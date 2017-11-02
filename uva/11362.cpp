#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        int n;
        scanf("%d", &n);

        vector<string> v;

        for(int i=0;i<n;i++){
            string s;
            cin >> s;
            v.push_back(s);
        }

        sort(v.begin(), v.end());

        bool ok = true;

        for(int i=0;i<v.size()-1;i++){
            if(v[i+1].find(v[i]) == 0){
                ok = false;
                break;
            }
        }

        printf("%s\n", (ok ? "YES" : "NO"));
    }

    return 0;
}
