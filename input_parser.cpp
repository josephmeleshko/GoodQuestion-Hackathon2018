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

string parse_input(){
    string base_input = "";
    getline(cin, base_input);
    base_input = trim(base_input);
    cout << base_input << endl;

    //if(base_input[0] = )





    return base_input;
}


int main(){
    cout << parse_input();



    return 0;
}
