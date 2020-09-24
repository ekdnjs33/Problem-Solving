//
//  bj15683.cpp
//  삼성 sw
//
//  Created by 김다원 on 2020/04/19.
//  Copyright © 2020 김다원. All rights reserved.
//

/* 감시, 완전탐색 = 브루트포스 */
#include <iostream>
#include <vector>
#include <algorithm> //min 사용
using namespace std;

typedef struct{
    int y, x; //x 가로, y 세로
}Dir;

Dir moveDir[4] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}}; //오른, 위, 왼, 아래

int n, m;
int map[8][8], copyMap[8][8];
vector<pair<int, int>> camera;
vector<int> angle; //각각의 카메라가 보는 각도 저장
bool visit[8][8][4];
int result = 100;

//기존 사무실 복사
void copy(void){
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            copyMap[i][j] = map[i][j];
}

//사각지대 구역 개수 세기
int numOfBlindSpot(){
    int result = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (copyMap[i][j] == 0)
                result++;
    return result;
}

void DFS(int cnt){ //모든 경우의 수
    if (cnt == camera.size()){ //마지막 카메라까지 끝이면
        for (int i = 0; i < angle.size(); i++){
            int y = camera[i].first; //각각의 카메라 위치
            int x = camera[i].second;
            
            for (int j = 0; j < 4; j++) //4가지 방향
                if (visit[y][x][j]){ //볼 수 있는 방향이 맞으면
                    int nextY = y + moveDir[(angle[i] + j) % 4].y; //angle(카메라 방향)쪽으로 다음 좌표 설정
                    int nextX = x + moveDir[(angle[i] + j) % 4].x;
                    
                    while (1){ //벽에 부딪히기 전까지 쭉 보임을 표시
                        if (copyMap[nextY][nextX] == 6) //벽
                            break;
        
                        if (!(0 <= nextY && nextY < n && 0 <= nextX && nextX < m)) //범위 초과
                            break;
                        
                        if (copyMap[nextY][nextX] == 0) //더 이상 사각지대가 아님
                            copyMap[nextY][nextX] = -1;
                        
                        nextY += moveDir[(angle[i] + j) % 4].y;
                        nextX += moveDir[(angle[i] + j) % 4].x;
                    }
                }
        }
        result = min(result, numOfBlindSpot());
        copy();
        return;
    }
    
    for (int i = 0; i < 4; i++){ //4가지 방향
        angle.push_back(i);
        DFS(cnt + 1);
        angle.pop_back();
    }
}
int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
            if(map[i][j] >=1 && map[i][j] <=5)
                camera.push_back({i, j}); //카메라가 있는 위치 저장
            
            switch (map[i][j]){ //카메라가 보는 곳 표시
            case 1:
                    visit[i][j][0] = true; //1곳
                    break;
            case 2:
                    visit[i][j][0] = true; //2곳
                    visit[i][j][2] = true;
                    break;
            case 3:
                    visit[i][j][0] = true; //2곳
                    visit[i][j][1] = true;
                    break;
            case 4:
                    visit[i][j][0] = true; //3곳
                    visit[i][j][1] = true;
                    visit[i][j][2] = true;
                    break;
            case 5:
                    visit[i][j][0] = true; //4곳
                    visit[i][j][1] = true;
                    visit[i][j][2] = true;
                    visit[i][j][3] = true;
                    break;
            }
        }
    }
    copy();
    DFS(0);
    cout << result << "\n";
    return 0;
}
