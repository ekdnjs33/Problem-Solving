//
//  bj11054.cpp
//  DP
//
//  Created by 김다원 on 2020/03/07.
//  Copyright © 2020 김다원. All rights reserved.
//

#include <stdio.h>

int main(void){
    int n, max = 0;
    scanf("%d", &n);
    int arr[n+1];
    int dp[2][n+1];
    for(int i = 1; i <= n; i++){
        scanf("%d", &arr[i]);
    }
    dp[0][1] = 1;
    dp[1][n] = 1;
    for(int i = 2; i <= n; i++){
        dp[0][i] = 1;
        for(int j = 1; j < i; j++){
            if(arr[i] > arr[j] && dp[0][j] >= dp[0][i])
                dp[0][i] = dp[0][j]+1;
        }
    }
    for(int i = n-1; i >= 1; i--){
        dp[1][i] = 1;
        for(int j = n; j > i; j--){
            if(arr[i] > arr[j] && dp[1][j] >= dp[1][i])
                dp[1][i] = dp[1][j]+1;
        }
    }
    for(int i = 1; i <= n; i++){
        //printf("%d ", dp[0][i]+dp[1][i]);
        if(dp[0][i]+dp[1][i] > max)
            max = dp[0][i]+dp[1][i];
    }
    printf("%d\n", max-1);
    return 0;
}
