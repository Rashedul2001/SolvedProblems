#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		string str;
		cin >> str;
		int cnt = 0;
		for (auto i : str){
			cnt += (i=='1');
		}
		if (cnt >= k+1 and n >= 2*k){
			cout << "Bob\n";
		}
		else
			cout << "Alice\n";
	}
	return 0;
}