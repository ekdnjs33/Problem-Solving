//
//  bj1699.cpp
//  DP
//
//  Created by 김다원 on 2020/03/08.
//  Copyright © 2020 김다원. All rights reserved.
//

#include <stdio.h>
#include <cmath>

int min(int a, int b){
    if(a < b) return a;
    else return b;
}
int main(void){
    int n;
    scanf("%d", &n);
    int dp[n+1];
    dp[0] = 0;
    for(int i = 1; i <= n; i++){
        dp[i] = i;
        for(int j = 2; j*j <= i; j++){
            dp[i] = min(dp[i], dp[i-j*j]+1);
        }
    }
    printf("%d\n", dp[n]);
    return 0;
}
