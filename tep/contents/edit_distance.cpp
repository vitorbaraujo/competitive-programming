#include <bits/stdc++.h>

using namespace std;

#define MAX_N 1000
#define MAX_M 1000

// Complexidade O(nm) <- custo de memória
int st[MAX_N][MAX_M];
int ci = 1, cr = 1, cs = 1;

int edit(const string& s, const string& t){
    int n = s.size();
    int m = t.size();

    for(int i=0;i<=n;i++){
        st[i][0] = i * cr;
    }

    for(int j=0;j<=m;j++){
        st[0][j] = j * ci;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            st[i][j] = min(st[i-1][j] + cr, st[i][j-1] + ci);
            st[i][j] = min(st[i][j], st[i-1][j-1] + cs * (s[i-1] == t[j-1] ? 0 : 1));
        }
    }

    return st[n][m];
}

// Complexidade O(nm), memoria O(n)
int a[MAX_N], b[MAX_N];

int edit2(const string& s, const string& t){
    int n = s.size();
    int m = t.size();

    int *prev = a, *line = b;

    for(int j=0;j<=m;j++)
        prev[j] = j * ci;

    for(int i=1;i<=n;i++){
        line[0] = i * cr;

        for(int j=1;j<=m;j++){
            int insertion = line[j-1] + ci;
            int deletion = prev[j] + cr;
            int change = prev[j-1] + cs * (s[i-1] == t[j-1] ? 0 : 1);

            line[j] = min(insertion, deletion);
            line[j] = min(line[j], change);
        }

        swap(line, prev);
    }

    return prev[n];
}

int st2[MAX_N][MAX_M];
char ps[MAX_N][MAX_M];

string edit_operations(const string& s, const string& t){
    int m = s.size();
    int n = t.size();

    for(int i=0;i<=m;i++){
        st2[i][0] = i * cr;
        ps[i][0] = 'r';
    }

    for(int j=1;j<=n;j++){
        st2[0][j] = j * ci;
        ps[0][j] = 'i';
    }

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            int insertion = st2[i][j-1] + ci;
            int deletion = st2[i-1][j] + cr;
            int change = st2[i-1][j-1] + cs * (s[i-1] == t[j-1] ? 0 : 1);

            st2[i][j] = min(insertion, deletion);
            st2[i][j] = min(st2[i][j], change);

            if(insertion <= deletion and insertion <= change)
                ps[i][j] = 'i';
            else if(deletion <= change)
                ps[i][j] = 'r';
            else
                ps[i][j] = 's';
        }
    }

    cout << "Operations: " << st2[m][n] << endl;

    int i = m, j = n;

    stack<string> S;
    char buffer[128];
    string subs = "[x->y]";

    while(i or j){
        switch(ps[i][j]){
            case 'i':
                sprintf(buffer, "%c", t[j-1]);
                --j;
                break;
            case 'r':
                sprintf(buffer, "x");
                --i;
                break;
            case 's':
                if(s[i-1] == t[j-1])
                    sprintf(buffer, "-");
                else
                    sprintf(buffer, "[%c->%c]", s[i-1], t[j-1]);

                --i;
                --j;
        }

        S.push(buffer);
    }

    ostringstream os;

    while(not S.empty()){
        os << S.top();
        S.pop();
    }

    return os.str();
    
}

int main(){
    string s = "fga";
    string t = "formiga";

    memset(st, 0, sizeof st);

    cout << edit_operations(s, t) << endl;

    return 0;
}
