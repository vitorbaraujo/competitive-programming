#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    string s, ss;
    map<char, int> m;
    cin >> s;

    ll sum = 0;
    bool z = false;

    int n = s.size();
    for(auto c : s){
        if(c != '0') z = true;
        if(!(c == '0' and !z)){
            ss += c;
            m[c]++;
        }
        sum += (c - '0');
    }

    if(ss.empty()){
        cout << -1 << endl;
        return 0;
    }

    if(sum%3 == 0){
        cout << ss << endl;
        return 0;
    }

    int mini = sum - 3 * (sum / 3);
    int xx = ss.find(mini + '0');

    if(xx != string::npos){
        ss.erase(ss.begin() + xx);
    }
    else{
        ss = "-1";
    }

    z = false;
    string sss = "";
    for(auto c : ss){
        if(c != '0') z = true;
        if(!(c == '0' and !z)){
            sss += c;
        }
    }

    cout << (sss.empty() ? "0" : sss) << endl;

    return 0;
}
