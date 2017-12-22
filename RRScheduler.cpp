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
    this->p[0].tat = 0;
    this->p[0].wt = 0;
    n = this->accept(ch);
    this->ganttrr(n);
    this->turnwait(n);
    this->display(n);
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
        cin >> this->p[i].at;
        this->p[i].id = i;
    }
    for (i = 1; i <= n; i++) {
        cout << "enter the burst time for process p: " << i;
        cin >> this->p[i].bt;
    }
    for (i = 1; i <= n; i++) {
        this->p1[i] = this->p[i];
        return n;
    }
}

void RRScheduler::ganttrr(int n) {
    int i, ts, m, nextval, nextarr;
    nextval = this->p1[1].at;
    i = 1;
    cout << "enter time slice: ";
    cin >> ts;
    for (i = 1; i <= n && this->p1[i].at <= nextval; i++)
        this->q1[.push(this->p1[i].id);

    while (!this->q1[.empty()) {
        m = this->q1[.front();
        this->q1[.pop();

        if (this->p1[m].bt >= ts)
            nextval = nextval + ts;
        else
            nextval = nextval + this->p1[m].bt;
        if (this->p1[m].bt >= ts)
            this->p1[m].bt = this->p1[m].bt - ts;
        else
            this->p1[m].bt = 0;
        while (i <= n && this->p1[i].at <= nextval) {
            this->q1[.push(this->p1[i].id);
            i++;
        }

        if (this->p1[m].bt > 0)
            this->q1[.push(m);
        if (this->p1[m].bt <= 0)
            this->p[m].ft = nextval;
    }

}

void RRScheduler::turnwait(int n) {

    int i;
    for (i = 1; i <= n; i++) {
        this->p[i].tat = this->p[i].ft - this->p[i].at;
        this->p[i].wt = this->p[i].tat - this->p[i].bt;
        this->p[0].tat = this->p[0].tat + this->p[i].tat;
        this->p[0].wt = this->p[0].wt + this->p[i].wt;
    }

    this->p[0].tat = this->p[0].tat / n;
    this->p[0].wt = this->p[0].wt / n;
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
  printf("\nP%d\t%d\t%d\t%d\t%f\t%f", this->p[i].id, this->p[i].at, this->p[i].bt, this->p[i].ft, this->p[i].tat, this->p[i].wt);
 cout<<"\n\n-----------------------------------------------------------";
 printf("\nAverage Turn Around Time: %f", this->p[0].tat);
 printf("\nAverage Waiting Time: %f\n", this->p[0].wt);
}
