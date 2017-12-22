/*
 * @Package RRScheduler (H)
 * @Version 1.0.0
 * @Author Amira M.M
 * @Licence GNU 2.0
 */

#ifndef _RRSCHEDULER_H_ 
#define _RRSCHEDULER_H_

#include<iostream>
#include<cstdlib>
#include<queue>
#include<cstdio>

using namespace std;

class RRScheduler {
public:
    RRScheduler();

    int execute();

    int accept(int ch);
    void turnwait(int n);
    void display(int n);
    void ganttrr(int n);
};

#endif
