#include <bits/stdc++.h>
#define MAX 300010

using namespace std;

int main(){
    int n;
    cin >> n;

    long long v[MAX];
    map<long long, int> m;

    for(int i=0;i<n;i++){
        scanf("%lld", &v[i]);
        m[v[i]]++;
    }

    sort(v, v + n);

    long long mini = abs(v[0] - v[1]); 
    
    for(int i=0;i<(n-1);i++){
        mini = min(mini, abs(v[i] - v[i+1]));
    }

    int cont = 0;

    for(int i=0;i<n;i++){
        if(m[v[i] + mini]){
            cont++;
        }
    }

    cout << mini << " " << cont << endl;

    return 0;
}
