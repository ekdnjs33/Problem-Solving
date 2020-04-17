//
//  bj13460.cpp
//  삼성 sw
//
//  Created by 김다원 on 2020/04/11.
//  Copyright © 2020 김다원. All rights reserved.
//

/* 구슬 탈출 2 */
#include <iostream> //입출력 사용
#include <queue> //큐 사용
#include <utility> //pair 사용
#include <cmath> //abs 사용
using namespace std;

int N, M;
int dx[4] = {0, 1, 0, -1}; //오른, 아래, 위, 왼 (x가 세로, y가 가로)
int dy[4] = {1, 0, -1, 0};
char map[11][11];
bool visit[11][11][11][11];
int rx, ry, bx, by; //공 위치 기억

int bfs(){
    queue<pair<pair<int, int>, pair<int, int>>> q;
    q.push(make_pair(make_pair(rx, ry), make_pair(bx, by)));
    visit[rx][ry][bx][by] = true;
    int result = 0;
    
    while(!q.empty()){
        long size = q.size();
        while(size--){
            int rxx = q.front().first.first;
            int ryy = q.front().first.second;
            int bxx = q.front().second.first;
            int byy = q.front().second.second;
            
            q.pop();
            if(map[rxx][ryy] == 'O' && map[rxx][ryy] != map[bxx][byy]){
                return result;
            }
            
            for(int i=0; i<4; i++){
                int rnx = rxx, rny = ryy, bnx = bxx, bny = byy;
                while(map[rnx + dx[i]][rny + dy[i]] != '#' && map[rnx][rny] != 'O'){
                    rnx += dx[i];
                    rny += dy[i];
                }
                while(map[bnx + dx[i]][bny + dy[i]] != '#' && map[bnx][bny] != 'O'){
                    bnx += dx[i];
                    bny += dy[i];
                }
                if(rnx == bnx && rny == bny){
                    if(map[rnx][bny] == 'O') continue;
                    if(abs(rnx - rxx) + abs(rny - ryy) < abs(bnx - bxx) + abs(bny - byy)){
                        bnx -= dx[i];
                        bny -= dy[i];
                    }
                    else{
                        rnx -= dx[i];
                        rny -= dy[i];
                    }
                }
                if(visit[rnx][rny][bnx][bny]) continue;
                q.push(make_pair(make_pair(rnx, rny), make_pair(bnx, bny)));
                visit[rnx][rny][bnx][bny] = true;
            }
        }
        if(result == 10) return -1;
        result++;
    }
    return -1;
}
int main(){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            char k;
            cin >> k;
            if(k == 'R'){
                rx = i;
                ry = j;
            }
            else if(k == 'B'){
                bx = i;
                by = j;
            }
            map[i][j] = k;
        }
    }
    cout << bfs() << "\n";
    return 0;
}

