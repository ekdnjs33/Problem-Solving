//
//  감시.cpp
//  삼성코테준비
//
//  Created by 김다원 on 2020/09/02.
//  Copyright © 2020 김다원. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

struct Dir{
    int x, y;
};
Dir moveDir[4] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};

int n, m, min_val = 100;
int map[8][8], new_map[8][8];
vector<pair<int, int>> cctv;
vector<int> angle; //각각의 카메라가 보는 각도 저장
int visit[8][8][4];

void copy_map(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            new_map[i][j] = map[i][j];
        }
    }
}
void detection(int cnt){
    if(cnt == cctv.size()){
        for (int i=0; i<angle.size(); i++){
            int x = cctv[i].first;
            int y = cctv[i].second;
            
            for (int j=0; j<4; j++){
                if (visit[x][y][j]){ //4가지 중 볼 수 있는 방향이 맞으면
                    int nx = x + moveDir[(angle[i] + j) % 4].x;
                    int ny = y + moveDir[(angle[i] + j) % 4].y; //angle(카메라 방향)쪽으로 다음 좌표 설정
                    
                    while(1){ //벽에 부딪히기 전까지 쭉 보인다
                        if (new_map[nx][ny] == 6)
                            break;
        
                        if (nx < 0 || ny < 0 || nx >= n || ny >= m) //범위 초과
                            break;
                        
                        if (new_map[nx][ny] == 0) //더 이상 사각지대가 아님
                            new_map[nx][ny] = -1;
                        
                        nx += moveDir[(angle[i] + j) % 4].x;
                        ny += moveDir[(angle[i] + j) % 4].y;
                    }
                }
            }
        }
        
        int result = 0;
        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++)
                if (new_map[i][j] == 0)
                    result++;
        min_val = min(min_val, result);
        
        copy_map();
        return;
    }
    
    for (int i=0; i<4; i++){ //4가지 방향
        angle.push_back(i);
        detection(cnt + 1);
        angle.pop_back();
    }
}
int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
            if(map[i][j] > 0 && map[i][j] < 6)
                cctv.push_back({i, j});
            
            switch (map[i][j]){ //카메라가 볼 수 있는 곳 표시
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
    
    copy_map();
    detection(0);
    cout << min_val << endl;
    
    return 0;
}
