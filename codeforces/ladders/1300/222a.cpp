#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    map<char,int> m;

    k--;

    vector<int> v;

    string s = "";
    for(int i=0;i<n;i++){
        int num;
        scanf("%d", &num);
        v.push_back(num);
        m[v[i]]++;
    }
    
    int counter = 0;

    while(true){
        if(m.size() == 1){
            break;
        }

        if(counter == n + 2){
            counter = -1;
            break;
        }

        m[v[0]]--;
        if(m[v[0]] == 0) m.erase(v[0]);
        m[v[k]]++;

        counter++;
    }

    printf("%d\n", counter);

    return 0;
}
