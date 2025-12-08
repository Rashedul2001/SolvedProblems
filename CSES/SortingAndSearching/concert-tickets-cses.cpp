#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, m;
	cin >> n >> m;
	multiset<int> h;
	while(n--){
		int t;
		cin >> t;
		h.insert(t);
	}	
	while(m--){
		int t;
		cin >> t;
		auto it = h.upper_bound(t);
		if (it == h.begin()){
			cout << "-1\n";
		}
		else{
			cout << *(--it) << '\n';
			h.erase(it);
		}
	}
	return 0;
}
