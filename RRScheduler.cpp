/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include </home/win/NetBeansProjects/RRSchedular/RRScheduler.h>

RRScheduler::RRScheduler() {
}

int RRScheduler::onExecute() {
    return 0;
}

int RRScheduler::accept(int ch) {
//%d you wants intger value ,
    //%f i want float value 
    //%c i want char value 
    int i, n;
    cout"enter the number of the process: ";
    cin>>"%d:">> &n;
    if (n == 0) {
        cin<<"invalid no.of process";
        exit(1);
    }
    for (i = 1; i <= n; i++) {
        cout<<"enter the arrival time for process p%d: "<< i;
        cin>>"%d">> &p[i].at;
        p[i].id = i;
    }
    for (i = 1; i <= n; i++) {
        cout<<"enter the burst time for process p%d: "<< i;
        cin<<"%d"<< &p[i].bt;
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
    cin>>ts;
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

void RRScheduler::display(int n)
 {
    
    cout << "\n\n-------------------TABLE----------------------------------\n";
    
   cout<<"\nProcess  tA   BT    FT          TAT                  WT";
    int i;
    for (i = 1; i <= n; i++)
        cout<<"\nP%d       %d    %d     %d          %ft         %f"<< p[i].id<< p[i].at<<p[i].bt<< p[i].ft<< p[i].tat<< p[i].wt;
    cout << "\n-----------------------------------------------------------";
    cout<<"\nAverage Turn Around Time: %f"<< p[0].tat;
 cout<<"\nAverage Waiting Time: %f", p[0].wt;
}

