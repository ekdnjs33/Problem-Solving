//
//  bj11724.cpp
//  그래프
//
//  Created by 김다원 on 2020/04/04.
//  Copyright © 2020 김다원. All rights reserved.
//

#include <iostream>
using namespace std;

int map[1001][1001];
int visit[1001];
int n, m;
void dfs(int start){
    visit[start] = 1;
    for(int i=1; i<=n; i++){
        if(visit[i] == 0 && map[start][i] == 1)
            dfs(i);
    }
}
int main(){
    int a, b, cnt=0;
    cin >> n >> m;
    for(int i=1; i<=m; i++){
        cin >> a >> b;
        map[a][b] = map[b][a] = 1;
    }
    for(int i=1; i<=n; i++){
        if(visit[i] == 0){
            dfs(i);
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
