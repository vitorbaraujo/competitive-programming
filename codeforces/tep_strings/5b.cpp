#include <bits/stdc++.h>

using namespace std;

vector<string> v;

int main(){
    string s;
    int maxi = 0;

    while(getline(cin,s)){
        v.push_back(s);
        maxi = max(maxi, (int)s.size());
    }

    for(int i=0;i<maxi+2;i++) printf("*");
    printf("\n");

    bool lt = true;

    for(auto c : v){
        int t = (maxi - c.size()) / 2;
        int t2 = (maxi - c.size() - t);
        printf("*");
        for(int i=0;i<(lt ? t : t2);i++) printf(" ");
        cout << c;
        for(int i=0;i<(lt ? t2 : t);i++) printf(" ");
        printf("*\n");

        if(t != t2) lt = !lt;
    }

    for(int i=0;i<maxi+2;i++) printf("*");
    printf("\n");

    return 0;
}
