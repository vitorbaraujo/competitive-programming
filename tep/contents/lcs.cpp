#include <bits/stdc++.h>

using namespace std;

#define MAX_M 1001
#define MAX_N 1001
#define INF 1000000010

int st[MAX_M][MAX_N], a[MAX_N], b[MAX_N];
int ci = 0, cr = 0, cs = 1;
char ps[MAX_M][MAX_N];
/*
int lcs(const string& s, const string& t){
    int m = s.size();
    int n = t.size();

    for(int i=0;i<=m;i++)
        st[i][0] = i * cr;
    for(int j=0;j<=n;j++)
        st[0][j] = j * ci;

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            int insertion = st[i][j-1] + ci;
            int deletion = st[i-1][j] + cr;
            int change = st[i-1][j-1] + cs * (s[i-1] == t[j-1] ? 1 : -INF);

            st[i][j] = max(insertion, deletion);
            st[i][j] = max(st[i][j], change);
        }
    }

    return st[m][n];
}
*/

string get_lcs(const string& s, const string& t){
    int i = s.size(), j = t.size();
    stack<char> S;

    while(i or j){
        switch(ps[i][j]){
            case 'i':
                --j;
                break;
            case 'r':
                --i;
                break;
            case 's':
                if(s[i-1] == t[j-1])
                    S.push(s[i-1]);

                --i;
                --j;
        }
    }

    ostringstream os;

    while(not S.empty()){
        os << S.top();
        S.pop();
    }

    return os.str();
}

string lcs(const string& s, const string& t){
    int m = s.size();
    int n = t.size();

    for(int i=0;i<=m;i++){
        st[i][0] = i * cr;
        ps[i][0] = 'r';
    }

    for(int j=0;j<=n;j++){
        st[0][j] = j * ci;
        ps[0][j] = 'i';
    }

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            int insertion = st[i][j-1] + ci;
            int deletion = st[i-1][j] + cr;
            int change = st[i-1][j-1] + cs * (s[i-1] == t[j-1] ? 1 : -INF);

            st[i][j] = max(insertion, deletion);
            st[i][j] = max(st[i][j], change);

            if(insertion >= deletion and insertion >= change)
                ps[i][j] = 'i';
            else if(deletion >= change)
                ps[i][j] = 'r';
            else
                ps[i][j] = 's';
        }
    }

    return get_lcs(s, t);
}

#define MAX 1000010

int dp[MAX];

int lis(const vector<int>& vv){
    dp[0] = -1;
    int n = 0;

    for(auto x : vv){
        if(x > dp[n])
            dp[++n] = x;
        else{
            auto it = lower_bound(dp + 1, dp + n, x);
            *it = min(*it, x);
        }
    }

    return n;
}


int main(){
    string s = "anos";
    string t = "caido";

    vector<int> v {2,6,9,12, 3,7,0,4};

    int n = lis(v);
    cout << "tamanho do lcs: " << n << endl;

    cout << lcs(s, t) << endl;

    return 0;
}
