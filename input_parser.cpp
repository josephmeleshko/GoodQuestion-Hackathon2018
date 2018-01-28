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
        output[count] = temp.substr(0, temp.find(','));
        count++;
        temp = temp.substr(temp.find(',') + 1);
        cout << temp << endl;
    }
    output[count] = temp;
    if(count != 3){
        cout << "Wrong amount of arguments for the Build() command";
        return false;
    }
    else{
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
            output[count] = temp.substr(0, temp.find(','));
            count++;
            temp = temp.substr(temp.find(',') + 1);
            cout << temp << endl;
        }
        output[count] = temp;
        if(count != 1){
            cout << "Wrong amount of arguments for the Destroy() command";
            return false;
        }
        else{
            for(int i = 0; i < 2; i++){
                cout << output[i] << " ";
            }
        }
        return true;
    }


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

}


int main(){
    parse_input();
    cout << endl;



    return 0;
}
