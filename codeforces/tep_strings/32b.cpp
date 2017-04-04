#include <bits/stdc++.h>

using namespace std;

int main(){
    string s, res = "";
    cin >> s;
    s += " ";

    for(int i=0;i<s.size();i++){
        if(s[i] == '.'){
            res += "0";
        }
        else if(s[i] == '-' && s[i+1] == '.'){
            res += "1";
            i++;
        }
        else if(s[i] == '-' && s[i+1] == '-'){
            res += "2";
            i++;
        }
    }
    cout << res << endl;

    return 0;
}
