//
//  테트로미노.cpp
//  삼성코테준비
//
//  Created by 김다원 on 2020/08/29.
//  Copyright © 2020 김다원. All rights reserved.
//

#include <iostream>
using namespace std;

int n, m, max_val = 0;
int map[501][501];
bool visited[501][501];

int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

void dfs1(int x, int y, int cnt, int sum){
    if(cnt == 0){
        max_val = max(max_val, sum);
        return;
    }
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && ny >= 0 && nx < n && ny < m && !visited[nx][ny]){
            visited[nx][ny] = true;
            dfs1(nx, ny, cnt - 1, sum + map[nx][ny]);
            visited[nx][ny] = false;
        }
    }
}
void tetromino(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            visited[i][j] = true;
            dfs1(i, j, 3, map[i][j]);
            visited[i][j] = false;
        }
    }
    for(int i=0; i<n-3; i++){
        for(int j=0; j<m; j++){
            int sum = map[i][j]+map[i+1][j]+map[i+2][j];
            if(j == 0)
                max_val = max(max_val, sum+map[i+1][j+1]);
            else if(j == m-1)
                max_val = max(max_val, sum+map[i+1][j-1]);
            else{
                max_val = max(max_val, sum+map[i+1][j-1]);
                max_val = max(max_val, sum+map[i+1][j+1]);
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m-3; j++){
            int sum = map[i][j]+map[i][j+1]+map[i][j+2];
            if(i == 0)
                max_val = max(max_val, sum+map[i+1][j+1]);
            else if(i == n-1)
                max_val = max(max_val, sum+map[i-1][j+1]);
            else{
                max_val = max(max_val, sum+map[i-1][j+1]);
                max_val = max(max_val, sum+map[i+1][j+1]);
            }
        }
    }
}
int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
        }
    }
    
    tetromino();
    cout << max_val << endl;
    
    return 0;
}
