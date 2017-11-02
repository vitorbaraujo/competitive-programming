#include <bits/stdc++.h>

using namespace std;


int main(){
    string text, pat;
    cin >> text >> pat;

    int idx = 0;
    int counter = 0;
    auto aux = text.find(pat, idx);
    while(aux != string::npos){
        counter++;
        idx = aux + pat.size();
        aux = text.find(pat, idx);
    }

    cout << counter << endl;

    return 0;
}
