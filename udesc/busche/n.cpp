#include <bits/stdc++.h>
#define MAX 100010

using namespace std;

int main(){
	int n;
	cin >> n;

	map<int, int> m;

	while(n--){
		int p;
		scanf("%d", &p);
		
		for(int i=0;i<p;i++){
			int v;
			scanf("%d", &v);
			m[v]++;
		}
	}

	map<int,int>::iterator it;

	for(it = m.begin(); it != m.end(); it++){
		if((*it).second <= 3) continue;
		printf("Placa: %04d tem: %d infracoes!", (*it).first, (*it).second);

		if((*it).second >= 10) printf(" (NINGUEM MERECE)\n");
		else printf("\n");
	}

	return 0;
}
