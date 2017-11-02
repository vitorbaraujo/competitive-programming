#include <bits/stdc++.h>

using namespace std;

vector<int> zf(const string &s){
    int n = s.size();
    int L = 0, R = 0;

    vector<int> z(n, 0);

    for(int i=1;i<n;i++){
        if(i <= R)
            z[i] = min(z[i-L], R - i + 1);

        while(i + z[i] < n && s[i + z[i]] == s[z[i]])
            ++z[i];

        if(R < i + z[i] - 1)
            L = i, R = i + z[i] - 1;
    }

    return z;
}

int main(){
    string s;

    while(cin >> s){
        string rev = s;
        reverse(rev.begin(), rev.end());
    
        string tudo = rev + '#' + s;

        vector<int> z = zf(tudo);

        int maxi = -1;
        for(auto c : z)
            maxi = max(maxi, c);

        string cpl(rev, maxi, s.size() - maxi);
        string ss = s + cpl;

        rev = ss;
        reverse(rev.begin(), rev.end());
        if(ss != rev){
            cout << "NAAAAO" << endl;
            cout << "in: [" << s << "]" << endl;
            cout << "out: [" << ss << "]" << endl;
        }

    }

    return 0;
}
