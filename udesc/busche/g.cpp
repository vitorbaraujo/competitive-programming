#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	scanf("%d\n", &n);

	for(int i=0;i<n;i++){
		string s;
		getline(cin, s);
		
		double soma = 0;
	
		stringstream b(s);
		double a;

		vector<double> v;
		while(b >> a){
			v.push_back(a);
		}
		for(int i=0;i<v.size();i++){soma += v[i];}

		double media = soma / v.size();

		soma = 0;
		for(int i=0;i<v.size();i++){
			double aa = (v[i] - media) * (v[i] - media);
			soma += aa;
		}

		double desvio = soma / v.size();

		printf("Turma %d: media %.1f desvio %.1f\n", i + 1, media, sqrt(desvio));
	}
	
	return 0;
}
