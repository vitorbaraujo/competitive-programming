#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	scanf("%d", &n);

	for(int i=0;i<n;i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		int d = 24 - (a + b + c);
		bool f12 = a <= 12 && b <= 12 && c <= 12 && d <= 12;
		bool fd = d >= 6;
		map<int, int> m;
		m[a]++;
		m[b]++;
		m[c]++;
		bool fz = m[0] == 1 || m[0] == 0;

		if(f12 && fd && fz) printf("adequada\n");
		else printf("nao adequada\n");
	}

	return 0;
}
