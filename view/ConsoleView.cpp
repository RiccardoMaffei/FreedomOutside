/* 
 * File:   ConsoleView.cpp
 * Author: Riccardo Maffei
 * Author: Danilo Branca
 * Author: Federico Bertani
 * 
 * Created on 21 dicembre 2015, 1.52
 */

#include <list>

#include "../view/ConsoleView.hpp"
#include "../model/StringUtils.hpp"
#include <limits>
#include <unistd.h>

ConsoleView::ConsoleView() {
}

ConsoleView::~ConsoleView() {
}

void ConsoleView::getUsername(char dest[],int playerNumber) {
    //calculate the prisoner number
    int prisonerNumber = Player::STARTING_PRISONER_NUMBER + playerNumber + 1;
    //print the prompt
    cout << "Prisoner " << prisonerNumber << "! What's your name?\n";
    //get the destination
    cin >> dest;
}

void ConsoleView::showSplash() {
    //print the title
    cout << "MMMMMMMMMMM                              dP                    " << "MMMMMMMMMM          dP                 dP         " << endl
         << "MM        M                              dP                    " << "MMb    dMM        d8888P       OO      dP         " << endl
         << "MM  MMMMMMM                              88                    " << "M' .MM. 'M          88                 88         " << endl
         << "MM      MMM 88d88b. .d888b. .d888b. .d88b88 .d888b. 88d8b.d8b. " << "M  MMMM  M dP   dP  88 .d888b. dP .d88b88 .d888b. " << endl
         << "MM  MMMMMMM 88' `88 88oood8 88oood8 88' `88 88' `88 88'`88'`88 " << "M  MMMM  M 88   88  88 Y8oooo. 88 88' `88 88oood8 " << endl 
         << "MM  MMMMMMM 88      88. ... 88. ... 88. .88 88. .88 88  88  88 " << "M. `MM' .M 88. .88  88      88 88 88. .88 88. ... " << endl
         << "MM  MMMMMMM dP      `8888P' `8888P' `8888P8 `8888P' dP  dP  dP " << "MMb    dMM `8888P'  dP `8888P' dP `8888P8 `8888P' " << endl
         << "MMMMMMMMMMM                                                    " << "MMMMMMMMMM                                        " << endl
    //print an empty line
      << endl
    //print the logo with colophon
      << "M.   +:   +/    s:    s:   o:   +/    s:   /M" << endl
      << "M.   +:   +/   `hmmNdm-    o:   +/    s:   /M" << endl
      << "M.   +:   +/  :mMMMMMMN`   o:   +/    s:   /M" << endl
      << "M.   +:--/o/  dMMMMMMMM+   o:   +/    s/.--/M" << endl
      << "M+:::ymMMmNo::dmMMMMMMMy::/yo:::so::::hdmMMhM" << endl
      << "M-   +MMN`+/   `sMMMMMMMMMhd/```+/    s/.hM+M" << endl
      << "M-   +MMm +/`:shNMMMMMMMMMMMMdhyds.`  s: hM/M" << endl
      << "M:   +MMN smNMMMMMMMMMMMMMMMMMMMMMNds/hosMM/M" << endl
      << "M:   +MMMhMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM/M" << "                       Riccardo Maffei" << endl
      << "M:   +MMMMMMMMMMMMMMMMMMMMMMMMMmmddmMMMNNNM/M" << endl
      << "M:   +::ddmy//NMMMMMMMMMMMMMMMM +/  `-:y.-`:M" << "                       Danilo Branca" << endl
      << "M:   +: ``+/  /MMMMMMMMMMMMMMMM +/    s/   :M" << endl
      << "M:   +:   +/   mMMMMMMMMMMMMMMM +/    s/   :M" << "                       Federico Bertani" << endl
      << "M:   +:   +/   yMMMMMMMMMMMMMMMh+/    s/   :M" << endl
      << "M:   +:   +/   /MMMMMMMMMMMMMMMm+/    s/   /M" << endl
      << "M:   +:   +/   -MMMMMMMMMMMMMMMN+/    s@@@@@M" << endl
      << "M:   +:   +/    dMMMMMMMMMMMMMMM+/    s@@@@@M" << endl
      << "Mo:::yo:::yo:::/mMMMMMMMMMMMMMMMMs::::h@@@@@M" << endl
      << "M-   +:   +/    mMMMMMMMMMMMMMMMM/    s/   /M" << "                       University Of Bologna" << endl
      << "M-   +:   +/   .NMMMMMMMMMMMMMMMM/    s/   /M" << endl
      << "M-   +-   +/   /MMMMMMMMMMMMMMMMM/    s/   /M" << endl
      << "M-   +-   +/   yMMMMMMMMMMMMMMMMM/    s/   /M" << endl
      << "M-   +-   +/  `NMMMMMMM NMMMMMMMM/    s/   /M" << endl
      << "M.   +:   +/  :MMMMMMMM  MMMMMMMM/    s/   /M" << endl
    //print two empty line
      << endl << endl;
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

void ConsoleView::slow_print(const char string[], int delay){
    //for the length of the string
    for (int i = 0; i < strlen(string); i++) { 
        //print the char at i and flush
        cout << string[i] << flush;
        //sleep for the given delay
        usleep(delay);
    }
}

void ConsoleView::showPrologue(int numberOfPlayer){
//    cout << "Democratic Kampuchea (Cambodia), 1977." << endl
//         << "Red Khmers have been in power for 2 years." << endl
//         << "The police have eyes everywhere and every careless action is considered against the party." << endl
//         << "Prisoners are detaind in the basement of Party's palace. " << endl
//         << "Not everyone knows that the palace was built on the old Khmer empire's prison" << endl
//         << "where there's an inhuman tradition: freedom will be given to the one who will survive to the other prisoners." << endl
//         << "Your captors have just pushed you in a damp cell with other " << (numberOfPlayer-1) << " unscrupulous prisoners who will try to kill you." << endl
//         << "You should run away and immediately find a weapon." << endl
//         << "Let the games begin!" << endl << endl;
    //the numer of player as string
    char nPlayer[20];
    //convert the number of player
    itoa((numberOfPlayer-1), nPlayer);
    //the prologue
    char prologue[1024] = "Democratic Kampuchea (Cambodia), 1977.\n"
                "Red Khmers have been in power for 2 years.\n"
                "The police has eyes everywhere and every careless action is considered against the party.\n"
                "Prisoners are detaind in the basement of Party's palace. \n"
                "Not everyone knows that the palace was built on the old Khmer empire's prison\n"
                "where there's an inhuman tradition: freedom will be given to the one who will survive to the other prisoners.\n"
                "Your captors have just pushed you in a damp cell with other ";
    //concat the number of player
    strcat(prologue, nPlayer);
    //concat the last part of the prologue
    strcat(prologue, " unscrupulous prisoners who will try to kill you.\n"
                        "You should run away and immediately find a weapon.\n"
                        "Let the games begin!\n\n");
    //print slowly
    slow_print(prologue, 70000);
}

Action* ConsoleView::selectAction(FedeList<Action*>* actions) {
    //the buffer where insert the promt
    char* prompt = new char[60];
    //copy the prompt in the buffer
    strcpy(prompt, "Hey prisoner! What's your next move? (write the number)");
    //the list of descriptions of actions
    FedeList<char*>* list = new FedeList<char*>(prompt);
    //for the list
    for(int i = 0; i < actions -> getSize(); i++){
        //a string buffer
        char* buffer = new char[512];
        //save the number in buffer
        itoa(i, buffer);
        //concat a dot and a space
        strcat(buffer, ". ");
        //the buffer for the description of the action
        char descr[256];
        //get the description of the action
        actions -> get(i) -> getDescription(descr);
        //concat the description
        strcat(buffer, descr);
        //add to the list
        list -> push_back(buffer);
    }
    //print framed
    frameText(list);
    //for all strings in list
    for(int i = 0; i < list -> getSize(); i++){
        //delete the string
        delete[](list -> get(i));
    }
    //delete the list
    delete list;
    //int selection
    int selection = 0;
    //get the selected value and if fails
    if (!(cin >> selection)) {
        //set as -1
        selection = -1;
    }
    //clear the cin error flag so the next inputs will work correctly
    cin.clear();
    //ignore all the others invalid character on the same line
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    //while the imput is invalid
    while(selection > (actions -> getSize() - 1) || selection < 0){
        //print an error
        cout << "You liar!! Choose your next move carefully!\n";
        //get the selected value and if fails
        if (!(cin >> selection)) {
            //set as -1
            selection = -1;
        }
        //clear the flag
        cin.clear();
        //ignore the buffer
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
    }
    //return the actionn at th selected position
    return actions -> get(selection);
}

void ConsoleView::showActionOutcome(Action* action) {
    //get the outcome list
    FedeList<char*>* messages = action->getOutcome();
    //show in frame
    frameText(messages);
    //wait a bit to let the user read
    usleep(strlen(messages -> get(0)) * 50000);
    //for the list
    for(int i = 0; i < messages -> getSize(); i++){
        //delete the string at i
        delete (messages -> get(i));
    }
    //delete the list itself
    delete messages;
}


void ConsoleView::showMap(Map* map, Player* player) {
    //the visibility radius
    int radius = 2;
    //get the room within the visibility radius
    FedeList<Room*>* visibleRooms = map -> getVisibleRooms(player -> getCurrentRoom(), radius);
    //the player X
    int playerX = player -> getCurrentRoom() -> getX();
    //the player Y
    int playerY = player -> getCurrentRoom() -> getY();
    //set the column cursor as the top left
    //int cCursor = playerX - radius;
    //set the column cursor as the top left + 3 to avoid printing spaces after the map
    int cCursor = playerX - radius + 3;
    //the old room Y
    int oldRoomY;
    //the list to be framed
    FedeList<char*>* listToFrame = new FedeList<char*>();
    //the zero line
    char* zeroLine = NULL;
    //the first line
    char* firstLine = NULL;
    //the second line
    char* secondLine = new char[512];
    //the third line
    char* thirdLine = NULL;
    //init the second line
    strcpy(secondLine, "");
    //for the radius
    for (int i = 0; i < radius; i++){
        //concat an empty space
        strcat(secondLine, "           ");
    }
    //concat a title
    strcat(secondLine, "    MAP    ");
    //for the radius
    for (int i = 0; i < radius; i++){
        //concat an empty space
        strcat(secondLine, "           ");
    }
    //if exist a room (should always exist)
    if(visibleRooms -> getSize() > 0){
        //set the old y as the first y minus 1
        oldRoomY = visibleRooms -> get(0) -> getY() - 1;
        //for the list
        for(int i = 0; i < visibleRooms -> getSize(); i++){
            //the current x
            int curRoomX = visibleRooms -> get(i) -> getX();
            //the current y
            int curRoomY = visibleRooms -> get(i) -> getY();
            //if the current room is under the old room
            if(curRoomY > oldRoomY){
                //if not null
                if (zeroLine != NULL) {
                    //push the zero line in the list to frame
                    listToFrame -> push_back(zeroLine);
                }
                //if not null
                if (firstLine != NULL) {
                    //push the first line in the list to frame
                    listToFrame -> push_back(firstLine);
                }
                //if not null
                if (secondLine != NULL) {
                    //push the second line in the list to frame
                    listToFrame -> push_back(secondLine);
                }
                //if not null
                if (thirdLine != NULL) {
                    //push the third line in the list to frame
                    listToFrame -> push_back(thirdLine);
                }
                //instance a new line
                zeroLine = new char[512];
                //clear the zero line
                strcpy(zeroLine, "");
                //instance a new line
                firstLine = new char[512];
                //clear the second line
                strcpy(firstLine, "");
                //instance a new line
                secondLine = new char[512];
                //clear the second line
                strcpy(secondLine, "");
                //instance a new line
                thirdLine = new char[512];
                //clear the third line
                strcpy(thirdLine, "");
                //reset the cursor
                cCursor = playerX - radius;
            }
            //while the cursor is not on the column to print
            while (cCursor < curRoomX){
                //concat an empty space
                strcat(zeroLine, "           ");
                //concat an empty space
                strcat(firstLine, "           ");
                //concat an empty space
                strcat(secondLine, "           ");
                //concat an empty space
                strcat(thirdLine, "           ");
                //increase the cursor
                cCursor++;
            }
            //the current x string
            char curSX[20];
            //the current y string
            char curSY[20];
            //convert the x
            itoa(curRoomX, curSX);
            //xonvert the y
            itoa(curRoomY, curSY);
            //concat the open bracket
            strcat(thirdLine, "|");
            //fill with spaces
            for(int i = 0; i < 4 - strlen(curSX) +1; i++){
                //concat a space
                strcat(secondLine, " ");
            }
            //concat the current x string
            strcat(secondLine, curSX);
            //concat a space
            strcat(secondLine, " ");
            //concat the current y string
            strcat(secondLine, curSY);
            //fill with spaces
            for(int i = 0; i < 4 - strlen(curSY) +1; i++){
                //concat a space
                strcat(secondLine, " ");
            }
            //if the player is here
            if(curRoomX == playerX && curRoomY == playerY){
                //concat a cross
                strcat(thirdLine, "___ X ___");
            }
            //otherwise
            else{
                //concat _ and spaces
                strcat(thirdLine, "___   ___");
            }
            //concat _ and spaces
            strcat(zeroLine, " ___   ___ ");
            //concat spaces
            strcat(firstLine, "|         |");
            //concat the close bracket
            strcat(thirdLine, "|");
            //increase the cursor
            cCursor++;
            //set the current as the old
            oldRoomY = curRoomY;
        }
        //push the zero line
        listToFrame -> push_back(zeroLine);
        //push the first line
        listToFrame -> push_back(firstLine);
        //push the second line
        listToFrame -> push_back(secondLine);
        //push the third line
        listToFrame -> push_back(thirdLine);
        //print framed
        frameText(listToFrame);
    }
    //for the list
    for(int i = 0; i < listToFrame -> getSize(); i++){
        //delete the string at i
        delete[] (listToFrame -> get(i));
    }
    //delete the list itself
    delete listToFrame;
    cout << endl;
    cout << "You are in [ " << playerX << " " << playerY << " ] (where there is the X)\nbut it's very dark and you can't see the cells more than "<<radius<<" steps away from you.\n";
    cout << endl;
    //delete the list
    delete visibleRooms;
}

void ConsoleView::showPlayerInfo(Player* player) {
    showPromptForTurn(player);
    //the list of texts to display
    FedeList<char*>* outputList = new FedeList<char*>();
    addPlayerStatsToOutput(outputList,player);
    addInventoryInfoToOutput(outputList,player);
    addEmptyLineToOutput(outputList);
    addArmorInfoToOutput(outputList,player);
    //print framed
    frameText(outputList);
    //fro all strings in list
    for(int i = 0; i < outputList -> getSize(); i++){
        //delete the string
        delete[](outputList -> get(i));
    }
    //delete the list
    delete outputList;
}

void ConsoleView::showShortInfo(FedeList<Player*>* players) {
    //the prompt
    char* prompt = new char[60];
    //if the list size is greater than 0
    if(players -> getSize() > 0){
        //copy the prompt
        strcpy(prompt, "There are some other prisoners here. Combat, run or die!");
    }
    //else (empty)
    else{
        //copy the prompt
        strcpy(prompt, "Don't be scared of being alone!");
    }
    //the list of description
    FedeList<char*>* list = new FedeList<char*>(prompt);
    //for the list
    for(int i = 0; i < players -> getSize(); i++){
        //the player
        Player* p = players -> get(i);
        //a string buffer
        char* buffer = new char[256];
        //concat the first part
        strcpy(buffer, "Prisoner #");
        //the number
        char number[10];
        //save the number in buffer
        itoa((Player::STARTING_PRISONER_NUMBER + p -> getId()), number);
        //concat the number
        strcat(buffer, number);
        //concat "("
        strcat(buffer, "(");
        //the name
        char name[50];
        //get the description
        p -> getUsername(name);
        //concat the name
        strcat(buffer, name);
        //concat "): health="
        strcat(buffer, "): health=");
        //the health
        char health[10];
        //save the number in buffer
        itoa(p -> getHealth(), health);
        //concat the number
        strcat(buffer, health);
        //add to the list
        list -> push_back(buffer);
    }
    //print framed
    frameText(list);
    //for all strings in list
    for(int i = 0; i < list -> getSize(); i++){
        //delete the string
        delete[](list -> get(i));
    }
    //delete the list
    delete list;
}

void ConsoleView::showPromptForTurn(Player* player) {
    //the buffer of the prompt
    char prompt[256];
    //concat the first part
    strcpy(prompt, "Prisoner #");
    //the buffer for the number of the prisoner
    char number[10];
    //add 15687 for fiction and trasform it to string
    itoa((15687 + player -> getId()), number);
    //concat the number of the prisoner
    strcat(prompt, number);
    //concat "("
    strcat(prompt, "(");
    //the buffer for the name of the prisoner
    char name[50];
    //get the description
    player -> getUsername(name);
    //concat the name
    strcat(prompt, name);
    //concat "):i'ts your turn"
    strcat(prompt, ") it's your turn!");
    //cout the prompt
    cout << prompt << endl;
}

void ConsoleView::addEmptyLineToOutput(FedeList<char*>* outputList) {
        //instance a new empy line
        char* emptyLine = new char[1];
        //copy the empty line
        strcpy(emptyLine, "");
        //push an empty line
        outputList -> push_back(emptyLine);
}

void ConsoleView::addPlayerStatsToOutput(FedeList<char*>* outputList,Player* player) {
    //get the health
    int health = player -> getHealth();
    //get the agility
    double agility = player -> getAgility();
    //get the strength
    double strength = player -> getStrength();
    //the temp array for converted number
    char tempConverted[50];
    //the text for the health
    char* textH = new char[60];
    //copy the first part
    strcpy(textH, "Your health is ");
    //convert the health
    itoa(health, tempConverted);   
    //concat the converted health
    strcat(textH, tempConverted);
    //push the health
    outputList -> push_back(textH);
    //the text for the agility
    char* textAgility = new char[60];
    //copy the first part
    strcpy(textAgility, "Your agility is ");
    //convert the agility
    dtoaTwo(agility, tempConverted);   
    //concat the converted agility
    strcat(textAgility, tempConverted);
    //push the agility
    outputList -> push_back(textAgility);
    //the buffer for the strength
    char* textStrength = new char[60];
    //copy the first part
    strcpy(textStrength, "Your strength is ");
    //convert the strength
    dtoaTwo(strength, tempConverted);   
    //concat the converted strength
    strcat(textStrength, tempConverted);
    //push the strength
    outputList -> push_back(textStrength);
    //add an empty line to output
    addEmptyLineToOutput(outputList);
}

void ConsoleView::addInventoryInfoToOutput(FedeList<char*>* outputList, Player* player) {
    //the player inventory
    FedeList<Item*>* inventory = player -> getInventory();
    //the buffer for the inventory
    char* textI = new char[60];
    //if the inventory is not empty
    if(inventory -> getSize() > 0){
        //copy the text
        strcpy(textI, "In your inventory there is (max ");
        char maxInventorybuffer[5];
        itoa(Player::MAX_INVENTORY,maxInventorybuffer);
        strcat(textI,maxInventorybuffer);
        strcat(textI," elements):");
    }
    //else (the inventory is empty)
    else{
        //copy the text
        strcpy(textI, "Your inventory is empty.");
    }
    outputList -> push_back(textI);
    //for the list
    for(int i = 0; i < inventory -> getSize(); i++){
        //a string buffer
        char* buffer = new char[512];
        //get the description
        inventory -> get(i) -> getDescription(buffer);
        //add to the list
        outputList -> push_back(buffer);
    }
}

void ConsoleView::addArmorInfoToOutput(FedeList<char*>* outputList, Player* player) {
    //get the armor
    ItemArmor* armor = player -> getArmor();
    //a string for the armor text
    char* armorText = new char[512];
    //if the player is wearing an armor
    if (armor != NULL){
        //copy the text
        strcpy(armorText, "You are wearing ");
        //description
        char description[256];
        //get the description
        armor -> getDescription(description);
        //concate the description
        strcat(armorText, description);
    }
    //else (no armor)
    else{
        //copy the text
        strcpy(armorText, "You are not wearing any armor... You'll probably die soon!");
    }
    //insert the armor text in the list
    outputList -> push_back(armorText);
}

void ConsoleView::clear() {
    //for 100 times
    for(int i = 0; i < 100; i++){
        //print an empty line
        cout << endl;
    }
}

void ConsoleView::showWinner(Player* p) {
    //clear the screen
    this -> clear();
    //if the player is not null
    if (p!= NULL){
        //the complete player name
        char completeName[256];
        //concat the first part
        strcpy(completeName, "#");
        //the buffer for the number of the prisoner
        char number[10];
        //add 15687 for fiction and trasform it to string
        itoa((15687 + p -> getId()), number);
        //concat the number of the prisoner
        strcat(completeName, number);
        //concat "("
        strcat(completeName, "(");
        //the buffer for the name of the prisoner
        char name[50];
        //get the description
        p -> getUsername(name);
        //concat the name
        strcat(completeName, name);
        //concat ")"
        strcat(completeName, ")");
        //print the message (it was a lie...)
        cout << "Congratulation prisoner "<< completeName <<"!\nYou have been told that the winner will be set free right?\nWell... it was a lie.";
    }
    //otherwise (everybody died)
    else{
        //print the message (losers...)
        cout << "You all died... losers!\n";
    }
}

