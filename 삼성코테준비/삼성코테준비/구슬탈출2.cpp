//
//  구슬탈출2.cpp
//  삼성코테준비
//
//  Created by 김다원 on 2020/08/31.
//  Copyright © 2020 김다원. All rights reserved.
//

#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int n, m, result = 0;
int rx, ry, bx, by;
char map[11][11];
bool visited[11][11][11][11];

int dx[4] = {0, 1, 0, -1}; //오른, 아래, 왼, 위
int dy[4] = {1, 0, -1, 0};

int moving_marble(){
    queue<pair<pair<int, int>, pair<int, int>>> pos;
    pos.push({{rx, ry}, {bx, by}});
    visited[rx][ry][bx][by] = true;
    
    while(!pos.empty()){
        long size = pos.size(); //pair로 만든 배열 있으면 long으로 쓰기
        
        while(size--){
            rx = pos.front().first.first;
            ry = pos.front().first.second;
            bx = pos.front().second.first;
            by = pos.front().second.second;
            pos.pop();
            
            //현재 빨간 공이 있는 곳이 구멍인데 파란 공은 구멍이 아닐 경우 게임 성공, 끝!
            if(map[rx][ry] == 'O' && map[rx][ry] != map[bx][by])
                return result;
            
            /* 이 조건은 있으나 없으나 메모리, 시간 비슷해
             else if(map[rx][ry] == 'O' && map[rx][ry] == map[bx][by])
                return -1;
             */
            
            for(int i=0; i<4; i++){
                int rnx = rx, rny = ry, bnx = bx, bny = by;
                //다음에 갈 곳이 벽이거나 현재 있는 곳이 구멍이면 while문 빠져 나와
                while(map[rnx + dx[i]][rny + dy[i]] != '#' && map[rnx][rny] != 'O'){
                    rnx += dx[i];
                    rny += dy[i];
                }
                while(map[bnx + dx[i]][bny + dy[i]] != '#' && map[bnx][bny] != 'O'){
                    bnx += dx[i];
                    bny += dy[i];
                }
                
                //빨간 공과 파란 공이 겹치면 더 많이 움직인 공을 한 칸 뒤로 보내
                if(rnx == bnx && rny == bny){
                    //대신 빨간 공(파란 공) 자리가 구멍이면 따질 필요 없어 continue; -> 둘 다 구멍에 빠졌으니까
                    if(map[rnx][rny] == 'O') continue;
                    if(abs(rnx - rx)+abs(rny - ry) < abs(bnx - bx)+abs(bny - by)){
                        bnx -= dx[i];
                        bny -= dy[i];
                    }
                    else{
                        rnx -= dx[i];
                        rny -= dy[i];
                    }
                }
                
                //이미 해봤던 자리니까 다시 안해봐도 결과 알아 continue; 이걸 써야 메모리도 줄이고, 시간도 단축된다
                if(visited[rnx][rny][bnx][bny]) continue;
                pos.push({{rnx, rny}, {bnx, bny}});
                visited[rnx][rny][bnx][bny] = true;
            }
        }//이 사이클마다 한 번 움직인 거야
        
        if(result == 10)
            return -1; //11번 움직인 게 될 경우
        result++;
    }
    return -1; //더 이상 움직일 곳이 없는데 구멍에 안 빠지거나, 둘 다 구멍에 빠진 경우
}
int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
            if(map[i][j] == 'R'){
                rx = i;
                ry = j;
            }
            else if(map[i][j] == 'B'){
                bx = i;
                by = j;
            }
        }
    }

    cout << moving_marble() << endl;
    
    return 0;
}
