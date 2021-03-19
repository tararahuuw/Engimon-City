#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include "Battle.h"
using namespace std;



float Battle::advantage(Engimon& e1,Engimon& e2,int n) {
    int x = 0;
    int y = 0;
    for (auto i = e1.getElement().begin(); i != e1.getElement().end(); ++i) {
        for (auto j = e2.getElement().begin(); i != e2.getElement().end(); ++i) {
            if(table[*i][*j] > x) {
                x = table[*i][*j];
            }
            if(table[*j][*i] > y) {
                y = table[*j][*i];
            }
        }
    }
    if(n == 1) {
        return x;
    }
    else if(n == 2) {
        return y;
    }
}
float Battle::countPower(Engimon& e,float adv) {
    float total = e.getLevel() * adv;
    vector<Skill> skill = e.getSkills();
    for (auto i = skill.begin(); i != skill.end(); ++i) {
        total = total + (i->getBasePower() * i->getMasteryLevel());
    }
    return total;

}
void Battle::attack(Player& p,Engimon& e1,Engimon& e2) {
    float adv1 = advantage(e1,e2,1);
    float adv2 = advantage(e1,e2,2);
    float power1 = countPower(e1,adv1);
    float power2 = countPower(e2,adv2);
    if(power1 >= power2) {
        int x = rand() % 10 + 1;
        // e2.setWild(false);
        e1.addEXP(e2.getLevel()*5);
        // p.addItem(x)
        
        
    }
    else {
        e1.setStatus(false);
    }

}