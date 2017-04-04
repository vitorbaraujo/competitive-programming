#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    int steps[200];

    for(int i=0;i<n;i++)
        v[i] = i + 1;

    for(int i=0;i<k;i++)
        scanf("%d", &steps[i]);

    int ni = n;

    int prevm = 0;
    int leader = 0;
    
    for(int i=0;i<k;i++){
        int mod = steps[i]%(ni);

        if(i) printf(" ");
        printf("%d", *(v.begin() + (leader + mod)%ni));
        v.erase(v.begin() + (leader + mod)%ni); 

        leader = (leader + mod)%ni;
        ni--;
    }

    printf("\n");


    return 0;
}
