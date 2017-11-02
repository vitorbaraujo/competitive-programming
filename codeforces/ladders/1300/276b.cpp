#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin >> s;

    int h[30];
    memset(h, 0, sizeof h);

    for(auto c : s){
        h[c - 'a'] = (h[c - 'a'] + 1)%2;
    }

    int counter = 0;

    for(int i=0;i<27;i++){
        counter += h[i]; 
    }

    if(counter == 0 || counter == 1 || counter % 2 != 0)
        printf("First\n");
    else
        printf("Second\n");

    return 0;
}
