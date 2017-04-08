#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    while(getline(cin, s), s != "*"){
        stringstream b(s);
        string word;

        bool ok = true;
        b >> word;
        char c = tolower(word[0]);
        while(b >> word){
            if(tolower(word[0]) != c){
                ok = false;
                break;
            }
        }

        printf("%s\n", ok ? "Y" : "N");
    }

    return 0;
}
