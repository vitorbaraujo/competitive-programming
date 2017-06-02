#include <bits/stdc++.h>

using namespace std;

// Complexidade: O(n²)
vector<int> naive_z_function(const string& s){
    int n = s.size();
    vector<int> z(n, 0);

    for(int i=1;i<n;i++){
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]){
            z[i]++;
        }
    }

    return z;
}

// Complexidade: O(n)
vector<int> z_function(const string& s){
    int n = s.size();
    vector<int> z(n, 0);

    int L = 0, R = 0;
    for(int i=1;i<n;i++){
        if(i <= R){
            z[i] = min(z[i - L], R - i + 1);
        }

        while(i + z[i] < n && s[z[i]] == s[i + z[i]]){
            z[i]++;
        }

        if(R < i + z[i] - 1){
            L = i;
            R = i + z[i] - 1;
        }
    }

    return z;
}

// match com |


int main(){

    string pat = "caco";
    string rpat = pat; reverse(rpat.begin(), rpat.end());
    string text = "cabococacoto";
    string rtext = text; reverse(rtext.begin(), rtext.end());
    string s = pat + '#' + text;
    string rs = rpat + '#' + rtext;

    //vector<int> z = naive_z_function(s);
    vector<int> z = z_function(s);
    vector<int> rz = z_function(rs);

    for(int i=0;i<z.size();i++){
        cout << z[i] << " ";
    }cout << endl;
    for(int i=0;i<rz.size();i++){
        cout << rz[i] << " ";
    }cout << endl;

    int counter = 0;
    for(int i=0;i<z.size();i++){
        int n = text.size();
        int m = pat.size();

        int z_idx = i;
        int rz_idx = n + m - z_idx + 2;

        int sum = z[z_idx] + rz[rz_idx];

        if(sum == 2 * m){
            cout << "Match exato em " << z_idx << endl;
            counter++;
        }
        if(sum == m - 1){
            cout << "Match inexato em " << z_idx << endl;
            counter++;
        }
    }

    cout << "counter: " << counter << endl;
    return 0;
}
