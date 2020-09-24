//
//  나무재테크.cpp
//  삼성코테준비
//
//  Created by 김다원 on 2020/09/07.
//  Copyright © 2020 김다원. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, m, k, result = 0;
int A[11][11];
int energy[11][11];

vector<int> map[11][11];
queue<pair<pair<int, int>, int>> dead_tree;
queue<pair<int, int>> old_tree;

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

void spring(){
    for(int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            if(map[i][j].size() == 0) continue;
            
            vector<int> temp;
            sort(map[i][j].begin(), map[i][j].end());
            for(int k=0; k<map[i][j].size(); k++){
                int age = map[i][j][k];
                
                if(energy[i][j] >= age){
                    energy[i][j] -= age;
                    temp.push_back(age + 1);
                }
                else
                    dead_tree.push({{i, j}, age});
            }
            
            map[i][j].clear();
            for(int k=0; k<temp.size(); k++){
                map[i][j].push_back(temp[k]);
                
                if(temp[k] % 5 == 0)
                    old_tree.push({i, j});
            }
        }
    }
}
void summer(){
    while(!dead_tree.empty()){
        int x = dead_tree.front().first.first;
        int y = dead_tree.front().first.second;
        int num = dead_tree.front().second/2;
        dead_tree.pop();
        
        energy[x][y] += num;
    }
}
void fall(){
    while(!old_tree.empty()){
        int x = old_tree.front().first;
        int y = old_tree.front().second;
        old_tree.pop();
        
        for(int i=0; i<8; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx >= 1 && ny >= 1 && nx <= n && ny <= n)
                map[nx][ny].push_back(1);
        }
    }
}
void winter(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            energy[i][j] += A[i][j];
        }
    }
}
int main(){
    cin >> n >> m >> k;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> A[i][j];
            energy[i][j] = 5;
        }
    }
    for(int i=0; i<m; i++){
        int x, y, age;
        cin >> x >> y >> age;
        map[x][y].push_back(age);
    }
    
    for(int i=0; i<k; i++){
        spring();
        summer();
        fall();
        winter();
    }
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            result += map[i][j].size();
        }
    }
    cout << result << endl;
    
    return 0;
}
