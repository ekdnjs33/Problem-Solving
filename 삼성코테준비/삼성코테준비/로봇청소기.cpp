//
//  로봇청소기.cpp
//  삼성코테준비
//
//  Created by 김다원 on 2020/08/27.
//  Copyright © 2020 김다원. All rights reserved.
//

#include <iostream>
using namespace std;

int n, m, r, c, d, result = 0; // (r, c): 현재 위치, d: 현재 방향
int map[51][51];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void cleaning(){
    if(map[r][c] == 0){
        result++;
        map[r][c] = 2;
    }
    
    int nr, nc;
    if(map[r+dx[0]][c+dy[0]] != 0 && map[r+dx[1]][c+dy[1]] != 0 && map[r+dx[2]][c+dy[2]] != 0 && map[r+dx[3]][c+dy[3]] != 0){
        nr = r + dx[(2+d)%4];
        nc = c + dy[(2+d)%4];
        
        if(map[nr][nc] == 1)
            return;
        else{
            r = nr;
            c = nc;
        }
    }else{
        nr = r + dx[(d+3)%4];
        nc = c + dy[(d+3)%4];
        
        if(map[nr][nc] == 0){
            d = (d + 3) % 4;
            r = nr;
            c = nc;
        }
        else if(map[nr][nc] != 0){
            d = (d + 3) % 4;
        }
    }
    cleaning();
}
int main(){
    cin >> n >> m;
    cin >> r >> c >> d;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
        }
    }
    
    cleaning();
    cout << result << endl;
    
    return 0;
}
