#include <bits/stdc++.h>

using namespace std;

int main(){
    const string s = "v<^>";

    char c1, c2;
    int n;
    cin >> c1 >> c2 >> n;
    
    n%=4;

    int d1 = s.find(c1);
    char s1 = s[(d1 + n)%4];
    char s2 = s[(d1 - n + 4)%4];

    if(s1 == c2 && s1 == s2) cout << "undefined";
    else if(s1 == c2) cout << "cw";
    else if(s2 == c2) cout << "ccw";

    cout << endl;


    return 0;
}
