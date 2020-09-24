//
//  2048Easy.cpp
//  삼성코테준비
//
//  Created by 김다원 on 2020/09/06.
//  Copyright © 2020 김다원. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

int n, result = 0;
int map[20][20];
bool visit[20][20];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void init_visit(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            visit[i][j] = false;
    }
}
void game_run(int dir){
    if(dir == 0){
        for(int j=0; j<n; j++)
            for(int i=1; i<n; i++)
                if(map[i][j] != 0){
                    int next_i = i - 1;
                    while(1){
                        if(next_i < 0 || map[next_i][j] != 0)
                            break;
                        next_i--;
                    }
                    if(next_i >= 0 && map[next_i][j] == map[i][j] && !visit[next_i][j]){
                        map[next_i][j] += map[i][j];
                        map[i][j] = 0;
                        visit[next_i][j] = true;
                    }
                    else{
                        int k = map[i][j];
                        map[i][j] = 0;
                        map[next_i+1][j] = k;
                    }
                }
    }
    else if(dir == 1){
        for(int j=0; j<n; j++)
            for(int i=n-2; i>=0; i--)
                if(map[i][j] != 0){
                    int next_i = i + 1;
                    while(1){
                        if(next_i >= n || map[next_i][j] != 0)
                            break;
                        next_i++;
                    }
                    if(next_i < n && map[next_i][j] == map[i][j] && !visit[next_i][j]){
                        map[next_i][j] += map[i][j];
                        map[i][j] = 0;
                        visit[next_i][j] = true;
                    }
                    else{
                        int k = map[i][j];
                        map[i][j] = 0;
                        map[next_i-1][j] = k;
                    }
                }
    }
    else if(dir == 2){
        for(int i=0; i<n; i++)
            for(int j=1; j<n; j++)
                if(map[i][j] != 0){
                    int next_j = j - 1;
                    while(1){
                        if(next_j < 0 || map[i][next_j] != 0)
                            break;
                        next_j--;
                    }
                    if(next_j >= 0 && map[i][next_j] == map[i][j] && !visit[i][next_j]){
                        map[i][next_j] += map[i][j];
                        map[i][j] = 0;
                        visit[i][next_j] = true;
                    }
                    else{
                        int k = map[i][j];
                        map[i][j] = 0;
                        map[i][next_j+1] = k;
                    }
                }
    }
    else if(dir == 3){
        for(int i=0; i<n; i++)
            for(int j=n-2; j>=0; j--)
                if(map[i][j] != 0){
                    int next_j = j + 1;
                    while(1){
                        if(next_j >= n || map[i][next_j] != 0)
                            break;
                        next_j++;
                    }
                    
                    if(next_j < n && map[i][next_j] == map[i][j] && !visit[i][next_j]){
                        map[i][next_j] += map[i][j];
                        map[i][j] = 0;
                        visit[i][next_j] = true;
                    }
                    else{
                        int k = map[i][j];
                        map[i][j] = 0;
                        map[i][next_j-1] = k;
                    }
                }
    }
}
int max_val(){
    int v = 0;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(map[i][j] > v)
                v = map[i][j];
    return v;
}
void dfs(int dir, int cnt){
    int copy_map[20][20];
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            copy_map[i][j] = map[i][j];
            
    if(cnt == 5){
        result = max(result, max_val());
        return;
    }
    
    init_visit();
    game_run(dir);
    for(int i=0; i<4; i++){
        dfs(i, cnt + 1);
    }
            
    for(int i=0; i<n; i++) //원래 맵으로 복구
        for(int j=0; j<n; j++)
            map[i][j] = copy_map[i][j];
}
int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> map[i][j];
        }
    }
    
    for(int i=0; i<4; i++)
        dfs(i, 0);
    
    cout << result << endl;
    
    return 0;
}
