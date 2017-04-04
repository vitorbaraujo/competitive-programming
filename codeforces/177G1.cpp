#include <bits/stdc++.h>

using namespace std;

int fib(int n){
	int a = 0;
	int b = 1;
	int temp = 0;

	for(int i=0;i<n;i++){
		temp = a + b;
		a = b;
		b = temp;
	}

	return temp;
}

string sfib(int n){
	string a = "a";
	string b = "b";
	string temp = "";

	for(int i=0;i<n;i++){
		temp = a + b;
		a = b;
		b = temp;
	}

	return temp;
}

int main(){
	for(int i=0;i<=3000;i++){
		cout << sfib(i).size() << endl;
	}

	return 0;
}
