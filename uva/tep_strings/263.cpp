#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    string s;
    map<ll, int> m;

    while(cin >> s, s != "0"){
        printf("Original number was %s\n", s.c_str());
        m.clear();
        m[stoll(s)]++;

        int counter = 1;
        while(1){
            string a = s;
            sort(a.begin(), a.end());
            string b = a;
            reverse(b.begin(), b.end());

            ll bb = stoll(b), aa = stoll(a);
            ll res = bb - aa;

            printf("%lld - %lld = %lld\n", bb, aa, res);

            if(m[res]){
                break;
            }

            m[res]++;
            s = to_string(res);
            counter++;
        }
        printf("Chain length %d\n", counter);
        printf("\n");
    }

    return 0;
}
