//
//  bj17144.cpp
//  삼성 sw
//
//  Created by 김다원 on 2020/04/22.
//  Copyright © 2020 김다원. All rights reserved.
//

/* 미세먼지 안녕 */
#include <iostream>
#include <queue>
#include <utility>
//#include <cstring> //memset 이용
using namespace std;

int r, c, t, h;
int map[51][51];
int mapCopy[51][51];
int dx[4] = {0, -1, 0, 1}; //(세로)오른, 위, 왼, 아래
int dy[4] = {1, 0, -1, 0}; //(가로)
queue<pair<int, int>> dustPosition;
queue<int> dust;

void copy(){
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
            map[i][j] = mapCopy[i][j];
    return;
}

//먼지 확산
void spread(){
    while(!dust.empty()){
        int cnt = 0;
        int total = dust.front();
        int x = dustPosition.front().first;
        int y = dustPosition.front().second;
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && ny >=0 && nx < r && ny < c){
                if(mapCopy[nx][ny] >= 0){
                    mapCopy[nx][ny] += total/5;
                    cnt++;
                }
            }
        }
        mapCopy[x][y] += total - (total/5)*cnt;
        dust.pop();
        dustPosition.pop();
    }
    copy();
}

//공기청정기 가동
void freshAir(){ //1.(h-1, 0), 2.(h, 0)
    int dustX = h-2;
    int dustY = 0;
    while(1){
        if(dustX == h-1 && dustY == 0) break;
        else if(dustX > 0 && dustY == 0){
            map[dustX][dustY] = map[dustX-1][dustY];
            dustX--;
        }else if(dustX == 0 && dustY < c-1){
            map[dustX][dustY] = map[dustX][dustY+1];
            dustY++;
        }else if(dustX < h-1 && dustY == c-1){
            map[dustX][dustY] = map[dustX+1][dustY];
            dustX++;
        }else if(dustX == h-1 && dustY > 0){
            if(map[dustX][dustY-1] == -1)
                map[dustX][dustY] = 0;
            else
                map[dustX][dustY] = map[dustX][dustY-1];
            dustY--;
        }
    }
    dustX = h+1;
    dustY = 0;
    while(1){
        if(dustX == h && dustY == 0) break;
        else if(dustX < r-1 && dustY == 0){
            map[dustX][dustY] = map[dustX+1][dustY];
            dustX++;
        }else if(dustX == r-1 && dustY < c-1){
            map[dustX][dustY] = map[dustX][dustY+1];
            dustY++;
        }else if(dustX > h && dustY == c-1){
            map[dustX][dustY] = map[dustX-1][dustY];
            dustX--;
        }else if(dustX == h && dustY > 0){
            if(map[dustX][dustY-1] == -1)
                map[dustX][dustY] = 0;
            else
                map[dustX][dustY] = map[dustX][dustY-1];
            dustY--;
        }
    }
}

int main(){
    cin >> r >> c >> t;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin >> map[i][j];
            if(map[i][j] > 0){
                dust.push(map[i][j]);
                dustPosition.push({i, j});
            }
            if(map[i][j] == -1) //공기청정기 아랫값
                h = i;
        }
    }
    
    while(t>0){
        //memset(mapCopy, 0, sizeof(mapCopy)); //0으로 전부 초기화
        mapCopy[h-1][0] = mapCopy[h][0] = -1;
        spread();
        freshAir();
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(map[i][j] > 0){
                    dust.push(map[i][j]);
                    dustPosition.push({i, j});
                }
                mapCopy[i][j] = 0;
            }
        }
        t--;
    }
    int sum = 0;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(map[i][j] > 0)
                sum += map[i][j];
        }
    }
    
    cout << sum << "\n";
    return 0;
}
