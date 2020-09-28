//
//  낚시왕.cpp
//  삼성코테준비
//
//  Created by 김다원 on 2020/09/25.
//  Copyright © 2020 김다원. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct sharkInfo{
    int num;
    int r, c;
    int s;
    int d;
    int z;
};

int R, C, M, Res = 0;
vector<int> map[101][101];
vector<sharkInfo> shark;
int dx[5] = {0, -1, 1, 0, 0};
int dy[5] = {0, 0, 0, 1, -1};

bool checking(){
    for(int i=0; i<shark.size(); i++){
        if (shark[i].z != 0)
            return false;
    }
    return true;
}
void fishing(int idx){
    for(int i=1; i<=R; i++){
        if(map[i][idx].size() != 0){
            Res = Res + shark[map[i][idx][0]].z;
            shark[map[i][idx][0]].z = 0;
            map[i][idx].clear();
            break;
        }
    }
}
void moving(){
    for(int i=0; i<shark.size(); i++){
        if (shark[i].z == 0) continue;
        int x = shark[i].r;
        int y = shark[i].c;
        map[x][y].clear();
    }
 
    for (int i=0; i<shark.size(); i++){
        if (shark[i].z == 0) continue;
        int x = shark[i].r;
        int y = shark[i].c;
        int direct = shark[i].d;
        int speed = shark[i].s;
 
        if (direct == 1 || direct == 2){
            int rotate = (R - 1) * 2;
            if (speed >= rotate)
                speed = speed % rotate;
 
            for(int j=0; j<speed; j++){
                int nx = x + dx[direct];
                int ny = y + dy[direct];
                
                if (nx < 1){
                    direct = 2;
                    nx = nx + 2;
                }
                if (nx > R){
                    direct = 1;
                    nx = nx - 2;
                }
                x = nx;
                y = ny;
            }
        }
        else{
            int rotate = (C - 1) * 2;
            if(speed >= rotate)
                speed = speed % rotate;
 
            for(int j=0; j<speed; j++){
                int nx = x + dx[direct];
                int ny = y + dy[direct];
                
                if (ny < 1){
                    direct = 3;
                    ny = ny + 2;
                }
                if (ny > C){
                    direct = 4;
                    ny = ny - 2;
                }
                x = nx;
                y = ny;
            }
        }
        
        shark[i].r = x;
        shark[i].c = y;
        shark[i].d = direct;
        map[x][y].push_back(i);
    }
}
void kill(){
    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            if (map[i][j].size() > 1){
                sort(map[i][j].begin(), map[i][j].end());
                int live_idx = map[i][j][0];
                
                for(int k=1; k<map[i][j].size(); k++){
                    shark[map[i][j][k]].z = 0;
                    shark[map[i][j][k]].r = -1;
                    shark[map[i][j][k]].c = -1;
                }
                
                map[i][j].clear();
                map[i][j].push_back(shark[live_idx].num);
            }
        }
    }
}

int main(){
    cin >> R >> C >> M;
    for(int i=0; i<M; i++){
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;
        shark.push_back({ i,r,c,s,d,z });
        map[r][c].push_back(i);
    }
    
    if (M == 0){
        cout << 0 << endl;
        return 0;
    }
    for (int i=1; i<=C; i++){
        if (checking() == true)
            break;
        fishing(i);
        moving();
        kill();
    }
    cout << Res << endl;
    return 0;
}
