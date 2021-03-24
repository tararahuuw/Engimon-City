#ifndef BATTLE_H
#define BATTLE_H
#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include "Engimon.h"
#include "Player.h"
using namespace std;


const float table[5][5] = {{1,0,1,0.5,2},{2,1,0,1,1},{1,2,1,0,1.5},{1.5,1,2,1,0},{0,1,0.5,2,1}};
const string EleName[5] = {"fire", "water", "electric", "ground", "ice"};

class Battle {
    
    public:
    // untuk mengetahui element advantage; n menandakan engimon mana yang ingin diketahui(n = 1 artinya engimon 1)
    static float advantage(Engimon& e1,Engimon& e2,int n);
    // inisiasi battle
    static int attack(Player& p,Engimon& e1,Engimon& e2,int& attempt);
    // menghitung power sebuah engimon
    static float countPower(Engimon& e,float adv);
    static void startBattle(Player& p,Engimon& e1);
    static int run(int& attempt);
    static void changeEngimon(Player& P,int& attempt);
    static void gameOver();
};

#endif