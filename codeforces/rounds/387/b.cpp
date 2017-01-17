#include <bits/stdc++.h>

using namespace std;
using ci = pair<int, char>; 

map<char, int> m;

int main(){
    int n;
    scanf("%d", &n);

    string s;
    cin >> s;

    for(int i=0;i<s.size();i++){
        m[s[i]]++; 
    }

    if(s.size()%4 != 0){
        cout << "===" << endl;
        return 0;
    }

    int x = s.size() / 4;

    string l = "ACTG";
    for(auto& xx : l){
        if(m[xx] > x){
            cout << "===" << endl;
            return 0;
        }
    }

    priority_queue< ci > pq;


    for(int i=0;i<l.size();i++){
        if(m[l[i]] == x) continue;
        pq.push(ci(m[l[i]] - x, l[i]));
    }

    for(int i=0;i<s.size();i++){
        if(s[i] == '?'){
            ci cur = pq.top(); pq.pop();

            s[i] = cur.second;
            m[cur.second]++;

            if(m[cur.second] == x) continue;
            pq.push(ci(m[cur.second] - x, cur.second));
        }
    }

    cout << s << endl;

    return 0;
}
