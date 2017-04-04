#include <bits/stdc++.h>

using namespace std;
using ii = pair<int,int>;

int main(){
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);

  int cont = 1;
  for(int i=0;cont <= n;i+=2, cont++){
    int ini = i * m + 1;
    int fim = (i + 2) * m;

    if(ini <= k and k <= fim){
      int cont2 = 1;
      for(int j=ini;j<=fim;j+=2){
        if(k == j or k == j+1) break;
        cont2++;
      }
  
      cout << cont << " " << cont2 << " ";

      if(k%2 != 0) cout << "L";
      else cout << "R";
      cout << endl;
    }
  }

  return 0;
}
