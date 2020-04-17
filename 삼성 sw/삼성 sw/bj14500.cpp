//
//  bj14500.cpp
//  삼성 sw
//
//  Created by 김다원 on 2020/04/16.
//  Copyright © 2020 김다원. All rights reserved.
//

/* 테트로미노, 'ㅗ' 모양 빼고 나머지는 DFS로 푸는 문제 */
#include <iostream>
using namespace std;

int n, m;
int dx[4] = {0, 1, 0, -1}; //세로(오른, 아래, 왼, 위)
int dy[4] = {1, 0, -1, 0}; //가로
int arr[501][501];
bool visit[501][501];
int Max = 0;
void DFS(int x, int y, int cnt, int sum){
    if(cnt == 0){
        if(sum > Max)
            Max = sum;
        return;
    }
    for(int i=0; i<4; i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx >= 0 && ny >= 0 && nx < n && ny < m && !visit[nx][ny]){
            visit[nx][ny] = true;
            DFS(nx, ny, cnt-1, sum+arr[nx][ny]);
            visit[nx][ny] = false;
        }
    }
}
int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> arr[i][j];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            visit[i][j] = true;
            DFS(i, j, 3, arr[i][j]);
            visit[i][j] = false;
        }
    }
    for(int i=0; i<n-1; i++){
        for(int j=0; j<m-2; j++){
            int a = arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i+1][j+1];
            if(a > Max)
                Max = a;
        }
    }
    for(int i=n-1; i>0; i--){
        for(int j=0; j<m-2; j++){
            int a = arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i-1][j+1];
            if(a > Max)
                Max = a;
        }
    }
    for(int i=0; i<n-2; i++){
        for(int j=0; j<m-1; j++){
            int a = arr[i][j] + arr[i+1][j] + arr[i+2][j] + arr[i+1][j+1];
            if(a > Max)
                Max = a;
        }
    }
    for(int i=0; i<n-2; i++){
        for(int j=m-1; j>0; j--){
            int a = arr[i][j] + arr[i+1][j] + arr[i+2][j] + arr[i+1][j-1];
            if(a > Max)
                Max = a;
        }
    }
    cout << Max << "\n";
}
