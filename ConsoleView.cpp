/* 
 * File:   ConsoleView.cpp
 * Author: Riccardo Maffei
 * Author: Danilo Branca
 * 
 * Created on 21 dicembre 2015, 1.52
 */

#include "ConsoleView.hpp"
#include "StringUtils.hpp"

ConsoleView::ConsoleView() {
}

ConsoleView::~ConsoleView() {
}

void ConsoleView::getUsername(char dest[]) {
    //print the prompt
    cout << "Prisoner! What's your name?\n";
    //get the destination
    cin >> dest;
}

void ConsoleView::showSplash() {
    //print the title
    cout << "MMMMMMMMMMM                              dP                    " << "MMMMMMMMMM          dP                 dP         " << endl; 
    cout << "MM        M                              dP                    " << "MMb    dMM        d8888P       OO      dP         " << endl; 
    cout << "MM  MMMMMMM                              88                    " << "M' .MM. 'M          88                 88         " << endl; 
    cout << "MM      MMM 88d88b. .d888b. .d888b. .d88b88 .d888b. 88d8b.d8b. " << "M  MMMM  M dP   dP  88 .d888b. dP .d88b88 .d888b. " << endl;
    cout << "MM  MMMMMMM 88' `88 88oood8 88oood8 88' `88 88' `88 88'`88'`88 " << "M  MMMM  M 88   88  88 Y8oooo. 88 88' `88 88oood8 " << endl; 
    cout << "MM  MMMMMMM 88      88. ... 88. ... 88. .88 88. .88 88  88  88 " << "M. `MM' .M 88. .88  88      88 88 88. .88 88. ... " << endl;
    cout << "MM  MMMMMMM dP      `8888P' `8888P' `8888P8 `8888P' dP  dP  dP " << "MMb    dMM `8888P'  dP `8888P' dP `8888P8 `8888P' " << endl; 
    cout << "MMMMMMMMMMM                                                    " << "MMMMMMMMMM                                        " << endl;
    //print an empty line
    cout << endl;
    //print the logo with colophon
    cout << "M.   +:   +/    s:    s:   o:   +/    s:   /M" << endl;
    cout << "M.   +:   +/   `hmmNdm-    o:   +/    s:   /M" << endl;
    cout << "M.   +:   +/  :mMMMMMMN`   o:   +/    s:   /M" << endl;
    cout << "M.   +:--/o/  dMMMMMMMM+   o:   +/    s/.--/M" << endl;
    cout << "M+:::ymMMmNo::dmMMMMMMMy::/yo:::so::::hdmMMhM" << endl;
    cout << "M-   +MMN`+/   `sMMMMMMMMMhd/```+/    s/.hM+M" << endl;
    cout << "M-   +MMm +/`:shNMMMMMMMMMMMMdhyds.`  s: hM/M" << endl;
    cout << "M:   +MMN smNMMMMMMMMMMMMMMMMMMMMMNds/hosMM/M" << endl;
    cout << "M:   +MMMhMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM/M" << "                       Riccardo Maffei" << endl;
    cout << "M:   +MMMMMMMMMMMMMMMMMMMMMMMMMmmddmMMMNNNM/M" << endl;
    cout << "M:   +::ddmy//NMMMMMMMMMMMMMMMM +/  `-:y.-`:M" << "                       Danilo Branca" << endl;
    cout << "M:   +: ``+/  /MMMMMMMMMMMMMMMM +/    s/   :M" << endl;
    cout << "M:   +:   +/   mMMMMMMMMMMMMMMM +/    s/   :M" << "                       Federico Bertani" << endl;
    cout << "M:   +:   +/   yMMMMMMMMMMMMMMMh+/    s/   :M" << endl;
    cout << "M:   +:   +/   /MMMMMMMMMMMMMMMm+/    s/   /M" << endl;
    cout << "M:   +:   +/   -MMMMMMMMMMMMMMMN+/    s@@@@@M" << endl;
    cout << "M:   +:   +/    dMMMMMMMMMMMMMMM+/    s@@@@@M" << endl;
    cout << "Mo:::yo:::yo:::/mMMMMMMMMMMMMMMMMs::::h@@@@@M" << endl;
    cout << "M-   +:   +/    mMMMMMMMMMMMMMMMM/    s/   /M" << "                       University Of Bologna" << endl;
    cout << "M-   +:   +/   .NMMMMMMMMMMMMMMMM/    s/   /M" << endl;
    cout << "M-   +-   +/   /MMMMMMMMMMMMMMMMM/    s/   /M" << endl;
    cout << "M-   +-   +/   yMMMMMMMMMMMMMMMMM/    s/   /M" << endl;
    cout << "M-   +-   +/  `NMMMMMMM NMMMMMMMM/    s/   /M" << endl;
    cout << "M.   +:   +/  :MMMMMMMM  MMMMMMMM/    s/   /M" << endl;
    //print an empty line
    cout << endl;
}

