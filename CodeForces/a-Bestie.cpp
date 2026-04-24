#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	int g=0;
	
	for (int i = 0; i < n; i++){
		int x;
		cin >> x;
		g = __gcd(g,x);
	}
	if (g==1)
		cout << 0 << "\n";
	else if (__gcd(g,n) == 1)
		cout << 1 << '\n';
	else if (__gcd(g,n-1) == 1){
		cout << "2\n";
	}
	else 
		cout << "3\n";
	
		
}

int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
