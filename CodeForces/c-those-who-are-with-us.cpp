#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n, m;
	cin >> n >> m;
	vector<vector<int>> mat(n,vector<int> (m));
	
	int mx = 0, mx_cnt = 0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> mat[i][j];
			if (mat[i][j] > mx){
				mx = mat[i][j];
				mx_cnt = 1;
			}
			else if (mat[i][j] == mx){
				mx_cnt++;
			}
		}
	}
	vector<int> r(n, 0), c(m, 0);
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (mx == mat[i][j]){
				r[i]++;
				c[j]++;
			}
		}
	}
	bool flag = 0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (r[i] + c[j] - (mat[i][j] == mx) == mx_cnt){
				flag = 1;
			}
		}
	}
	cout << mx - flag << '\n';


	
	

	
		
}	
	

				


int main(){
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
