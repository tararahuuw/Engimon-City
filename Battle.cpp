#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include "Battle.h"
using namespace std;

float Battle::table[5][5] = {{1,0,1,0.5,2},{2,1,0,1,1},{1,2,1,0,1.5},{1.5,1,2,1,0},{0,1,0.5,2,1}};


Battle::Battle(Engimon& e1,Engimon& e2) {
    this->e1 = e1;
    this->e2 = e2;
}
Battle::~Battle() {
    this->e1.~Engimon();
    this->e2.~Engimon();
}
Engimon& Battle::getEngimon1() {
    return this->e1;
}
Engimon& Battle::getEngimon2() {
    return this->e2;
}
void Battle::fight() {
    float multiplier1 = 0;
    float multiplier2 = 0;
    
    for (auto i = this->e1.getElement().begin(); i != this->e1.getElement().end(); ++i) {
        for (auto j = this->e2.getElement().begin(); i != this->e2.getElement().end(); ++i) {
            if(table[*i][*j] > multiplier1) {
                multiplier1 = table[*i][*j];
            }
            if(table[*j][*i] > multiplier2) {
                multiplier2 = table[*j][*i];
            }
        }
    }
        
}