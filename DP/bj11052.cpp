//
//  bj11052.cpp
//  DP
//
//  Created by 김다원 on 2020/03/09.
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
    for(int i=1; i<=n; i++){
        scanf("%d", &arr[i]);
    }
    int dp[n+1];
    dp[0] = 0;
    for(int i=1; i<=n; i++){
        dp[i] = arr[i];
        for(int j=1; j<=i/2; j++){
            dp[i] = max(dp[i], dp[i-j]+dp[j]);
        }
    }
    printf("%d\n", dp[n]);
    return 0;
}
