#include <bits/stdc++.h>

#define MAX 6000

using namespace std;

int adj[MAX][5], memo[MAX];

typedef pair <int, int> ii;

void insert(int cur, int node){
	if(node < cur){
		if(adj[cur][0]==-1)
			adj[cur][0]=node;
		else
			insert(adj[cur][0], node);
	}else{
		if(adj[cur][1]==-1)
			adj[cur][1]=node;
		else
			insert(adj[cur][1], node);
	}
}

int dfs(int u){
	int ans=0;
	for(int i=0; i<2; i++){
		int v=adj[u][i];
		if(v!=-1)
			ans=max(ans, dfs(v)+1);
	}

	return memo[u]=ans;
}

int main(){
	int n;

	cin >> n;


	for(int test=1; test<=n; test++){
		memset(adj, -1, sizeof adj);
		memset(memo, 0, sizeof memo);

		int f;
		cin >> f;

		int root;
		cin >> root;

		vector <int> in;
		in.push_back(root);

		for(int h=2; h<=f; h++){
			int num;
			cin >> num;

			in.push_back(num);

			insert(root, num);
		}

		dfs(root);

		int g=0;
		int ans[MAX];

		memset(ans, 0, sizeof ans);

		for(int i=0; i<MAX; i++){
			int a=0;
			if(adj[i][0]!=-1)
				a=memo[adj[i][0]]+1;

			int b=0;
			if(adj[i][1]!=-1)
				b=memo[adj[i][1]]+1;

			ans[i]=abs(a-b);
			g=max(g, ans[i]);
		}

//		cout << ans[19] << endl;
//		cout << adj[16][1] << endl;
//		return 0;
//		cout << memo[4] << endl << memo[14] << endl;
//		return 0;

//		cout << ans[66] << endl << ans[67] << endl;
//		for(int i=(int)in.size()-1; i>=0; i--){
		for(int i=0; i<(int)in.size(); i++){
//			cout << "b: " << in[i] << endl;
			if(ans[in[i]]==g){
				printf("Bando #%d: %d\n\n", test, in[i]);
//				cout << in[i] << endl;
				break;
			}
		}
	}

	return 0;
}
