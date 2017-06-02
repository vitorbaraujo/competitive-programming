#include <bits/stdc++.h>

using namespace std;

vector<int> z_function(const string& s){
    int n = s.size();
    vector<int> z(n, 0);

    int L = 0, R = 0;
    for(int i=1;i<n;i++){
        if(i <= R)
            z[i] = min(z[i - L], R - i + 1);
        while(i + z[i] < n && s[z[i]] == s[i + z[i]])
            z[i]++;
        if(R < i + z[i] - 1){
            L = i;
            R = i + z[i] - 1;
        }
    }
    return z;
}

int main(){
    string s;

    while(cin >> s){

        string rev = s;
        reverse(rev.begin(), rev.end());

        string ss = rev + '#' + s;

        vector<int> z = z_function(ss);

        int maxi = 0;
        for(int i=s.size() + 1; i < z.size(); i++){
            if(i + z[i] == z.size()){
                maxi = z[i];
                break;
            }
        }

        string to_app(rev, maxi, rev.size() - maxi);
        s += to_app;

        printf("%s\n", s.c_str());
    }

    return 0;
}
