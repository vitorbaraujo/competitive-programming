#include <bits/stdc++.h>

using namespace std;

#define INF 1e9 + 10

int main(){
	int n, test = 0;

	cin >> n;
	while(n--){
		int c;
		int soma = 0, num, res = 0;
		vector<int> v;

		cin >> c;
		while(c--){
			cin >> num;
			v.push_back(num);
		}
		v.push_back(INF);

		sort(v.begin(), v.end());
		for(unsigned i = 0; i < v.size(); ++i){
			if(v[i] > soma + 1){
				res = soma + 1; break;
			}
			soma += v[i];
		}

		printf("Conjunto #%d: %d\n\n", ++test, res);
	}


	return 0;
}
