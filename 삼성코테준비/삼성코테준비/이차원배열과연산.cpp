//
//  이차원배열과연산.cpp
//  삼성코테준비
//
//  Created by 김다원 on 2020/09/08.
//  Copyright © 2020 김다원. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int r, c, k, cnt = 0, max_row = 3, max_col = 3;
int arr[101][101];
int visit[101];

void init_visit(){
    for(int i=0; i<101; i++)
        visit[i] = 0;
}
int main(){
    cin >> r >> c >> k;
    for(int i=1; i<=3; i++)
        for(int j=1; j<=3; j++)
            cin >> arr[i][j];
    
    while(arr[r][c] != k){
        if(cnt > 100){
            cnt = -1;
            break;
        }
        
        if(max_col >= max_row){
            int row = max_row;
            for(int i=1; i<=max_col; i++){
                init_visit();
                vector<pair<int, int>> list;
                for(int j=1; j<=row; j++){
                    visit[arr[i][j]]++;
                    arr[i][j] = 0;
                }
                
                for(int j=1; j<=100; j++)
                    if(visit[j] != 0)
                        list.push_back({visit[j], j});
                sort(list.begin(), list.end());
                
                int nj = 1;
                for(int j=0; j<list.size(); j++){
                    if(nj > 100)
                        break;
                    arr[i][nj++] = list[j].second;
                    arr[i][nj++] = list[j].first;
                }
                max_row = max(max_row, nj-1);
            }
        }
        else{
            int col = max_col;
            for(int i=1; i<=max_row; i++){
                init_visit();
                vector<pair<int, int>> list;
                for(int j=1; j<=col; j++){
                    visit[arr[j][i]]++;
                    arr[j][i] = 0;
                }
                
                for(int j=1; j<=100; j++)
                    if(visit[j] != 0)
                        list.push_back({visit[j], j});
                sort(list.begin(), list.end());
                
                int nj = 1;
                for(int j=0; j<list.size(); j++){
                    if(nj > 100)
                        break;
                    arr[nj++][i] = list[j].second;
                    arr[nj++][i] = list[j].first;
                }
                max_col = max(max_col, nj-1);
            }
        }
        cnt++;
    }
    cout << cnt << endl;
    
    return 0;
}
