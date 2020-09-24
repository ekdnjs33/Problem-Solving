//
//  bj16236.cpp
//  삼성 sw
//
//  Created by 김다원 on 2020/04/27.
//  Copyright © 2020 김다원. All rights reserved.
//

/* 아기 상어 */
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int n, sharkX, sharkY, eatCnt, size = 2;
int minTime, minX, minY, res = 0;
int arr[21][21];
int check[21][21];
int dx[4] = {-1, 0, 1, 0}; //(세로)위, 왼, 아래, 오른
int dy[4] = {0, -1, 0, 1};
vector<pair<int, int>> fishPos;

void init_check(){
    minTime = 401;
    minX = 21;
    minY = 21;
    
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            check[i][j] = -1;
}

void bfs(int x, int y){
    queue<pair<int, int>> que;
    check[x][y] = 0;
    que.push({x, y});
    
    while(!que.empty()){
        x = que.front().first;
        y = que.front().second;
        que.pop();
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            //지도 밖으로 넘어갔을 경우 건너뛴다.
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            //1)이미 방문했거나, 2)상어의 크기보다 큰 물고기인 경우 건너뛴다.
            if(check[nx][ny] != -1 || arr[nx][ny] > size) continue;
            //(nx, ny)에 있는 물고기까지의 이동거리를 갱신
            check[nx][ny] = check[x][y] + 1;
            
            // 먹을 수 있는 물고기일 경우
            if(arr[nx][ny] != 0 && arr[nx][ny] < size){
                // 만약 현재 물고기 까지의 이동시간이 더 짧은 경우
                if(minTime > check[nx][ny]){
                    minX = nx;
                    minY = ny;
                    minTime = check[nx][ny];
                }
                // 만약 현재 물고기 까지의 이동시간은 같으면 1) 가장 위쪽, 가장 왼쪽을 찾습니다.
                else if(minTime == check[nx][ny]){
                    if(minX == nx){
                        if(minY > ny){
                            minX = nx;
                            minY = ny;
                        }
                    }else if(minX > nx){
                        minX = nx;
                        minY = ny;
                    }
                }
            }
            // 물고기의 위치를 큐에 넣어줍니다.
            que.push({nx, ny});
        }
    }
}
int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 9){
                sharkX = i;
                sharkY = j;
                arr[i][j] = 0;
            }
        }
    }
    while(true){
        //정보 초기화
        init_check();
        //먹을 수 있는 물고기 찾기
        bfs(sharkX, sharkY);
        //먹을 수 있는 물고기를 찾은 경우
        if(minX != 21 && minY != 21){ //여기가 왜 먹을 수 있는 물고기를 찾은 경우일까?
            res += check[minX][minY];
            eatCnt++;
            
            if(eatCnt == size){
                size++;
                eatCnt = 0;
            }
            
            arr[minX][minY] = 0;
            sharkX = minX;
            sharkY = minY;
        }
        else
            break;
    }
    cout << res << "\n";
    return 0;
}
