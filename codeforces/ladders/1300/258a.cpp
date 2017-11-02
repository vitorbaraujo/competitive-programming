#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin >> s;

    bool ok = false;

    for(auto it = s.begin(); it != s.end(); it++){
        if(*it == '0'){
            s.erase(it);
            ok = true;
            break;
        }
    }

    if(not ok) s.erase(s.end() - 1);

    cout << s << endl;

    return 0;
}
