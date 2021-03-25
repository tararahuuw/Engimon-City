#include <bits/stdc++.h> //no need to include another c++ library
#include "Player.h"

//to do : bikin list command

int main(){
    Peta peta(14,14);
	peta.BacaFile();
	Player player1(make_pair(13,13), peta);
    int round = 0;
    bool isLastCommandMove = false;
    string command;
    cin >> command;
    //nanti welcome message disini
    while (command != "exit"){
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
            if (command == "peta"){
                player1.lihatPeta();
            }

            if (command == "activate"){
                int idx;
                cout << "Masukkan nomor engimon yang ingin digunakan :";
                cin >> idx;
                player1.activateEngimon(idx-1);
            }
            if (command == "learn"){
                int idx;
                cout << "Masukkan nomor skill item yang ingin digunakan :";
                cin >> idx;
                player1.learnSkill(idx-1);
            }


            //jika mencapai round dengan kriteria tertentu, random spawn dan/atau random gerak
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