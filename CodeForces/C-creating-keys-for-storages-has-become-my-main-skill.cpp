#include<bits/stdc++.h>
uisng namespace std;

int main(){
    int tt;
    cin >> tt;
    while(tt--){
        int n, x;
        cin >> n >> x;
        vector<int> ans(n,x);
        int currNum = 0;
        for (int i = 0; i < n-1; i++){
            if (currNum 
