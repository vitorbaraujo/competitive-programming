#include <bits/stdc++.h>

using namespace std;

bool isv(char c){ string s = "aeiouy"; return s.find(c) != string::npos; }

int main(){
    string s;
    bool flag;

    while(getline(cin, s), s != "e/o/i"){
        flag = false;
        int pos = s.find('/');
        int pos2 = s.find('/', pos + 1);
        string a(s, 0, pos + 1);
        string b(s, pos + 1, pos2 - pos);
        string c(s, pos2 + 1, s.size() - pos2); 
        c += '/';

        int counter = 0;
        char previ = a[0];
        for(int i=1;i<a.size();i++){
            if(!isv(a[i]) and isv(previ)) counter++; 
            previ = a[i];
        }

        if(counter != 5){
            cout << 1 << endl;
            flag = true;
            continue;
        }

        counter = 0;
        previ = b[0];
        for(int i=1;i<b.size();i++){
            if(!isv(b[i]) and isv(previ)) counter++; 
            previ = b[i];
        }

        if(counter != 7){
            cout << 2 << endl;
            flag = true;
            continue;
        }

        counter = 0;
        previ = c[0];
        for(int i=1;i<c.size();i++){
            if(!isv(c[i]) and isv(previ)) counter++; 
            previ = c[i];
        }

        if(counter != 5){
            cout << 3 << endl;
            flag = true;
        }

        if(not flag) cout << "Y" << endl;
    }

    return 0;
}
