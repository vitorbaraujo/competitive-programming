#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

int d(ii a, ii b){
    return abs(a.first - b.first) + abs(a.second - b.second);
}

string dirs = "NSEW";
const ii us[] { ii(0,1), ii(0,-1), ii(1,0), ii(-1,0) };

int main(){
    int t;
    ii a, b;

    cin >> t >> a.first >> a.second >> b.first >> b.second;

    int dist = d(a,b); 

    string s;
    cin >> s;
    int res = -1;

    for(int i=0;i<s.size();i++){
        char c = s[i];
        ii togo = us[dirs.find(c)];

        a.first += togo.first;
        a.second += togo.second;

        if(d(a,b) <= dist){
            dist = d(a,b); 
            if(dist == 0) res = i + 1;
            continue;
        }

        a.first -= togo.first;
        a.second -= togo.second;
    }

    printf("%d\n", dist == 0 ? res : -1);

    return 0;
}
