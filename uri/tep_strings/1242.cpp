#include <bits/stdc++.h>

using namespace std;


map<char, char> m;

int main(){
    string ss;

    m['B'] = 'S';
    m['S'] = 'B';
    m['F'] = 'C';
    m['C'] = 'F';

    while(cin >> ss){
        stack<char> s;

        int cont = 0;

        for(auto& c : ss){
            if(s.empty()) s.push(c);
            else{
                if(s.top() == m[c]){
                    cont++;
                    s.pop();
                }
                else s.push(c);
            }
        }

        cout << cont << endl;
    }

    return 0;
}
