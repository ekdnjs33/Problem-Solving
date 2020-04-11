//
//  bj1707.cpp
//  그래프
//
//  Created by 김다원 on 2020/04/04.
//  Copyright © 2020 김다원. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> vr[20001];
int visit[20001];

void dfs(int start, int c){
    visit[start] = c;
    for(int i=0; i<vr[start].size(); i++){
        int next = vr[start][i];
        if(visit[next] == 0)
            dfs(next, 3-c);
    }
}
int main(){
    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        int v, e;
        cin >> v >> e;
        for(int i=1; i<=v; i++){
            vr[i].clear();
            visit[i] = 0;
        }
        for(int j=1; j<=e; j++){
            int a, b;
            cin >> a >> b;
            vr[a].push_back(b);
            vr[b].push_back(a);
        }
        for(int i=1; i<=v; i++){
            if(visit[i] == 0)
                dfs(i, 1);
        }
        bool res = true;
        for(int i=1; i<=v; i++){
            for(int j=0; j<vr[i].size(); j++){
                int k = vr[i][j];
                if(visit[i] == visit[k])
                    res = false;
            }
        }
        cout << (res?"YES":"NO") << endl;
    }
}
