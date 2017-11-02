#include <bits/stdc++.h>

#define MAX 100

using namespace std;

typedef pair <int, int> ii;

int visited[MAX];
vector <int> adj[MAX];

bool dfs(int u, int color){
	if(visited[u]){
		if(visited[u]!=color) return false;
		return true;
	}
	visited[u]=color;

	bool ans=true;
	for(int i=0; i<(int)adj[u].size(); i++){
		int v=adj[u][i];

		ans &= dfs(v, (color == 1) ? 2 : 1);
	}

	return ans;
}

int main(){
	int t;

	cin >> t;

	for(int test=1; test<=t; test++){
		int n, m;
		cin >> n >> m;

		vector <ii> vc;
		while(m--){
			char a, b;
			int u, v;
			cin >> a >> b;

			u=a-'A';
			v=b-'A';
			
			vc.push_back(ii(u, v));
		}

		int k;
		cin >> k;
		while(k--){
			char a;
			int b;
			cin >> a >> b;

			int aux=a-'A';
			for(int i=0; i<(int)vc.size(); i++){
				ii x=vc[i];
				if(x.first==aux || x.second==aux)
					vc[i]=ii(-1, -1);
			}
		}

		for(int i=0; i<(int)vc.size(); i++){
			int u=vc[i].first, v=vc[i].second;
			if(u!=-1){
				adj[u].push_back(v);
				adj[v].push_back(u);
			}
		}

		bool ans = true;
		for(int i=0; i<n; i++){
			if(not visited[i]){
				ans &= dfs(i, 1);
			}
		}

		if(ans)
			printf("calabouco #%d: Gabriel e Lucas jogaram este jogo ateh o fim!\n\n", test);
		else
			printf("calabouco #%d: Gabriel e Lucas NAO completaram este jogo!\n\n", test);

		for(int i=0; i<27; i++)
			adj[i].clear();

		memset(visited, 0, sizeof visited);
	}

	return 0;
}
