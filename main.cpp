#include <bits/stdc++.h> //no need to include another c++ library
#include "Player.h"

//to do : bikin list command
//g++ main.cpp Player.cpp Engimon2.cpp Species.cpp peta.cpp Skill.cpp
int main(){
    int b,k;
    cout << "Enter map dimension :";
    cin >>b>>k;
    cout << "Enter map name :";
    string filename;
    cin >> filename;
    Peta peta(b,k);
	peta.BacaFile(filename);
	Player player1(make_pair(13,13), peta);
    player1.spawn();
    int round = 0;
    bool isLastCommandMove = false;
    bool isGameOver = false;
    string command;
    cin >> command;
    //nanti welcome message disini
    while (command != "exit" &&  !(isGameOver)){
        try{
            
            if (command == "d" or command == "D"){
                player1.moveD();
                isLastCommandMove = true;
                round++;
            }
            if (command == "w" or command == "W"){
                player1.moveW();
                isLastCommandMove = true;
                round++;
            }
            if (command == "s" or command == "S"){
                player1.moveS();
                isLastCommandMove = true;
                round++;
            }
            if (command == "a" or command == "A"){
                player1.moveA();
                isLastCommandMove = true;
                round++;
            }
            if (command == "map"){
                player1.lihatPeta();
            }
            if (command == "viewEng"){
                player1.viewListEngimon();
            }

            if (command == "viewItems"){
                player1.viewListSkill();
            }

            if (command == "viewInventory"){
                player1.viewListEngimon();
                player1.viewListSkill();
            }
            if (command == "activate"){
                player1.viewListEngimon();
                int idx;
                cout << "Choose engimon (use number) :";
                cin >> idx;
                player1.activateEngimon(idx-1);
            }
            if(command == "status") {
                if (player1.isThereActiveEngimonYet()) cout << "status : " << player1.getActiveEngimon().getStatus() << endl;
                else throw ActiveEngimonKosong();
            }

            if (command =="detailEng"){
                player1.viewListEngimon();
                int idx;
                cout << "Choose engimon (use number) :";
                cin >> idx;
                player1.getListEng().getElementX(idx-1).printDetail();
            }

            if (command == "detailItem"){
                player1.viewListSkill();
                int idx;
                cout << "Choose engimon (use number) :";
                cin >> idx;
                player1.getListSkill().getSkillX(idx-1).printDetail();
                cout << endl;
            }

            if (command == "learn"){
                int idx;
                player1.getListSkill().viewList();
                cout << "Choose skill item (use number) :";
                cin >> idx;
                player1.learnSkill(idx-1);
                round++;
            }
            if (command == "battle"){
                player1.initBattle();
                round++;
            }

            if (command == "breeding"){
                if (player1.getListEng().getSize() < 2){
                    throw NotEnoughEngiBreed();
                }else{
                    player1.viewListEngimon();
                    int idx1,idx2;
                    cout << "Choose 2 engimons (use number) :";
                    cin >> idx1 >> idx2;
                    player1.breeding(idx1-1,idx2-1);
                }
                round++;
            }


            if (command == "deactivate"){
                player1.deactivateEngimon();
            }
            //jika mencapai round dengan kriteria tertentu, random spawn dan/atau random gerak
            if (round%15 == 0){
                player1.spawn();
            }
            if (round%10 == 0){
                player1.randomMove();
            }
            
            if (player1.isThereActiveEngimonYet() and isLastCommandMove ){
                try{
                    player1.moveAE(command);
                }catch (exception& e){
                    cout << e.what() <<endl;
                    //relocating
                    player1.relocateAE();
                    cout << "Relocating to " << player1.getYCoorAE() << "," << player1.getXCoorAE() <<endl;
                }
            }
            isGameOver = player1.isGameOver();
            if (isGameOver){
                cout << "All of your Engimon are defeated." << endl;
                cout << "GAME OVER" << endl;
            }
        }catch (exception& e){
            cout << e.what() << endl;
        }catch (...){
            //do nothing;
        }
        isLastCommandMove = false;
        cin >> command;       
    }

    //goodbye
}