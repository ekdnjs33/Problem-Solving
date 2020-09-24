//
//  아기상어.cpp
//  삼성코테준비
//
//  Created by 김다원 on 2020/09/04.
//  Copyright © 2020 김다원. All rights reserved.
//

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, eat = 0, sharkx, sharky, size = 2;
int min_time, min_x, min_y, res = 0;
int map[21][21];
int visit[21][21];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void init(){
    min_time = 401;
    min_x = 21;
    min_y = 21;
    
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            visit[i][j] = -1;
}
void bfs(int x, int y){
    queue<pair<int, int>> q;
    visit[x][y] = 0;
    q.push({x, y});
    
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            //1)이미 방문했거나, 2)상어의 크기보다 큰 물고기인 경우 건너뛴다.
            if(visit[nx][ny] != -1 || map[nx][ny] > size) continue;
            //(nx, ny)에 있는 물고기까지의 이동거리를 갱신
            visit[nx][ny] = visit[x][y] + 1;
            
            // 먹을 수 있는 물고기일 경우
            if(map[nx][ny] > 0 && map[nx][ny] < size){
                // 만약 현재 물고기 까지의 이동시간이 더 짧은 경우
                if(min_time > visit[nx][ny]){
                    min_x = nx;
                    min_y = ny;
                    min_time = visit[nx][ny];
                }
                // 만약 현재 물고기 까지의 이동시간은 같으면 1) 가장 위쪽, 가장 왼쪽을 찾습니다.
                else if(min_time == visit[nx][ny]){
                    if(min_x == nx){ //위쪽이 같으면
                        if(min_y > ny){ //가장 왼쪽
                            min_x = nx;
                            min_y = ny;
                        }
                    }
                    else if(min_x > nx){
                        min_x = nx;
                        min_y = ny;
                    }
                }
            }
            // 물고기의 위치를 큐에 넣어줍니다.
            q.push({nx, ny});
        }
    }
}
int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> map[i][j];
            if(map[i][j] == 9){
                map[i][j] = 0;
                sharkx = i;
                sharky = j;
            }
        }
    }
    
    while(1){
        init();
        //먹을 수 있는 물고기 찾기
        bfs(sharkx, sharky);
      
        //먹을 수 있는 물고기를 찾은 경우
        if(min_x != 21 && min_y != 21){
            res += visit[min_x][min_y];
            eat++;
            
            if(eat == size){
                size++;
                eat = 0;
            }
            
            map[min_x][min_y] = 0;
            sharkx = min_x;
            sharky = min_y;
        }
        else
            break;
    }
    
    cout << res << "\n";
    
    return 0;
}
