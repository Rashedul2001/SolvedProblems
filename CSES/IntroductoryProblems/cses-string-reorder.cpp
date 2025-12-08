#include<bits/stdc++.h>
using namespace std;

int main(){
    string str;
    cin >> str;
    int n = str.size();
    vector<int> cnt(26, 0);
    for(auto it : str)
        cnt[it-'A']++;
    string ans;
    while(ans.size() < n){
        pair<int,int> biggest = {0, 0};
        for (int i = 0; i < 26; i++){
            if (cnt[i] > biggest.first){
                biggest = {cnt[i], biggest.first};
            }
            else if (cnt[i] > biggest.second)
                    biggest.second = cnt[i];
        }
       for (int i = 0; i < n; i++){
            if (cnt[i] > 0 and (ans.empty() or ans.back() != ('A' + i)){
                
