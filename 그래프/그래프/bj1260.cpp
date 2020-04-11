//
//  bj1260.cpp
//  그래프
//
//  Created by 김다원 on 2020/04/04.
//  Copyright © 2020 김다원. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

int visit_dfs[1001];
int visit_bfs[1001];
int map[1001][1001];
int n, m, v;
void dfs(int a){ //재귀 이용
    cout << a << " ";
    visit_dfs[a] = 1;
    for(int i=1; i<=n; i++){
        if(visit_dfs[i] == 0 && map[a][i] == 1)
            dfs(i);
    }
}
void bfs(int a){ //큐 이용
    queue<int> q;
    q.push(a);
    visit_bfs[a] = 1;
    while(!q.empty()){
        a = q.front();
        cout << a << " ";
        q.pop();
        for(int i=1; i<=n; i++){
            if(visit_bfs[i] == 0 && map[a][i] == 1){
                q.push(i);
                visit_bfs[i] = 1;
            }
        }
    }
}
int main(){
    int a, b;
    cin >> n >> m >> v;
    for(int i=0; i<m; i++){
        cin >> a >> b;
        map[a][b] = map[b][a] = 1;
    }
    dfs(v);
    cout << "\n";
    bfs(v);
    cout << "\n";
    return 0;
}
