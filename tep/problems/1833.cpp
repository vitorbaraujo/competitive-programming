#include <bits/stdc++.h>

using namespace std;

int cr = 5, cs = 10, ci = 25;
int st[110][110];

int lcs(const string& s, const string& t){
    int m = s.size();
    int n = t.size();

    for(int i=0;i<=m;i++) st[i][0] = i * cr;
    for(int j=0;j<=n;j++) st[0][j] = j * ci;

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            int insertion = st[i][j-1] + ci;
            int deletion = st[i-1][j] + cr;
            int change = st[i-1][j-1] + cs * (s[i-1] == t[j-1] ? 0 : 1);

            st[i][j] = min(insertion, deletion);
            st[i][j] = min(st[i][j], change);
        }
    }

    return st[m][n];
}

int main(){
    int t;
    scanf("%d", &t);


    for(int xx=1;xx<=t;xx++){

        int price;
        scanf("%d", &price);
        int mm, n;
        scanf("%d", &mm);

        char letter = 'a';
        map<string, char> m;

        string a = "", b = "";
        while(mm--){
            string s;
            cin >> s;
            if(m.find(s) != m.end()) a += m[s];
            else{
                m[s] = letter;
                a += letter++;
            }
        }

        scanf("%d", &n);
        while(n--){
            string s;
            cin >> s;
            if(m.find(s) != m.end()) b += m[s];
            else{
                m[s] = letter;
                b += letter++;
            }
        }

        int res = lcs(a, b) * price;

        printf("Caso #%d: R$ %d,%02d\n", xx, res / 10, 10 * (res % 10));
    }

    return 0;
}
