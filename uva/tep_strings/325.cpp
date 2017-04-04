#include <bits/stdc++.h>

// #include <regex>

using namespace std;

int main(){
    string s;

    while(cin >> s, s != "*"){

        regex r("^(\\+|\\-)?(\\d+)(((e|E)(\\+|\\-)?\\d+)$|((\\.\\d+)((e|E)(\\+|\\-)?\\d+)?)$)");

        cout << s << " ";
        if(regex_match(s, r))
            cout << "is legal.";
        else
            cout << "is illegal.";
        cout << endl;
    }

    return 0;
}
