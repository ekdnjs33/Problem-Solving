//
//  사다리조작.cpp
//  삼성코테준비
//
//  Created by 김다원 on 2020/09/02.
//  Copyright © 2020 김다원. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

int n, m, h, result = 1000;
bool map[31][11];

bool game(){
    for(int i=1; i<=n; i++){
        int now = i;
        for(int j=1; j<=h; j++){
            if(map[j][now] == true)
                now = now + 1;
            else if(map[j][now-1] == true)
                now = now - 1;
        }
        if(now != i)
            return false;
    }
    return true;
}
void select_line(int idx, int cnt){
    if(cnt > 3)
        return;
    
    if(game() == true){
        result = min(result, cnt);
        return;
    }
    
    for(int i=idx; i<=h; i++){
        for(int j=1; j<n; j++){
            if(map[i][j] == true) continue;
            if(map[i][j-1] == true) continue;
            if(map[i][j+1] == true) continue;
            
            map[i][j] = true;
            select_line(i, cnt+1);
            map[i][j] = false;
        }
    }
}
int main(){
    cin >> n >> m >> h;
    for(int i=0; i<m; i++){
        int x, y;
        cin >> x >> y;
        map[x][y] = true;
    }
    
    select_line(1, 0);
    
    if(result == 1000) //게임이 성공하는 경우가 없어
        result = -1;
    cout << result << endl;
    
    return 0;
}
