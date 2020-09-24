//
//  연구소3.cpp
//  삼성코테준비
//
//  Created by 김다원 on 2020/09/15.
//  Copyright © 2020 김다원. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, min_time = 1000000;
int map[50][50];
int visited[50][50];
bool select_virus[300];
vector<pair<int, int>> all_virus;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void copy_map(){
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            visited[i][j] = -map[i][j];
}
int spread_virus(){
    int x, y;
    queue<pair<int,int>> q;
    copy_map();
    for(int i=0; i<all_virus.size(); i++){
        if(select_virus[i] == true){
            int x = all_virus[i].first;
            int y = all_virus[i].second;
            visited[x][y] = 1;
            q.push({x, y});
        }
    }
    
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if(visited[nx][ny] > 0 || visited[nx][ny] == -1) continue;
            visited[nx][ny] = visited[x][y] + 1;
            q.push({nx, ny});
        }
    }
    int min = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(visited[i][j] == 0)
                return 1000000;
            
            if(visited[i][j] > min){
                if(map[i][j] == 0)
                    min = visited[i][j] - 1;
            }
        }
    }
    return min;
}
void dfs(int index, int cnt){ //조합
    if(cnt == m){
        int res = spread_virus();
        
        if(res < min_time)
            min_time = res;
        
        return;
    }
    for(int i=index; i<all_virus.size(); i++){
        if(select_virus[i] == true) continue;
        
        select_virus[i] = true;
        dfs(i, cnt+1);
        select_virus[i] = false;
    }
}
int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> map[i][j];
            
            if(map[i][j] == 2)
                all_virus.push_back({i, j});
        }
    }
    
    dfs(0, 0);
    if(min_time == 1000){
        min_time = -1;
    }
    cout << min_time << endl;
    
    return 0;
}
