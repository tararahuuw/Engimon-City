#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include "Battle.h"
#include "Skill.h"
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
int Battle::attack(Player& p,Engimon& e1,Engimon& e2,int& attempt) {
    SkillsFactory sf = SkillsFactory();
    float adv1 = advantage(e1,e2,1);
    float adv2 = advantage(e1,e2,2);
    float power1 = countPower(e1,adv1);
    float power2 = countPower(e2,adv2);
    cout << "Player Engimon attacks with a total power of " << power1 << endl;
    cout << "Wild Engimon attacks with a total power of " << power2 << endl;
    if(power1 >= power2) {
        cout << "Player Engimon wins" << endl;
        e1.addEXP(e2.getLevel()*5);
        int x = rand() % sf.getSkills().size();
        e2.setWild(false);
        int ele2 = e2.getElement().at(0);
        Skill s = Skill(sf[x]);
        while(count(s.getElement().begin(),s.getElement().end(),ele2) == 0) {
            x = (x + 1) % sf.getSkills().size();
            s = Skill(sf[x]);
        } 
        p.addSkillItemToInven(s);
        return 0;
    }
    else {
        cout << "Your Engimon is defeated" << endl;
        e1.setStatus(false);
        changeEngimon(p,attempt);
        return 1;
    }

}
void Battle::startBattle(Player& P,Engimon& enemy) {
    int ongoing = 1;
    int attempt = 1;
    while(ongoing == 1) {
        string answer;
        cout << "Enemy : " << enemy.getSpecies() << endl;
        cout << "Element : ";
        vector<Element> element = enemy.getElement();
        for (auto i = element.begin(); i != element.end(); ++i) {
            cout << EleName[*i] << endl;
        } 
        cout << "Level : " << enemy.getLevel() << endl;

        cout << "What will you do?" << endl;
        cout << "- attack" << endl;
        cout << "- change active engimon" << endl;
        cout << "- run" << endl;
        cout << "Choose a command : ";
        cin >> answer;
        if(answer == "attack") {
            ongoing = attack(P,P.getActiveEngimon(),enemy,attempt);
        }
        else if(answer == "change active engimon") {
            changeEngimon(P,attempt);

        }
        else if(answer == "run") {
            ongoing = run(attempt);
        }
 
    }

}
int Battle::run(int& attempt) {
    int x = rand() % 2 + 1;
    if(attempt > 0) {
        attempt = attempt - 1;
        if(x == 1) {
            cout << "You failed to run" << endl;
            return 1;
        }
        else {
            cout << "You successfully fled" << endl;
            return 0;
        }
    }
    else {
        cout << "You may only attempt to run once until your active engimon is defeated." << endl;
        return 1;
    }
    
}
void Battle::gameOver() {
    cout << "All of your Engimon are defeated." << endl;
    cout << "GAME OVER" << endl;
}
void Battle::changeEngimon(Player& P,int& attempt) {
    if(P.getListEng().getSize() >= 1) {
        int found = 0;
        while(found == 0) {
            int x,y;
            if(P.getActiveEngimon().getStatus() == false) {
                attempt = 1;
            }
            cout << "Please choose another Engimon to fight" << endl;
            P.getListEng().viewList();
            cout << "Input the index of the Engimon : ";
            cin >> x;
            y = x - 1;
            if(P.getListEng().getElementX(y).getStatus() == false) {
                cout << "This Engimon is already defeated" << endl;
            }
            else {
                cout << "You have successfully changed your active Engimon" << endl;
                P.activateEngimon(y);
                found = 1;
            }
        }
    }
    else {
        if(P.getActiveEngimon().getStatus() == false) {
            gameOver();
        }
        else {
            cout << "You don't have any other available Engimon" << endl;
        }
    }
}