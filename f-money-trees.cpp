#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n,k, ans = 0;
	cin >> n >> k;
	vector<int> a(n), h(n);
	for (auto& it : a) cin >> it;
	for (auto& it : h) cin >> it;
	
	for (int i = 0; i < n; i++){
		int j = i;
		while(j + 1 < n and h[j] % h[j + 1] == 0)
			j++;
		int left = i;
		long long currentSum = 0;
		for (int right = left; right <= j; right++){
			currentSum += a[right];
			while(currentSum > k){
				currentSum -= a[left];
				left++;
			}
			ans = max(ans, right-left+1);
		}
		i = j;
	}
	cout << ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);cout.tie(nullptr);
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
		
