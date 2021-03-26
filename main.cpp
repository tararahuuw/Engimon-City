#include <bits/stdc++.h> //no need to include another c++ library
#include "Player.h"

void printCommandList();

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
	bool berhasil = peta.BacaFile(filename);
    if( !berhasil) exit(1);
	Player player1(make_pair(13,13), peta);
    player1.spawn();
    int round = 0;
    player1.drawing(-1);
    printCommandList();
    bool isLastCommandMove = false;
    bool isGameOver = false;
    string command;
    cout << "Enter your command : ";
    cin >>command;
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
                player1.drawing(13+4);
                player1.viewListEngimon();
            }

            if (command == "viewItem"){
                player1.drawing(13+4);
                player1.viewListSkill();
            }

            if (command == "viewInventory"){
                player1.drawing(13+4);
                player1.viewListEngimon();
                player1.viewListSkill();
            }

            if (command == "interact"){
                player1.interact();
            }

            if (command == "activate"){
                player1.drawing(13+4);
                player1.viewListEngimon();
                int idx;
                cout << "Choose engimon (use number) :";
                cin >> idx;
                player1.activateEngimon(idx-1);
                player1.drawing(player1.getActiveEngimon().getSpeciesIndex());
            }
            // if(command == "status") {
            //     if (player1.isThereActiveEngimonYet()) cout << "status : " << player1.getActiveEngimon().getStatus() << endl;
            //     else throw ActiveEngimonKosong();
            // }
            
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
                cout << "Choose skill item (use number) :";
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
                    if (player1.getListEng().getElementX(idx1-1).getLevel() >= 30 and player1.getListEng().getElementX(idx2-1).getLevel() >= 30){

                    }else throw NotEnoughLevel();
                    player1.drawing(16);
                    player1.breeding(idx1-1,idx2-1);
                }
                round++;
            }


            // if (command == "deactivate"){
            //     player1.deactivateEngimon();
            // }

            if (command == "help"){
                printCommandList();
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
        if (!isGameOver) cout << "Enter your command : ";
        cin >>command;       
    }

    //goodbye
}

void printCommandList(){
    cout << "List command that you can use:\n" << endl;
    cout << "exit           \t- To exit the game" << endl;
    cout << "\"w\" or \"W\"\t- Move up" << endl;
    cout << "\"a\" or \"A\"\t- Move left" << endl;
    cout << "\"s\" or \"S\"\t- Move down" << endl;
    cout << "\"d\" or \"D\"\t- Move right" << endl;
    cout << "map            \t- To view map" << endl;
    cout << "viewEng        \t- To view Engimon Inventory" << endl;
    cout << "viewItem       \t- To view Skill Item Inventory" << endl;
    cout << "viewInventory  \t- To view all inventory" << endl;
    cout << "interact       \t- To interact with active Engimon" << endl;
    cout << "activate       \t- To activate Engimon" <<endl;
    // cout << "deactivate     \t- To deactivate Engimon" << endl;
    cout << "detailEng      \t- To view details of one specific Engimon" << endl;
    cout << "detailItem     \t- To view details of one specific Skill Item" << endl;
    cout << "learn          \t- To learn Skill Item in Active Engimon" << endl;
    cout << "battle         \t- To battle adjacent Wild Engimon" << endl;
    cout << "breeding       \t- To breed 2 Engimons" << endl;
    cout << "help           \t- View this list" <<endl;
}