void ConsoleView::frameText(FedeList<char*>* list){
    //variable "max" inizialized to zero
    int max = 0;
    //loop that find the lenght of the longest string
    for (int i = 0; i < list -> getSize(); i++){
        int length = strlen(list -> get(i));
        //evaluating s lenght, comparing it to the lenght of the previus longest string
        if(length > max){
            max = length;
        }
    }
    //print the top of the frame, being beware of corners
    for(int i = 0; i < max+4; i++){
        //determinate if we need a top-left corner or not
        if(i==0){
            cout << "╔";
        }
        //determinate if we need a top-right corner or not
        else if(i==max+3){
            cout << "╗";             
        }
        //determinate if we need a top border or not
        else{
            cout << "═";            
        }  
    }
    cout << endl;   
    //print the content of the frame, beetween two "║"
    for(int i = 0; i < list -> getSize(); i++){
        //print a piece of left-side border and the description
        cout << "║ " << list -> get(i);
        //determinate if an addictional blank space is needed to adjust the frame's right-side border
        for(int n_spazi = strlen(list -> get(i)); n_spazi < max; n_spazi++){
            cout << " ";
        }
        //print a piece of right-side border
        cout << " ║";
        cout << endl;
    }
    //print the bottom of the frame, being beware of corners
    for(int i = 0; i < max+4; i++){
        //determinate if we need a bottom-left corner or not
        if(i==0){
            cout << "╚";
        }
        //determinate if we need a bottom-right corner or not
        else if(i==max+3){
            cout << "╝";             
        }
        //determinate if we need a bottom border or not
        else{
            cout << "═";            
        }
    }
    cout << endl;
}
/**
 * Show the game intro/prologue.
 */
void ConsoleView::showPrologue(){
    
}

Action* ConsoleView::selectAction(FedeList<Action*>* actions) {
    //the prompt
    char* prompt = new char[60];
    //copy the prompt
    strcpy(prompt, "Hey prisoner! What's your next move? (write the number)");
    //the list of description
    FedeList<char*>* list = new FedeList<char*>(prompt);
    //for the list
    for(int i = 0; i < actions -> getSize(); i++){
        //a string buffer
        char* buffer = new char[512];
        //save the number in buffer
        itoa(i, buffer);
        //concat a dot and a space
        strcat(buffer, ". ");
        //the description
        char descr[256];
        //get the description
        actions -> get(i) -> getDescription(descr);
        //concat the description
        strcat(buffer, descr);
        //add to the list
        list -> push_back(buffer);
    }
    //print framed
    frameText(list);
    //fro all strings in list
    for(int i = 0; i < list -> getSize(); i++){
        //delete the string
        delete[](list -> get(i));
    }
    //delete the list
    delete list;
    //int selection
    int selection = 0;
    //get the selected value
    cin >> selection;
    //if selection is greater thal listsize-1
    if (selection > (actions -> getSize() - 1)){
        //set as the last
        selection = actions -> getSize() - 1;
    }
    //return the actionn at th selected position
    return actions -> get(selection);
}

