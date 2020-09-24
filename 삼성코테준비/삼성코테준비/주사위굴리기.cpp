//
//  주사위굴리기.cpp
//  삼성코테준비
//
//  Created by 김다원 on 2020/08/30.
//  Copyright © 2020 김다원. All rights reserved.
//

#include <iostream>
using namespace std;

int n, m, x, y, k;
int map[21][21];
int dice[7];
int dx[5] = {0, 0, 0, -1, 1};
int dy[5] = {0, 1, -1, 0, 0};

void map_dice(int num){
    int tmp;
    if(num == 1){
        tmp = dice[1];
        dice[1] = dice[4];
        dice[4] = dice[6];
        dice[6] = dice[3];
        dice[3] = tmp;
    }
    else if(num == 2){
        tmp = dice[1];
        dice[1] = dice[3];
        dice[3] = dice[6];
        dice[6] = dice[4];
        dice[4] = tmp;
    }else if(num == 3){
        tmp = dice[2];
        dice[2] = dice[1];
        dice[1] = dice[5];
        dice[5] = dice[6];
        dice[6] = tmp;
    }else if(num == 4){
        tmp = dice[2];
        dice[2] = dice[6];
        dice[6] = dice[5];
        dice[5] = dice[1];
        dice[1] = tmp;
    }
}
void rolling_dice(int num){
    int nx = x + dx[num];
    int ny = y + dy[num];
    
    if(nx >= 0 && ny >= 0 && nx < n && ny < m){
        x = nx;
        y = ny;
        map_dice(num);
        
        if(map[x][y] == 0)
            map[x][y] = dice[6];
        else{
            dice[6] = map[x][y];
            map[x][y] = 0;
        }
        
        cout << dice[1] << endl;
    }
}
int main(){
    cin >> n >> m >> x >> y >> k;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
        }
    }
    for(int i=0; i<k; i++){
        int c;
        cin >> c;
        rolling_dice(c);
    }
    
    return 0;
}

