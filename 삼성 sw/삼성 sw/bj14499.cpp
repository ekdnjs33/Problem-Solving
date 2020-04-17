//
//  bj14499.cpp
//  삼성 sw
//
//  Created by 김다원 on 2020/04/17.
//  Copyright © 2020 김다원. All rights reserved.
//

/* 주사위 굴리기 */
#include <iostream>
using namespace std;

int n, m, x, y, k;
int map[21][21];
int dice[7];
int dx[5] = {0, 0, 0, -1, 1}; //세로
int dy[5] = {0, 1, -1, 0, 0}; //가로
int main(){
    cin >> n >> m >> x >> y >> k;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> map[i][j];
    
    dice[1] = map[x][y];
    for(int i=0; i<k; i++){
        int a, temp, nx, ny;
        cin >> a;
        nx = x+dx[a];
        ny = y+dy[a];
        if(nx >= 0 && ny >= 0 && nx < n && ny < m){
            x = nx;
            y = ny;
            if(a == 1){ //동쪽으로
                temp = dice[4];
                dice[4] = dice[1];
                dice[1] = dice[3];
                dice[3] = dice[6];
                dice[6] = temp;
            }else if(a == 2){ //서쪽으로
                temp = dice[3];
                dice[3] = dice[1];
                dice[1] = dice[4];
                dice[4] = dice[6];
                dice[6] = temp;
            }else if(a == 3){ //북쪽으로
                temp = dice[6];
                dice[6] = dice[5];
                dice[5] = dice[1];
                dice[1] = dice[2];
                dice[2] = temp;
            }else if(a == 4){ //남쪽으로
                temp = dice[2];
                dice[2] = dice[1];
                dice[1] = dice[5];
                dice[5] = dice[6];
                dice[6] = temp;
            }
            if(map[x][y] == 0)
                map[x][y] = dice[1];
            else{
                dice[1] = map[x][y];
                map[x][y] = 0;
            }
            cout << dice[6] << "\n";
        }
    }
}
