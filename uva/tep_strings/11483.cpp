#include <bits/stdc++.h>

using namespace std;

string parse(string s){
    string res = "";
    for(int i=0;i<s.size();i++){
        if(s[i] == '\\' || s[i] == '\"'){
            res += '\\'; 
        }
        res += s[i];
    }

    return res;
}

int main(){
    int n, x = 1;
    string s;

    while(scanf("%d\n", &n), n){
        vector<string> v;
        for(int i=0;i<n;i++){
            getline(cin, s);
            v.push_back(s);
        }

        printf("Case %d:\n", x++);
        printf("#include<string.h>\n#include<stdio.h>\nint main()\n{\n");

        for(auto c : v){
            string res = parse(c);

            printf("printf(\"%s\\n\");\n", res.c_str()); 
        }

        printf("printf(\"\\n\");\nreturn 0;\n}\n");
    }

    return 0;
}
