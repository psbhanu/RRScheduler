/*
 * @Package RRScheduler
 * @Version 1.0.0
 * @Author Amira M.M
 * @Licence GNU 2.0
 */

#include <string>
#include <iomanip>
#include </home/win/NetBeansProjects/RRSchedular/RRScheduler.h>

RRScheduler::RRScheduler() {
}

int RRScheduler::execute() {
    int i, n, ts, ch, j, x;
    RRScheduler::p[0].tat = 0;
    RRScheduler::p[0].wt = 0;
    n = accept(ch);
    ganttrr(n);
    turnwait(n);
    display(n);
    return 0;
}

int RRScheduler::accept(int ch) {
//%d you wants intger value ,
    //%f i want float value 
    //%c i want char value 
    int i, n;
    cout << "enter the number of the process: ";
    cin >> n;
    if (n == 0) {
        cout << "invalid no.of process";
        exit(1);
    }
    for (i = 1; i <= n; i++) {
        cout << "enter the arrival time for process p: " << i;
        cin >> p[i].at;
        p[i].id = i;
    }
    for (i = 1; i <= n; i++) {
        cout << "enter the burst time for process p: " << i;
        cin >> p[i].bt;
    }
    for (i = 1; i <= n; i++) {
        p1[i] = p[i];
        return n;
    }
}

void RRScheduler::ganttrr(int n) {
    int i, ts, m, nextval, nextarr;
    nextval = p1[1].at;
    i = 1;
    cout << "enter time slice: ";
    cin >> ts;
    for (i = 1; i <= n && p1[i].at <= nextval; i++)

        q1.push(p1[i].id);

    while (!q1.empty()) {
        m = q1.front();
        q1.pop();

        if (p1[m].bt >= ts)
            nextval = nextval + ts;
        else
            nextval = nextval + p1[m].bt;
        if (p1[m].bt >= ts)
            p1[m].bt = p1[m].bt - ts;
        else
            p1[m].bt = 0;
        while (i <= n && p1[i].at <= nextval) {
            q1.push(p1[i].id);
            i++;
        }

        if (p1[m].bt > 0)
            q1.push(m);
        if (p1[m].bt <= 0)
            p[m].ft = nextval;
    }

}

void RRScheduler::turnwait(int n) {

    int i;
    for (i = 1; i <= n; i++) {
        p[i].tat = p[i].ft - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
        p[0].tat = p[0].tat + p[i].tat;
        p[0].wt = p[0].wt + p[i].wt;
    }

    p[0].tat = p[0].tat / n;
    p[0].wt = p[0].wt / n;
}
/*
void RRScheduler::display(int n)
 {
    string tab = "";
    cout << "\n\n-------------------TABLE----------------------------------\n";
    cout << std::setw(10) << "\nProcess" << std::setw(5) << "AT" << std::setw(10) << "BT" << std::setw(10) << "FT" << std::setw(10) << "TAT" << std::setw(10) << "WT";
    
    int i;
    for (i = 1; i <= n; i++)
        cout << std::setw(10) << "\nP"<< (int) p[i].id << std::setw(10) << (int) p[i].at << std::setw(10) << (int) p[i].bt << std::setw(10) << (int) p[i].ft << std::setw(10) << (float) p[i].tat << "t" << std::setw(10) << (float) p[i].wt << "t";
    
    cout << "\n-----------------------------------------------------------";
    
    cout << "\nAverage Turn Around Time: " << p[0].tat;
    cout << "\nAverage Waiting Time: " << p[0].wt;
}
*/
void RRScheduler::display(int n)
{
 int i; 
 cout<<"\n\n-------------------TABLE----------------------------------\n";
 printf("\nProcess\tAT\tBT\tFT\tTAT\t\tWT");
 for(i=1;i<=n;i++)
  printf("\nP%d\t%d\t%d\t%d\t%f\t%f",p[i].id,p[i].at,p[i].bt,p[i].ft,p[i].tat,p[i].wt);
 cout<<"\n\n-----------------------------------------------------------";
 printf("\nAverage Turn Around Time: %f",p[0].tat);
 printf("\nAverage Waiting Time: %f\n",p[0].wt);
}


