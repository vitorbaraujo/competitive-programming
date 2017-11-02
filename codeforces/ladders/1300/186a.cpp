#include <bits/stdc++.h>

using namespace std;

int main(){
    string a, b;
    cin >> a >> b;
    int cont = 0;

    if(a.size() != b.size()){
        cout << "NO" << endl;
        return 0;
    }

    string da = "",db = "";

    for(int i=0;i<a.size();i++){
        if(a[i] != b[i]){
            cont++;
            da += a[i];
            db += b[i];
        }
    }

    sort(da.begin(), da.end());
    sort(db.begin(), db.end());

    cout << (cont == 2 && da == db ? "YES" : "NO") << endl;

    return 0;
}
