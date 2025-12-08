#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,x,y,mx=0;
    cin >> n;
    vector<pair<int,int>> vec;
    while(n--){
        cin >> x >> y;
        vec.push_back({x,1});
        vec.push_back({y,-1});
    }
    sort(vec.begin(), vec.end());
    int cur = 0;
    for (auto i : vec){
        cur += i.second;
        mx = max(cur, mx);
    }

    cout << mx << '\n';
    return 0;
}

