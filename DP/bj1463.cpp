//
//  bj1463.cpp
//  DP
//
//  Created by 김다원 on 2020/03/05.
//  Copyright © 2020 김다원. All rights reserved.
//

#include <stdio.h>

int main(void){
    int n;
    int dp[1000001];
    scanf("%d", &n);
    dp[1]=0;
    for(int i=2; i<=n; i++) {
        dp[i]=dp[i-1]+1; // 1을 빼는 경우
        if(i%2==0 && dp[i]>dp[i/2]+1) { // 2로 나누는 경우
            dp[i]=dp[i/2]+1;
        }
        if(i%3==0 && dp[i]>dp[i/3]+1) { // 3으로 나누는 경우
            dp[i]=dp[i/3]+1;
        }
    }
    printf("%d\n", dp[n]);
    return 0;
}
