//
//  bj2133.cpp
//  DP
//
//  Created by 김다원 on 2020/03/08.
//  Copyright © 2020 김다원. All rights reserved.
//

#include <stdio.h>

int dp[31];
int main(void){
    int n;
    scanf("%d", &n);
    dp[0] = 1;
    for(int i = 2; i <= n; i++){
        dp[i] = dp[i-2]*3;
        for(int j = 2; j*2 <= i; j++){
            dp[i] += dp[i-j*2]*2;
        }
    }
    printf("%d\n", dp[n]);
    return 0;
}
