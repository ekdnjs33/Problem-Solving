//
//  뱀.cpp
//  삼성코테준비
//
//  Created by 김다원 on 2020/08/31.
//  Copyright © 2020 김다원. All rights reserved.
//

#include <iostream>
#include <deque>
using namespace std;

int n, k, l, result  = 0;
int x, y, d; //뱀 머리 현재 위치와 방향
int board[101][101]; //빈칸 0, 사과 1, 뱀 2
deque<pair<pair<int, int>, int>> snake; //뱀 위치, 방향 저장
char second[10001]; //오른쪽 = D, 왼쪽 = L

int dx[4] = {-1, 0, 1, 0}; //북, 동, 남, 서
int dy[4] = {0, 1, 0, -1};

int direct(int r, int dir){
    if(second[r] == 'D')
        return (dir + 5) % 4;
    else if(second[r] == 'L')
        return (dir + 3) % 4;
    else
        return dir;
}
void game_start(){
    while(1){
        result++;
        int nx = x + dx[d];
        int ny = y + dy[d];
        int nd = direct(result, d);
        
        if(nx < 0 || ny < 0 || nx >= n || ny >= n || board[nx][ny] == 2) return;
        
        if(board[nx][ny] == 1){
            snake.push_back({{nx, ny}, nd});
            x = nx; y = ny; d = nd;
            board[x][y] = 2;
        }
        else{
            int rx = snake.front().first.first;
            int ry = snake.front().first.second;
            board[rx][ry] = 0;
            snake.pop_front();
            snake.push_back({{nx, ny}, nd});
            x = nx; y = ny; d = nd;
            board[x][y] = 2;
        }
        
    }
}
int main(){
    cin >> n >> k;
    for(int i=0; i<k; i++){
        int ax, ay;
        cin >> ax >> ay;
        board[ax-1][ay-1] = 1;
    }
    cin >> l;
    for(int i=0; i<l; i++){
        int c;
        cin >> c;
        cin >> second[c];
    }
    x = 0; y = 0; d = 1;
    board[x][y] = 2;
    
    snake.push_back({{0, 0}, 1});
    game_start();
    cout << result << endl;
    
    return 0;
}

