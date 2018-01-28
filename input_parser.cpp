#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <cctype>
#include <locale>
#include <fstream>
#include "input_parser.h"
#include "globalHeader.h"
#include "mainDraw.h"
#include "gametick.h"
#include "levels.h"
#include <stdio.h>

using namespace std;

// trim from start
static inline string &ltrim(string &s) {
    s.erase(s.begin(), find_if(s.begin(), s.end(),
            not1(ptr_fun<int, int>(isspace))));
    return s;
}

// trim from end
static inline string &rtrim(string &s) {
    s.erase(find_if(s.rbegin(), s.rend(),
            not1(ptr_fun<int, int>(isspace))).base(), s.end());
    return s;
}

// trim from both ends
static inline string &trim(string &s) {
    return ltrim(rtrim(s));
}


bool InGameBuildFunc(string args){
    int output[3];
    string temp = args;
    int count = 0;
    while(temp.find(',') != string::npos){
        if(count < 2){
            output[count] = stoi(temp.substr(0, temp.find(',')).c_str());
        }
        count++;
        temp = temp.substr(temp.find(',') + 1);
    }
    output[count] = stoi(temp.c_str());
    if(count != 2|| count > 2){
        cout << "Wrong amount of arguments for the Build() command";
        return false;
    }
    else if (output[1] < 2) {
        cout << "NO DELETEY LAVA" << endl;
        return false;
    }
    else{
        int value = getSpace(output[0], output[1]);
        if (value == 0) {
            if (output[2] == 1 || output[2] == 4 || output[2] == 6 || output[2] == 7) {
                changeSpace(output[0], output[1], output[2]);
            }
        }
    }
    drawScreen(activeLevel);
    return true;
}

bool InGameDestroyFunc(string args){
    int output[2];
    string temp = args;
    int count = 0;
    while(temp.find(',') != string::npos){
        if(count < 1){
            output[count] = stoi(temp.substr(0, temp.find(',')).c_str());
        }
        count++;
        temp = temp.substr(temp.find(',') + 1);
    }
    output[count] = stoi(temp.c_str());
    if(count != 1|| count > 1){
        cout << "Wrong amount of arguments for the Destroy() command";
        return false;
    }
    else if (output[1] < 2) {
        cout << "NO DELETEY LAVA" << endl;
        return false;
    }
    else {
        int value = getSpace(output[0], output[1]);
        if (value == 1 || value == 4 || value == 7) {
            changeSpace(output[0], output[1], 0);
        }
    }
    drawScreen(activeLevel);
    return true;
}

bool InGameChangeLevelFunc(string arg){
    string temp = trim(arg);
    if(temp.length() == 0){
        cout << "Wrong number of arguments for the Change Level() command";
        return false;
    }

    if (temp == "0") {
        activeLevel = nullData();
        levelPointer = level0data();
        for (int i = 0; i < 527; i++) {activeLevel[i] = levelPointer[i];}
        currentLevel = 0;
        drawScreen(activeLevel);
    }
    else if (temp == "1") {
        activeLevel = nullData();
        levelPointer = level1data();
        for (int i = 0; i < 527; i++) {activeLevel[i] = levelPointer[i];}
        currentLevel = 1;
        drawScreen(activeLevel);
    }
    else if (temp == "2") {
        activeLevel = nullData();
        levelPointer = level2data();
        for (int i = 0; i < 527; i++) {activeLevel[i] = levelPointer[i];}
        currentLevel = 2;
        drawScreen(activeLevel);
    }
    else if (temp == "3") {
        activeLevel = nullData();
        levelPointer = level3data();
        for (int i = 0; i < 527; i++) {activeLevel[i] = levelPointer[i];}
        currentLevel = 3;
        drawScreen(activeLevel);
    }
    else if (temp == "4") {
        activeLevel = nullData();
        levelPointer = level4data();
        for (int i = 0; i < 527; i++) {activeLevel[i] = levelPointer[i];}
        currentLevel = 4;
        drawScreen(activeLevel);
    }
    return true;
}

bool InGameChangeSettingFunc(string args){
    string temp = args;
    string output [2];
    int count = 0;
    while(temp.find(',') != string::npos ){
        if(count < 2){
            output[count] = temp.substr(0, temp.find(','));
        }
        count++;
        temp = temp.substr(temp.find(',') + 1);
        cout << temp << endl;
    }

    if(count != 1|| count > 1){
        cout << "Wrong amount of arguments for the Change Setting() command";
        return false;
    }
    else{
        output[count] = temp;
        for(int i = 0; i < 2; i++){
            cout << output[i] << " ";
        }
    }
    return true;
}

bool InGameChangeSpeedFunc(string arg){
    string temp = trim(arg);
    if(temp.length() == 0){
        cout << "Wrong number of arguments for the Change Speed() command";
        return false;
    }
    tickTime = atoi(temp.c_str());
    return true;
}


bool InGameHelpFunc(){
    return true;
}


bool InGameListLevelsFunc(){
    return true;
}


bool InGameSettingsFunc(){
    return true;
}


bool InGameCheckResourcesFunc(){
    return true;
}


bool InGamePauseFunc(){
    isPlaying = false;
    return true;
}


bool InGameContinueFunc(){
    isPlaying = true;
    return true;
}

bool InGameRunCode() {
    InGameResetFunc();
    parse_editor_input("editor.txt");
    return true;
}


