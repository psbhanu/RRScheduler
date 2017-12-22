/*
 * @Package RRScheduler
 * @Version 1.0.0
 * @Author Amira M.M
 * @Licence GNU 2.0
 */

#ifndef _RRSCHEDULER_H_ //it's 
#define _RRSCHEDULER_H_
#include<iostream>
#include <cstdlib>
#include <queue>
#include <cstdio>
using namespace std;

typedef struct process {
    int id, at, bt, st, ft, pr;
    float wt, tat;
    
}process;

class RRScheduler {
    public: 
    RRScheduler();
    
    static process p[10], p1[10], temp;
    static queue<int> q1;
    
    int execute();
    int accept(int ch);
    void turnwait(int n);
    void display(int n);
    void ganttrr(int n);

};
#endif /* RRSCHEDULER_H */




