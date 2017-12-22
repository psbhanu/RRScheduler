/*
 * @Package RRScheduler
 * @Version 1.0.0
 * @Author Amira M.M
 * @Licence GNU 2.0
 */

#ifndef _RRSCHEDULER_H_ 
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
    
    static int execute();
    static int accept(int ch);
    static void turnwait(int n);
    static void display(int n);
    static void ganttrr(int n);
};

#endif




