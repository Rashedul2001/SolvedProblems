#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr); cout.tie(nullptr);
    int row, col;
    cin >> row >> col;
    vector<string> grid(row);
    for(auto& it : grid) cin >> it;
    vector<int> rowWallCnt(row, 0), colWallCnt(col, 0);
    int totalWallCnt= 0;
    for(int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            if (grid[i][j] == '*'){
                totalWallCnt++;
                rowWallCnt[i]++;
                colWallCnt[j]++;
            }
        }
    }
    for(int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            int destroyed = rowWallCnt[i] + colWallCnt[j];
            if (grid[i][j] == '*')
                destroyed--;
            if(destroyed == totalWallCnt){
                cout << "YES\n";
                cout << i+1 << ' ' << j + 1 << '\n';
                return 0;
            }
        }
    }
    cout << "NO\n";
    return 0;
}
