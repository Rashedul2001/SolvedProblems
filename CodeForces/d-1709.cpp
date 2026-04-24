#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (auto& it : a) cin >> it;
	for (auto& it : b) cin >> it;
	bool swapped = false;
	vector<pair<int,int>> ans;
	for (int i = 0; i < n-1; i++){
		for (int j = 0; j < n-i-1; j++){
			if ( a[j] > a[j+1]){
				swapped = true;
				swap(a[j],a[j+1]);
				ans.push_back(make_pair(1,j+1));
			}
			if ( b[j] > b[j+1]){
				swapped = true;
				swap(b[j],b[j+1]);
				ans.push_back(make_pair(2,j+1));
			}
		}
		if (!swapped)
			break;
	}
	for (int i = 0; i < n; i++){
		if (a[i] > b[i]){
			ans.push_back(make_pair(3,i+1));
		}
	}
	
	cout << ans.size() << '\n';
	for (auto it : ans)
		cout << it.first << ' ' << it.second << '\n';

}

int main(){
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}

	
