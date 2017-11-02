#include <bits/stdc++.h>
#define INF 1 << 25

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

int main(){
	int n;
	cin >> n;

	unsigned int m[30][30];

	for(int xx=1;xx<=n;xx++){
    for(int i=0;i<30;i++)
      for(int j=0;j<30;j++)
        m[i][j] = INF;

		int no;
		scanf("%d\n", &no);

		for(int j=0;j<no-1;j++){
			string a, b;
			int peso;
			cin >> a >> b >> peso;

      int aa = a[0] - 'A', bb = b[0] - 'A';

      m[aa][bb] = peso;
      m[bb][aa] = peso;
		}

		vector<int> v;

		queue<ii> q;
		q.push(ii(0,-1));

		while(not q.empty()){
			ii cur = q.front();
			q.pop();

			v.push_back(cur.first);

			for(int x=0;x<26;x++){
				if(cur.first == x || cur.second == x || m[cur.first][x] == INF) continue;

				q.push(ii(x, cur.first));
			}
		}

		v.push_back(0);

		for(int k=0;k<26;k++)
			for(int i=0;i<26;i++)
				for(int j=0;j<26;j++)
					m[i][j] = min((unsigned int)(m[i][j]), (unsigned int)(m[i][k] + m[k][j]));

		int soma = 0;
		for(int i=0;i<v.size() - 1; i++){
			soma += m[v[i]][v[i+1]];	
		}

		printf("Trilha #%d:\n", xx);
		printf("Deslocamento total: %d\n", soma);
		printf("\n");
	}

	return 0;
}
