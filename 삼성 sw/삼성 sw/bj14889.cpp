//
//  bj14889.cpp
//  삼성 sw
//
//  Created by 김다원 on 2020/04/14.
//  Copyright © 2020 김다원. All rights reserved.
//

/* 스타트와 링크 */
#include <iostream>
#include <cmath>
using namespace std;

int n;
int m = 1000; //가장 최소값을 저장
bool visit[21];
int score[21][21];
int sum(int t[]){ //팀의 능력치 합
    int sum = 0;
    for(int i=0; i<n/2; i++){
        for(int j=0; j<n/2; j++)
            sum += score[t[i]][t[j]];
    }
    return sum;
}
void combination(int start, int cnt){
    if(cnt == 0){
        int startT[n/2];
        int linkT[n/2];
        int a=0, b=0;
        for(int i=1; i<=n; i++){ //스타트팀과 링크팀으로 나눠
            if(visit[i] == true){
                startT[a] = i;
                a++;
            }else{
                linkT[b] = i;
                b++;
            }
        }
        int min = abs(sum(startT)-sum(linkT)); //스타트팀 능력치와 링크팀 능력치 차이 계산
        if(min < m) m = min;
        return;
    }else{
        for(int i=start; i<=n; i++){ //조합
            visit[i] = true;
            combination(i+1, cnt-1);
            visit[i] = false;
        }
    }
}
int main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++)
            cin >> score[i][j];
    }
    combination(1, n/2);
    cout << m << "\n";
}
