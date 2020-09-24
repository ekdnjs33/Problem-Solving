//
//  청소년상어.cpp
//  삼성코테준비
//
//  Created by 김다원 on 2020/09/21.
//  Copyright © 2020 김다원. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

int map[4][4];
vector<int, pair<pair<int, int>, int>> fish_pos;
int shark_x = 0, shark_y = 0, shark_dir = 0;

int dx[8] = {0, -1, -1, 0, 1, 1, 1, 0, -1}; // 위, 왼위, 왼, 왼아래, 아래, 오른아래, 오른, 오른위
int dy[8] = {0, 0, -1, -1, -1, 0, 1, 1, 1};

void changePos(){
    for(int i=0; i<fish_pos.size(); i++){
        int nx = fish_pos[i].second.first.first;
        int ny = fish_pos[i].second.first.second;
    }
}
int main(){
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            int num, dir;
            cin >> num >> dir;
            fish_pos.push_back({num, {{i, j}, dir}});
            map[i][j] = num;
        }
    }
    sort(fish_pos.begin(), fish_pos.end());
    
    shark_dir = fish_pos[map[0][0]-1].second.second;
    
    while(true){
        changePos();
        
        //상어 이동
        //만약 이동할 수 없다면 break;
    }
}
