#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int, int> &a, pair<int, int> &b){
    return a.second < b.second;
}

int main(){
    int n;
    cin >> n;
    vector<pair<int,int>> vec(n);
    for(int i = 0; i < n; i++){
        cin >> vec.first >> vec.second;
    }
    sort(vec.begin(), vec.end(),cmp);
    
