#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    map<int,int> mp;
    map<int, vector<int>>li;
    for(int i = 0; i < n; i++){
        int d;
        cin >> d;
        mp[d]++;
        li[d].push_back(i);
    }

    int cnt = 0;
    vector<int> ans(n,1);
    for (auto it : mp){
        if (it.second % it.first != 0){
            cout << "-1\n";
            return ;
        }
        int cir = it.second / it.first;
        for (int i = 0; i < it.second; i ++){
            if(i % it.first == 0)
                cnt++;
            ans[li[it.first][i]] = cnt;
        }
        
    }
   
    for (auto it : ans){
        cout << it << ' ';
    }
    cout << '\n';

            
    
}

int main(){
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
