//
//  톱니바퀴.cpp
//  삼성코테준비
//
//  Created by 김다원 on 2020/09/06.
//  Copyright © 2020 김다원. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

int wheel[4][8];
int k, result = 0;
bool visit[5];
queue<pair<int, int>> q;

void rotate(int num, int dir){
    int tmp = wheel[num][0];
    
    if(dir == 1){
        wheel[num][0] = wheel[num][7];
        wheel[num][7] = wheel[num][6];
        wheel[num][6] = wheel[num][5];
        wheel[num][5] = wheel[num][4];
        wheel[num][4] = wheel[num][3];
        wheel[num][3] = wheel[num][2];
        wheel[num][2] = wheel[num][1];
        wheel[num][1] = tmp;
    }
    else if(dir == -1){
        wheel[num][0] = wheel[num][1];
        wheel[num][1] = wheel[num][2];
        wheel[num][2] = wheel[num][3];
        wheel[num][3] = wheel[num][4];
        wheel[num][4] = wheel[num][5];
        wheel[num][5] = wheel[num][6];
        wheel[num][6] = wheel[num][7];
        wheel[num][7] = tmp;
    }
}
void dfs(int num, int dir){
    visit[num] = true;
    
    int left_num = num - 1;
    int right_num = num + 1;
    if(left_num >= 0 && wheel[left_num][2] != wheel[num][6] && !visit[left_num]){
        dfs(left_num, -dir);
    }
    if(right_num < 4 && wheel[right_num][6] != wheel[num][2] && !visit[right_num]){
        dfs(right_num, -dir);
    }
    
    visit[num] = false;
    rotate(num, dir);
}
int score(int num){
    if(wheel[num][0] == 1){
        if(num == 0)
            return 1;
        else if(num == 1)
            return 2;
        else if(num == 2)
            return 4;
        else if(num == 3)
            return 8;
    }
    return 0;
}
int main(){
    string a;
    for(int i=0; i<4; i++){
        cin >> a;
        for(int j=0; j<8; j++){
            wheel[i][j] = a[j] - 48;
        }
    }
    cin >> k;
    for(int i=0; i<k; i++){
        int b, c;
        cin >> b >> c;
        q.push({b - 1, c});
    }
    
    while(!q.empty()){
        int num = q.front().first;
        int dir = q.front().second;
        q.pop();
        
        dfs(num, dir);
    }
    
    for(int i=0; i<4; i++)
        result += score(i);
    cout << result << endl;
    
    return 0;
}
