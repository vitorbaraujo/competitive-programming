#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    string s, a , b;
    scanf("%d\n", &t);

    for(int i=0;i<t;i++){
        if(i) printf("\n");
        getline(cin, a);
        getline(cin, b);

        cout << b << endl;
        cout << a << endl;

        while(getline(cin, s), s != ""){
            string res;
            transform(s.begin(), s.end(), back_inserter(res), [&](char c) {
                return a.find(c) != string::npos ? b[a.find(c)] : c; 
            });
            cout << res << endl;
        }
    }

    return 0;
}
