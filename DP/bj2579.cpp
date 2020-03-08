//
//  bj2579.cpp
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
    int n;
    scanf("%d", &n);
    int arr[n+1];
    int dp[n+1];
    for(int i = 1; i <= n; i++){
        scanf("%d", &arr[i]);
    }
    dp[0] = 0;
    dp[1] = arr[1];
    dp[2] = arr[1] + arr[2];
    if(n > 1){
        dp[2] = arr[1] + arr[2];
        for(int i = 3; i <= n; i++){
            dp[i] = max(dp[i-2] + arr[i], dp[i-3] + arr[i-1] + arr[i]);
        }
    }
    printf("%d\n", dp[n]);
}
