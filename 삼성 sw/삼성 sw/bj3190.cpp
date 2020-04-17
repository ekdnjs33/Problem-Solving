//
//  bj3190.cpp
//  삼성 sw
//
//  Created by 김다원 on 2020/04/14.
//  Copyright © 2020 김다원. All rights reserved.
//

/* 뱀 */
#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int n, k, t, res=0, m=0;
int dx[4] = {0, 1, 0, -1}; //오른쪽(0), 아래(1), 왼쪽(2), 위쪽(3)
int dy[4] = {1, 0, -1, 0};
int map[101][101];
queue<pair<int, int>> q;
int move(int time, char dir){
    for(int i=0; i<time; i++){
        res++;
        int nx = q.back().first+dx[m];
        int ny = q.back().second+dy[m];
        if(nx >= 0 && nx < n && ny >= 0 && ny < n){
            if(map[nx][ny] == 0){ //아무것도 없는 경우
                map[nx][ny] = 1;
                q.push(make_pair(nx, ny));
                int tx = q.front().first;
                int ty = q.front().second;
                map[tx][ty] = 0;
                q.pop();
            }
            else if(map[nx][ny] == 2){ //사과가 있는 경우
                map[nx][ny] = 1;
                q.push(make_pair(nx, ny));
            }
            else{ //자기 몸통인 경우
                return -1;
            }
        }else{
            return -1; //뱀이 벽에 부딪힌 경우
        }
    }
    if(dir == 'D')
        m = (m+1)%4;
    else if(dir == 'L')
        m = (m+3)%4;
    return 1;
}
int main(){
    cin >> n >> k;
    map[0][0] = 1;
    for(int i=0; i<k; i++){
        int a, b;
        cin >> a >> b;
        map[a-1][b-1] = 2;
    }
    q.push(make_pair(0, 0)); //(0, 0)에서 출발
    cin >> t;
    int stop = 1;
    for(int i=0; i<t; i++){
        int c;
        char d;
        cin >> c >> d;
        stop = move(c-res, d);
        if(stop == -1)
            break;
    }
    if(stop == 1){
        move(n, 'D');
    }
    cout << res << "\n";
    return 0;
}
