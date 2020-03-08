//
//  bj1912.cpp
//  DP
//
//  Created by 김다원 on 2020/03/08.
//  Copyright © 2020 김다원. All rights reserved.
//

#include <stdio.h>

int max(int a, int b){
    if(a > b) return a;
    else return b;
}
int main(void){
    int n, dp_max;
    scanf("%d", &n);
    int arr[n+1];
    int dp[n+1];
        for(int i = 1; i <= n; i++){
        scanf("%d", &arr[i]);
    }
    dp[1] = dp_max = arr[1];
    for(int i = 2; i <= n; i++){
        dp[i] = max(dp[i-1] + arr[i], arr[i]);
        if(dp[i] > dp_max)
            dp_max = dp[i];
    }
    printf("%d\n", dp_max);
    return 0;
}
