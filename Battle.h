#ifndef BATTLE_H
#define BATTLE_H
#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include "Engimon.h"
#include "Player.h"
using namespace std;

class Battle {
    private:
    static float table[5][5];
    Engimon e1;
    Engimon e2;
    
    public:
    Battle();
    Battle(Engimon& e1, Engimon& e2);
    ~Battle();
    Engimon& getEngimon1();
    Engimon& getEngimon2();
    void fight();
};

#endif