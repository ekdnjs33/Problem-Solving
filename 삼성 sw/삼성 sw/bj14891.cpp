//
//  bj14891.cpp
//  삼성 sw
//
//  Created by 김다원 on 2020/04/14.
//  Copyright © 2020 김다원. All rights reserved.
//

/* 톱니바퀴 */
#include <iostream>
#include <string>
using namespace std;

int wheel[5][8]; //1-4번, 12시부터 시계 방향
int score[4][2] = {{0, 1}, {0, 2}, {0, 4}, {0, 8}};
bool visit[5];
void Turn(int num, int dir){ //바퀴 회전
    int tmp;
    if(dir == -1){ //반시계 회전
        tmp = wheel[num][0];
        for(int i=1; i<=7; i++){
            wheel[num][i-1] = wheel[num][i];
        }
        wheel[num][7] = tmp;
    }
    else if(dir == 1){ //시계 회전
        tmp = wheel[num][7];
        for(int i=6; i>=0; i--){
            wheel[num][i+1] = wheel[num][i];
        }
        wheel[num][0] = tmp;
    }
    return;
}
void Check(int num, int dir){ //회전할 바퀴인지 확인
    visit[num] = true;
    if(num == 1){
        if(!visit[num+1] && (wheel[num][2] != wheel[num+1][6])){
            Check(num+1, -dir);
        }
    }else if(num == 4){
        if(!visit[num-1] && (wheel[num][6] != wheel[num-1][2])){
            Check(num-1, -dir);
        }
    }else{
        if(!visit[num+1] && (wheel[num][2] != wheel[num+1][6])){
            Check(num+1, -dir);
        }
        if(!visit[num-1] && (wheel[num][6] != wheel[num-1][2])){
            Check(num-1, -dir);
        }
    }
    Turn(num, dir);
    visit[num] = false;
    return;
}
int main(){
    string str;
    int k;
    for(int i=1; i<=4; i++){
        cin >> str;
        for(int j=0; j<8; j++)
            wheel[i][j] = str[j] - 48;
    }
    cin >> k;
    for(int i=0; i<k; i++){
        int a, b;
        cin >> a >> b;
        Check(a, b);
    }
    int sum = score[0][wheel[1][0]]+score[1][wheel[2][0]]+score[2][wheel[3][0]]+score[3][wheel[4][0]];
    cout << sum << "\n";
}
