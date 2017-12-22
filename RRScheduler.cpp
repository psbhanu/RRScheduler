/*
 * @Package RRScheduler (CPP)
 * @Version 1.0.0
 * @Author Amira M.M
 * @Licence GNU 2.0
 */

#include<iostream>
#include<cstdlib>
#include<queue>
#include<cstdio> 

#include <string>
#include <iomanip>

#include "RRScheduler.h"

using namespace std;
typedef struct process {
    int ProcessID, ArrivalTime, BurstTime, StratTime, FinishTime, Priority;
    float WaitTime, TurnArroundTime;
} process;

process Process[10], p1[10], temp;
queue<int> queue1;

RRScheduler::RRScheduler() {
    Process[0].TurnArroundTime = 0;
    Process[0].WaitTime = 0;
}

int RRScheduler::execute() {
    int i, n, ts, ch, j, x;

    n = accept(ch);
    ganttrr(n);
    turnwait(n);
    display(n);
    return 0;
}

int RRScheduler::accept(int ch) //functions for accepting inputs from the user
{
    int i, n;
    cout << "\nEnter the no. of process: ";
    scanf("%d", &n);
    if (n == 0) {
        cout << "\nInvalid no. of process";
        exit(1);
    }
    for (i = 1; i <= n; i++) {
        printf("\nEnter the arrival time for process P%d: ", i);
        scanf("%d", &Process[i].ArrivalTime);
        Process[i].ProcessID = i;
    }
    for (i = 1; i <= n; i++) {
        printf("\nEnter the burst time for process P%d: ", i);
        scanf("%d", &Process[i].BurstTime);
    }
    if (ch == 3) {
        for (i = 1; i <= n; i++) {
            printf("\nEnter the priority for P%d: ", i);
            scanf("%d", &Process[i].Priority);
        }
        return n;
    }

    printf("\nInputs given by the user are:\n");

    printf("==============================================================");
    printf("\nProcess\tAT\tBT");
    for (i = 1; i <= n; i++)
        printf("\nP%d\t%d\t%d", Process[i].ProcessID, Process[i].ArrivalTime, Process[i].BurstTime);

    printf("\n============================================================");
    for (i = 1; i <= n; i++) // copying of one array into another array(dummy area)
        p1[i] = Process[i];
    return n;
}

/* FUNCTION FOR DISPLAYING GANTT CHART FOR ROUND ROBIN SCHEDULING */
void RRScheduler::ganttrr(int n) {
    int i, ts, m, nextval, nextarr;
    nextval = Process[1].ArrivalTime;
    cout << "\nEnter time slice: ";
    cin>>ts;

    nextval = p1[1].ArrivalTime;
    printf("\n\nGantt chart is as follows\n\n");
    cout << p1[1].ArrivalTime;

    for (i = 1; i <= n, p1[i].ArrivalTime <= nextval; i++)
        queue1.push(p1[i].ProcessID);
    nextarr = p1[i].ArrivalTime;
    while (!queue1.empty()) {
        m = queue1.front();
        queue1.pop();
        if (p1[m].BurstTime >= ts)
            nextval = nextval + ts;
        else
            nextval = nextval + p1[m].BurstTime;
        cout << "->P" << p1[m].ProcessID << "->" << nextval;
        p1[m].BurstTime = p1[m].BurstTime - ts;
        if (nextval < nextarr) {
            if (p1[m].BurstTime > 0)
                queue1.push(m);
            if (p1[m].BurstTime <= 0)
                Process[m].FinishTime = nextval;
        } else {
            while (i <= n && p1[i].ArrivalTime <= nextval) {
                queue1.push(p1[i].ProcessID);
                i++;
            }
            if (i <= n)
                nextarr = p1[i].ArrivalTime;
            if (p1[m].BurstTime > 0)
                queue1.push(m);
            if (p1[m].BurstTime <= 0)
                Process[m].FinishTime = nextval;
        }
    }
}

/* FUNCTION FOR CALCULATING TURN AROUND TIME OR WAIT TIME */
void RRScheduler::turnwait(int n) {
    int i;
    for (i = 1; i <= n; i++) {
        Process[i].TurnArroundTime = Process[i].FinishTime - Process[i].ArrivalTime;
        Process[i].WaitTime = Process[i].TurnArroundTime - Process[i].BurstTime;
        Process[0].TurnArroundTime = Process[0].TurnArroundTime + Process[i].TurnArroundTime;
        Process[0].WaitTime = Process[0].WaitTime + Process[i].WaitTime;
    }
    Process[0].TurnArroundTime = Process[0].TurnArroundTime / n;
    Process[0].WaitTime = Process[0].WaitTime / n;
}

/* FUNCTION FOR DISPLAYING THE TABLE */
void RRScheduler::display(int n) {
    int i;
    cout << "\n\n-------------------TABLE----------------------------------\n";
    printf("\nProcess\tAT\tBT\tFT\tTAT\t\tWT");
    for (i = 1; i <= n; i++)
        printf("\nP%d\t%d\t%d\t%d\t%f\t%f", Process[i].ProcessID, Process[i].ArrivalTime, Process[i].BurstTime, Process[i].FinishTime, Process[i].TurnArroundTime, Process[i].WaitTime);
    cout << "\n\n-----------------------------------------------------------";
    printf("\nAverage Turn Around Time: %f", Process[0].TurnArroundTime);
    printf("\nAverage Waiting Time: %f\n", Process[0].WaitTime);
}
