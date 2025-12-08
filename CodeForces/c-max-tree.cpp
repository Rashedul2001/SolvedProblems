#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;

	vector<int> adj[n];
	vector<int> indegree(n,0);
	
	int u,v,x,y;
	for (int i = 0; i < n-1; i++){
		cin >> u >> v >> x >> y;
		u--; v--;
		
		if(x > y){
			adj[u].push_back(v);
			indegree[v]++;
		}
		else{
			adj[v].push_back(u);
			indegree[u]++;
		}
	}
	queue<int> q;
	for (int i = 0; i <n ; i++){
		if (indegree[i] == 0){
			q.push(i);
		}
	}
	vector<int> ans;
	while(!q.empty()){
		int node =q.front();
		q.pop();
		ans.push_back(node);
		for(auto it : adj[node]){
			indegree[it]--;
			if (indegree[it] == 0){
				q.push(it);
			}
		}
	}
	
	vector<int> vec(n);
	int k = 0;
	for (int i = n; i>= 1; i--){
		vec[ans[k++]] = i;
	}
	for (auto it : vec){
		cout << it << ' ';
	}
	cout << '\n';

}
		
	

int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}