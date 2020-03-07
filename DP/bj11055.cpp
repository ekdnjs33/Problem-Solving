//
//  bj11055.cpp
//  DP
//
//  Created by 김다원 on 2020/03/07.
//  Copyright © 2020 김다원. All rights reserved.
//

#include <stdio.h>

int max(int a, int b){
    if(a > b) return a;
    else return b;
}
int main(void){
    int n, val = 0;
    scanf("%d", &n);
    int arr[n+1];
    int dp[n+1];
    for(int i = 1; i <= n; i++){
        scanf("%d", &arr[i]);
    }
    dp[1] = arr[1];
    for(int i = 2; i <= n; i++){
        dp[i] = 0;
        for(int j = 1; j < i; j++){
            if(arr[j] < arr[i] && dp[j] > dp[i])
                dp[i] = dp[j];
        }
        dp[i] += arr[i];
    }
    for(int i = 1; i <= n; i++){
        //printf("%d ", dp[i]);
        val = max(len, dp[i]);
    }
    printf("%d\n", val);
}
