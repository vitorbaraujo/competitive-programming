#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

int main(){
	int n;
	cin >> n;

	int m[30][30];
	int cac[30];
	
	for(int i=1;i<=n;i++){
		memset(m, -1, sizeof m);
		memset(cac, -1, sizeof cac);
		
		int no;
		scanf("%d\n", &no);

		for(int j=0;j<no-1;j++){
			string a, b;
			int peso;
			cin >> a >> b >> peso;

			m[a[0] - 'A'][b[0] - 'A'] = peso;
			cac[a[0] - 'A'] = max(cac[a[0] - 'A'], b[0] - 'A');
		}

		int soma = 0;
		queue<iii> q;
		q.push(iii(0,-1,0));

		while(not q.empty()){
			iii curx = q.front();
			q.pop();

			int cur = get<0>(curx);
			int par = get<1>(curx);
			int niv = get<2>(curx);

			int h = cur ? m[par][cur] : 0;

			soma += h;

			int xgh = 1;

			for(int x=0;x<26;x++){
				if(cur == x || par == x || m[cur][x] == -1) continue;
				//soma += 2 * h * xgh;
				xgh = 0;
				soma += m[cur][x] * (cac[par] == cur ? 1 : 1); 
				cout << "soma: " << soma << endl;
				q.push(iii(x, cur, niv + 1));
				m[cur][x] += h;
			}
		}
		
		printf("Trilha #%d:\n", i);
		printf("Deslocamento total: %d\n", soma);
		printf("\n");
	}

	return 0;
}
