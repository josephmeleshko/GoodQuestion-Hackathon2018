#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <cctype>
#include <locale>
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
    string output [4];
    string temp = args;
    int count = 0;
    while(temp.find(',') != string::npos){
        if(count < 4){
            output[count] = temp.substr(0, temp.find(','));
        }
        count++;
        temp = temp.substr(temp.find(',') + 1);
        cout << temp << endl;
    }

    if(count != 3|| count > 3){
        cout << "Wrong amount of arguments for the Build() command";
        return false;
    }
    else{
        output[count] = temp;
        for(int i = 0; i < 4; i++){
            cout << output[i] << " ";
        }
    }
    return true;
}

bool InGameDestroyFunc(string args){
    string temp = args;
    if(temp.find("All") != string::npos){
        temp = trim(temp);
        cout << temp;
        return true;
    }
    else {
        string output [2];
        int count = 0;
        while(temp.find(',') != string::npos){
            if(count < 2){
                output[count] = temp.substr(0, temp.find(','));
            }
            count++;
            temp = temp.substr(temp.find(',') + 1);
            cout << temp << endl;
        }

        if(count != 1 || count > 1){
            cout << "Wrong amount of arguments for the Destroy() command";
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


}

bool InGameChangeLevelFunc(string arg){
    string temp = trim(arg);
    if(temp.length() == 0){
        cout << "Wrong number of arguments for the Change Level() command";
        return false;
    }
    cout << temp << endl;
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
    cout << temp << endl;
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
    return true;
}


bool InGameContinueFunc(){
    return true;
}


bool InGameResetFunc(){
    return true;
}


bool InGameStartFunc(){
    return true;
}


bool InGameQuitFunc(){
    return true;
}


bool InGameSaveFunc(){
    return true;
}


void parse_input(){
    string base_input = "";
    getline(cin, base_input);
    base_input = trim(base_input);
    if(base_input.find("Build") != string::npos){
        if(base_input.find('(') == string::npos || base_input.find(')') == string::npos){
            string error = "Brackets on both ends are needed to get entire input.";
            //return error;
            cout << error;
        }
        else{
            string arguments = base_input.substr(base_input.find('(') + 1, base_input.find(')') - base_input.find('(') - 1);
            cout << arguments;
            InGameBuildFunc(arguments);
        }
    }
    else if(base_input.find("Destroy") != string::npos){
        if(base_input.find('(') == string::npos || base_input.find(')') == string::npos){
            string error = "Brackets on both ends are needed to get entire input.";
            //return error;
            cout << error;
        }
        else{
            string arguments = base_input.substr(base_input.find('(') + 1, base_input.find(')') - base_input.find('(') - 1);
            cout << arguments;
            InGameDestroyFunc(arguments);
        }
    }
    else if(base_input.find("Change Level") != string::npos){
        if(base_input.find('(') == string::npos || base_input.find(')') == string::npos){
            string error = "Brackets on both ends are needed to get entire input.";
            //return error;
            cout << error;
        }
        else{
            string arguments = base_input.substr(base_input.find('(') + 1, base_input.find(')') - base_input.find('(') - 1);
            cout << arguments;
            InGameChangeLevelFunc(arguments);
        }
    }
    else if(base_input.find("Change Setting") != string::npos){
        if(base_input.find('(') == string::npos || base_input.find(')') == string::npos){
            string error = "Brackets on both ends are needed to get entire input.";
            //return error;
            cout << error;
        }
        else{
            string arguments = base_input.substr(base_input.find('(') + 1, base_input.find(')') - base_input.find('(') - 1);
            cout << arguments;
            InGameChangeSettingFunc(arguments);
        }
    }
    else if(base_input.find("Change Speed") != string::npos){
        if(base_input.find('(') == string::npos || base_input.find(')') == string::npos){
            string error = "Brackets on both ends are needed to get entire input.";
            //return error;
            cout << error;
        }
        else{
            string arguments = base_input.substr(base_input.find('(') + 1, base_input.find(')') - base_input.find('(') - 1);
            cout << arguments;
            InGameChangeSpeedFunc(arguments);
        }
    }
    else if(base_input.find("Save") != string::npos){
        cout << "Entering the Save func" << endl;
        InGameSaveFunc();
    }
    else if(base_input.find("Help") != string::npos){
        cout << "Entering the Help func" << endl;
        InGameHelpFunc();
    }
    else if(base_input.find("List Levels") != string::npos){
        cout << "Entering the List Levels func" << endl;
        InGameListLevelsFunc();
    }
    else if(base_input.find("Settings") != string::npos){
        cout << "Entering the Settings func" << endl;
        InGameSettingsFunc();
    }
    else if(base_input.find("Check Resources") != string::npos){
        cout << "Entering the Check Resources func" << endl;
        InGameCheckResourcesFunc();
    }
    else if(base_input.find("Pause") != string::npos){
        cout << "Entering the Pause func" << endl;
        InGamePauseFunc();
    }
    else if(base_input.find("Continue") != string::npos){
        cout << "Entering the Continue func" << endl;
        InGameContinueFunc();
    }
    else if(base_input.find("Reset") != string::npos){
        cout << "Entering the Reset func" << endl;
        InGameResetFunc();
    }
    else if(base_input.find("Start") != string::npos){
        cout << "Entering the Start func" << endl;
        InGameStartFunc();
    }
    else if(base_input.find("Quit") != string::npos){
        cout << "Entering the Quit func" << endl;
        InGameQuitFunc();
    }
    else{
        cout << "Wrong Input!" << endl;
    }

}


int main(){
    string input = "";
    getline(cin, input);
    while(input != "END"){
        parse_input();
        cout << endl;
        getline(cin, input);
    }



    return 0;
}