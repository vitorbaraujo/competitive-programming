#include <bits/stdc++.h>
#define ll long long
#define MP 10000010

using namespace std;

ll primes[MP];
short isp[MP];
ll pc = 0;

void sieve(){
    primes[pc++] = 2;
    memset(isp, 1, sizeof isp);

    for(int i=4;i<=MP;i+=2) isp[i] = 0;
    
    int i;
    for(i=3;(i*i) <= MP;i+=2){
        if(isp[i]){
            primes[pc++] = i;

            for(int j=i*i;j<=MP;j+=i)
                isp[j] = 0;
        }
    }

    if(!(i &1)) i++;
    for(;i<=MP;i+=2){
        if(isp[i])
            primes[pc++] = i;
    }
}

int main(){
    sieve();

    int n;
    cin >> n;

    for(int i=0;i<n;i++){
        if(i) printf(" ");
        printf("%lld", primes[i+1]);
    }
    printf("\n");

    return 0;
}
