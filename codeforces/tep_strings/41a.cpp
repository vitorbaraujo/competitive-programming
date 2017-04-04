#include <bits/stdc++.h>

using namespace std;

int main(){
    string a, b;
    cin >> a >> b;

    if(a.size() != b.size()){
        cout << "NO" << endl;
        return 0;
    }

    for(int i=0;i<(int)a.size();i++){
        if(a[i] != b[b.size() - i - 1]){
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;

    return 0;
}
