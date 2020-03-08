//
//  bj9461.cpp
//  DP
//
//  Created by 김다원 on 2020/03/08.
//  Copyright © 2020 김다원. All rights reserved.
//

#include <stdio.h>

long long dp[101];
int main(void){
    int t, n;
    scanf("%d", &t);
    for(int i=0; i<t; i++){
        scanf("%d", &n);
        dp[1] = dp[2] = dp[3] = 1;
        dp[4] = dp[5] = 2;
        for(int j=6; j<=n; j++){
            dp[j] = dp[j-1]+dp[j-5];
        }
        printf("%lld\n", dp[n]);
    }
    return 0;
}
