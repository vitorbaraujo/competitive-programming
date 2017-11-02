#include <bits/stdc++.h>

using namespace std;

int parse(string s){
    string res = "";
    for(auto c : s){
        if(isdigit(c)) res += c;
    }

    return stoi(res);
}

int merge(vector<int>& v, int low, int high){
}

int main(){
    vector<int> v;
    int n;
    string s;

    scanf("%d", &n);

    while(n--){
        cin >> s;
        v.push_back(parse(s));
    }

    count = merge(v, 0, v.size());

    return 0;
}
