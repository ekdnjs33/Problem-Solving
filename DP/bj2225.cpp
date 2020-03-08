//
//  bj2225.cpp
//  DP
//
//  Created by 김다원 on 2020/03/08.
//  Copyright © 2020 김다원. All rights reserved.
//

#include <stdio.h>

int main(void){
    int n, k;
    scanf("%d %d", &n, &k);
    long long dp[k+1][n+1];
    for(int i=1; i<=k; i++) dp[i][0] = 1;
    for(int i=0; i<=n; i++) dp[1][i] = 1;
    for(int i=2; i<=k; i++){
        for(int j=1; j<=n; j++){
            dp[i][j] = 0;
            for(int h=0; h<=j; h++){
                dp[i][j] += dp[i-1][j-h];
            }
            dp[i][j] = dp[i][j]%1000000000;
        }
    }
    printf("%lld\n", dp[k][n]);
    return 0;
}
