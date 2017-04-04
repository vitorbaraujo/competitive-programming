#include <bits/stdc++.h>

using namespace std;

int main(){
  string a, b;
  cin >> a >> b;

  int fr[1000];
  memset(fr, 0, sizeof fr);
  map<char,char> m;
  set< pair<char, char> > res;

  int tam = a.size();

  for(int i=0;i<tam;i++){
    if((fr[a[i]] and m[a[i]] != b[i]) or (fr[b[i]] and m[b[i]] != a[i])){
      cout << -1 << endl;
      return 0;
    }
    m[a[i]] = b[i];
    m[b[i]] = a[i];

    if(a[i] != b[i])
      res.insert(make_pair(min(a[i], m[a[i]]), max(a[i], m[a[i]])));

    fr[a[i]]++;
    fr[b[i]]++;
  }

  cout << res.size() << endl;
  for(auto c : res){
    cout << c.first << " " << c.second << endl;
  }

  return 0;
}
