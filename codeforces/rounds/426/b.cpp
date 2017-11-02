#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    int n, k;
    cin >> n >> k >> s;

    int occ[30];
    memset(occ, 0, sizeof occ);

    for(int i=0;i<n;i++){
        occ[s[i]-'A'] = max(occ[s[i]-'A'], i);
    }

    int open = 0;
    int op[30];
    memset(op, 0, sizeof op);

    for(int i=0;i<n;i++){
        if(open > k){
            cout << "YES" << endl;
            return 0;
        }
        int c = s[i]-'A';
        if(op[c] == 0){
            op[c] = 1;
            open++;
        }
        if(occ[c] == i){
            op[c] = 0;
            open--;
        }
    cout << open << endl;
    }

    cout << "NO" << endl;

    return 0;
}
