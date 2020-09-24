//
//  bj16234.cpp
//  삼성 sw
//
//  Created by 김다원 on 2020/04/29.
//  Copyright © 2020 김다원. All rights reserved.
//

/* 인구 이동 */
#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int n, l, r, cnt = 0, num_cnt, sum;
int map[51][51];
int check[51][51];
int dx[4] = {0, 1, 0, -1}; //오른, 아래, 왼, 위
int dy[4] = {1, 0, -1, 0};
queue<pair<int, int>> q;
queue<pair<int, int>> position;

//초기화
void init(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            check[i][j] = 0;
    }
}

//열린 국경선 체크
void checking(int num){
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if(check[x][y] != 0) continue;
        check[x][y] = num;
        position.push({x, y});
        sum += map[x][y];
        num_cnt++;
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0  && ny >= 0  && nx < n && ny < n){
                if(check[nx][ny] == 0){
                    int val = abs(map[x][y] - map[nx][ny]);
                    if(val >= l  && val <= r)
                        q.push({nx, ny});
                }
            }
        }
    }
}
//인구 이동
void moving(){
    sum = sum/num_cnt;
    while(!position.empty()){
        int px = position.front().first;
        int py = position.front().second;
        map[px][py] = sum;
        position.pop();
    }
}

int main(){
    cin >> n >> l >> r;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> map[i][j];
        }
    }
    while(true){
        int num = 0;
        init();
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(check[i][j] == 0){
                    num_cnt = 0;
                    sum = 0;
                    q.push({i, j});
                    num++;
                    checking(num);
                    moving();
                }
            }
        }
        if(num == n*n) break;
        cnt++;
    }
    cout << cnt << "\n";
    return 0;
}
