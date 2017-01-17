#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    scanf("%d", &n);

    pair<int, int> best = make_pair(0,1 << 25);

    for(int i=1;i<=sqrt(n);i++){
        if(n%i == 0 && abs(i - n/i) < abs(best.first - best.second)){
            best = make_pair(i, n/i);
        }
    }

    printf("%d %d\n", min(best.first, best.second), max(best.first, best.second));

    return 0;
}