bool InGameResetFunc(){
    if (currentLevel == 0) {
        activeLevel = nullData();
        levelPointer = level0data();
        for (int i = 0; i < 527; i++) {activeLevel[i] = levelPointer[i];}
        drawScreen(activeLevel);
    }
    else if (currentLevel == 1) {
        activeLevel = nullData();
        levelPointer = level1data();
        for (int i = 0; i < 527; i++) {activeLevel[i] = levelPointer[i];}
        drawScreen(activeLevel);
    }
    else if (currentLevel == 2) {
        activeLevel = nullData();
        levelPointer = level2data();
        for (int i = 0; i < 527; i++) {activeLevel[i] = levelPointer[i];}
        drawScreen(activeLevel);
    }
    else if (currentLevel == 3) {
        activeLevel = nullData();
        levelPointer = level3data();
        for (int i = 0; i < 527; i++) {activeLevel[i] = levelPointer[i];}
        drawScreen(activeLevel);
    }
    else if (currentLevel == 4) {
        activeLevel = nullData();
        levelPointer = level4data();
        for (int i = 0; i < 527; i++) {activeLevel[i] = levelPointer[i];}
        drawScreen(activeLevel);
    }
    isPlaying = false;
    walkingRight = true;
    return true;
}


bool InGameStartFunc(){
    return true;
}


bool InGameQuitFunc(){
    quit = true;
    return true;
}


bool InGameSaveFunc(){
    return true;
}


void parse_editor_input(string filename){

    string base_input = InputFile(filename);

    cout << base_input << endl;

    string delimiter = "\n";

    size_t pos = 0;
    string token;
    while ((pos = base_input.find(delimiter)) != string::npos) {
        token = base_input.substr(0, pos);
        base_input.erase(0, pos + delimiter.length());
        if(token.find("build") != string::npos){
            if(token.find('(') == string::npos || token.find(')') == string::npos){
                string error = "Brackets on both ends are needed to get entire input.";
                //return error;
                cout << error;
            }
            else{
                string arguments = token.substr(token.find('(') + 1, token.find(')') - token.find('(') - 1);
                InGameBuildFunc(arguments);
            }
        }
        else if(token.find("destroy") != string::npos){
            if(token.find('(') == string::npos || token.find(')') == string::npos){
                string error = "Brackets on both ends are needed to get entire input.";
                //return error;
                cout << error;
            }
            else{
                string arguments = token.substr(token.find('(') + 1, token.find(')') - token.find('(') - 1);
                InGameDestroyFunc(arguments);
            }
        }
    }
}

void parse_terminal_input(){
    string base_input = InputFile("input.txt");

    if(base_input.find("change level") != string::npos){
        if(base_input.find('(') == string::npos || base_input.find(')') == string::npos){
            string error = "Brackets on both ends are needed to get entire input.";
            //return error;
            cout << error;
        }
        else{
            string arguments = base_input.substr(base_input.find('(') + 1, base_input.find(')') - base_input.find('(') - 1);
            InGameChangeLevelFunc(arguments);
        }
    }
    else if(base_input.find("change setting") != string::npos){
        if(base_input.find('(') == string::npos || base_input.find(')') == string::npos){
            string error = "Brackets on both ends are needed to get entire input.";
            //return error;
            cout << error;
        }
        else{
            string arguments = base_input.substr(base_input.find('(') + 1, base_input.find(')') - base_input.find('(') - 1);
            InGameChangeSettingFunc(arguments);
        }
    }
    else if(base_input.find("change tickspeed") != string::npos){
        if(base_input.find('(') == string::npos || base_input.find(')') == string::npos){
            string error = "Brackets on both ends are needed to get entire input.";
            //return error;
            cout << error;
        }
        else{
            string arguments = base_input.substr(base_input.find('(') + 1, base_input.find(')') - base_input.find('(') - 1);
            InGameChangeSpeedFunc(arguments);
        }
    }
    else if(base_input.find("save") != string::npos){
        InGameSaveFunc();
    }
    else if(base_input.find("help") != string::npos){
        InGameHelpFunc();
    }
    else if(base_input.find("list levels") != string::npos){
        InGameListLevelsFunc();
    }
    else if(base_input.find("settings") != string::npos){
        InGameSettingsFunc();
    }
    else if(base_input.find("check resources") != string::npos){
        InGameCheckResourcesFunc();
    }
    else if(base_input.find("pause") != string::npos){
        InGamePauseFunc();
    }
    else if(base_input.find("continue") != string::npos){
        InGameContinueFunc();
    }
    else if(base_input.find("reset") != string::npos){
        InGameResetFunc();
    }
    else if(base_input.find("run code") != string::npos){
        InGameRunCode();
    }
    else if(base_input.find("start") != string::npos){
        InGameStartFunc();
    }
    else if(base_input.find("quit") != string::npos){
        InGameQuitFunc();
    }
    else if(base_input.find("exit") != string::npos){
        InGameQuitFunc();
    }
    else if(base_input.find("haltandcatchfire") != string::npos){
        cout << "AHAHHAHAHAHHAHAHAHAH" << endl;
        InGameQuitFunc();
    }
    else{
        cout << "Wrong Input!" << endl;
    }

}

string InputFile(string filename) {
    string txt;
    string input = "";
    ifstream file(filename);
    if (file.is_open()) {
        while (file.good()) {
            getline(file, txt);
            input += txt + '\n';
        }
    }
    file.close();
    return input;
}

string InputLine(string filename){
    string txt;
    string input = "";
    ifstream file(filename);
    getline(file, txt);
    file.close();
    return input;
}
