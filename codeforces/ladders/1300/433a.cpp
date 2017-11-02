#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    int a=0, b=0;
    for(int i=0;i<n;i++){
        int n;
        scanf("%d", &n);
        a += n == 100;
        b += n == 200;
    }

    if((a * 100 + b * 200 % 2) != 0){
        printf("NO\n");
        return 0;
    }

    if(a == b * 2){
        printf("YES\n");
        return 0;
    }

    int diff = a - b * 2;

    if(diff > 0){
        if(diff % 2 == 0) printf("YES\n");
        else printf("NO\n");
    }
    else{
        
    }

    return 0;
}
