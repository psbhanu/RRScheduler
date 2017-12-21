/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: win
 *
 * Created on 19 December 2017, 12:02
 */

//RRScheduler.h



#include "RRScheduler.h"

using namespace std;


int main() {
    int i, n, ts, ch, j, x;
    RRScheduler scheduler;
    
    scheduler.p[0].tat = 0;
    scheduler.p[0].wt = 0;
    n =scheduler.accept(ch);
    scheduler.ganttrr(n);
    scheduler.turnwait(n);
     scheduler.display(n);
    
    return 0;
}

