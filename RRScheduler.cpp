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
    n = RRScheduler::accept(ch);
    RRScheduler::ganttrr(n);
    RRScheduler::turnwait(n);
    RRScheduler::display(n);
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
        cin >> RRScheduler::p[i].at;
        RRScheduler::p[i].id = i;
    }
    for (i = 1; i <= n; i++) {
        cout << "enter the burst time for process p: " << i;
        cin >> RRScheduler::p[i].bt;
    }
    for (i = 1; i <= n; i++) {
        RRScheduler::p1[i] = RRScheduler::p[i];
        return n;
    }
}

void RRScheduler::ganttrr(int n) {
    int i, ts, m, nextval, nextarr;
    nextval = RRScheduler::p1[1].at;
    i = 1;
    cout << "enter time slice: ";
    cin >> ts;
    for (i = 1; i <= n && RRScheduler::p1[i].at <= nextval; i++)
        RRScheduler::q1.push(RRScheduler::p1[i].id);

    while (!RRScheduler::q1.empty()) {
        m = RRScheduler::q1.front();
        RRScheduler::q1.pop();

        if (RRScheduler::p1[m].bt >= ts)
            nextval = nextval + ts;
        else
            nextval = nextval + RRScheduler::p1[m].bt;
        if (RRScheduler::p1[m].bt >= ts)
            RRScheduler::p1[m].bt = RRScheduler::p1[m].bt - ts;
        else
            RRScheduler::p1[m].bt = 0;
        while (i <= n && RRScheduler::p1[i].at <= nextval) {
            RRScheduler::q1.push(RRScheduler::p1[i].id);
            i++;
        }

        if (RRScheduler::p1[m].bt > 0)
            RRScheduler::q1.push(m);
        if (RRScheduler::p1[m].bt <= 0)
            RRScheduler::p[m].ft = nextval;
    }

}

void RRScheduler::turnwait(int n) {

    int i;
    for (i = 1; i <= n; i++) {
        RRScheduler::p[i].tat = RRScheduler::p[i].ft - RRScheduler::p[i].at;
        RRScheduler::p[i].wt = RRScheduler::p[i].tat - RRScheduler::p[i].bt;
        RRScheduler::p[0].tat = RRScheduler::p[0].tat + RRScheduler::p[i].tat;
        RRScheduler::p[0].wt = RRScheduler::p[0].wt + RRScheduler::p[i].wt;
    }

    RRScheduler::p[0].tat = RRScheduler::p[0].tat / n;
    RRScheduler::p[0].wt = RRScheduler::p[0].wt / n;
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
  printf("\nP%d\t%d\t%d\t%d\t%f\t%f", RRScheduler::p[i].id, RRScheduler::p[i].at, RRScheduler::p[i].bt, RRScheduler::p[i].ft, RRScheduler::p[i].tat, RRScheduler::p[i].wt);
 cout<<"\n\n-----------------------------------------------------------";
 printf("\nAverage Turn Around Time: %f", RRScheduler::p[0].tat);
 printf("\nAverage Waiting Time: %f\n", RRScheduler::p[0].wt);
}


