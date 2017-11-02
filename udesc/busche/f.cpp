#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;

	while(n--){
		int v[15];
		for(int i=1;i<=9;i++) scanf("%d", &v[i]);

		int f[15];
		f[1] = v[1];
		f[5] = v[5];
		f[9] = v[9];
		int a = f[1];
		int b = f[5];
		int c = f[9];

		f[2] = ((a + c) * 2)%10;
		f[3] = (b * 3) % 10;
		f[4] = (a + b) % 10;
		f[6] = (c * 4) % 10;
		f[7] = (a * 8) % 10;
		f[8] = (a + b + c) % 10;

		bool ok = true;
		for(int i=1;i<=9;i++){
			if(f[i] != v[i]){
				ok = false;
				break;
			}
		}

		printf("%s\n", (ok ? "SIM" : "NAO"));
	}

	return 0;
}
