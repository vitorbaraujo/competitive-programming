#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;

	cin >> n;

	for(int i=0; i<n; i++){
		int a, b, c;
		cin >> a >> b >> c;

		printf("Conjunto: %d %d %d\n", a, b, c);
		for(int j=0; j<c; j++){
			if(a<b)
				b/=2;
			else
				a/=2;
		}

		printf("%d %d\n\n", max(a, b), min(a, b));
	}

	return 0;
}
