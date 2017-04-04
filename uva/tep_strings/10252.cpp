#include <bits/stdc++.h>

using namespace std;

int main(){
    string a, b, res;
    map<char, int> m1, m2;

    while(getline(cin, a)){
        getline(cin, b);
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        m1.clear(); m2.clear();
        res = "";
        for(auto& c : a) m1[c]++;
        for(auto& c : b) m2[c]++;

        for(int i=0;i<26;i++){
            int mini = min(m1[i + 'a'], m2[i + 'a']);
            if(mini){
                while(mini--) res += char(i + 'a'); 
            }
        }

        cout << res << endl;
    }

    return 0;
}
