#include <bits/stdc++.h>

using namespace std;

const string s[] { "1", "22", "333", "4444", "55555", "666666", "7777777", "88888888", "999999999" };

int main(){
    int t;
    scanf("%d", &t);

    for(int x=0;x<t;x++){
        if(x) printf("\n");

        int a, b;
        scanf("%d %d", &a, &b);

        for(int k=0;k<b;k++){
            if(k) printf("\n");
            for(int j=0;j<a-1;j++)
                printf("%s\n", s[j].c_str());
            for(int j=a-1;j>=0;j--)
                printf("%s\n", s[j].c_str());
        }
    }

    return 0;
}
