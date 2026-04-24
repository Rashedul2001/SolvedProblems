#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> vec(n);
		for (auto& it : vec) cin >> it;
		int start = 0, mid = n/2; 
		vector<pair<int,int>> ans;
		for (int i = mid; i < n; i++){
			if (vec[i] == 0){
				ans.push_back({mid+1,n});
				n = mid+1;
				break;
			}
		}
		for (int i = 0; i < mid; i++){
			if (vec[i] == 0){
				ans.push_back({1,mid});
				n = n-mid+1;
				break;
			}
		}
		ans.push_back({1,n});
		cout << ans.size() <<'\n';
		for (auto it : ans)
			cout << it.first  << ' ' << it.second << '\n';
		cout << '\n';
	}
	return 0;
}
		
