//
//  bj2156.cpp
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
    int n;
    scanf("%d", &n);
    int arr[n+1];
    for(int i=1; i<=n; i++){
        scanf("%d", &arr[i]);
    }
    /*int d[3][n+1];
    d[0][0] = d[1][0] = d[2][0] = d[2][1] = 0;
    d[0][1] = d[1][1] = arr[1];
    for(int i=2; i<=n; i++){
        d[0][i] = max(d[1][i-2], d[2][i-1]) + arr[i]; // 전 잔을 안 마시고 지금 잔을 마신다
        d[1][i] = d[0][i-1] + arr[i];  // 전 잔을 마시고 지금 잔을 마신다
        d[2][i] = max(d[2][i-1], max(d[0][i-1], d[1][i-1])); // 지금 잔을 안 마신다
    }
    printf("%d\n", max(d[2][n], max(d[0][n], d[1][n])));*/
    int dp[n+1];
    dp[0] = 0;
    dp[1] = arr[1]; // 잔이 1개면 1개 마셔야 최대
    if(n>1){
        dp[2] = arr[1]+arr[2]; // 잔이 2개면 2개 다 마셔야 최대
        for(int i=3; i<=n; i++){ // 잔이 3개 이상이면
            // 마지막 잔을 안 마신 경우, 연속으로 1개 마신 경우, 연속으로 2개 마신 경우 중 가장 큰 값을 선택
            dp[i] = max(dp[i-1], max(dp[i-2] + arr[i], dp[i-3] + arr[i-1] + arr[i]));
        }
    }
    printf("%d\n", dp[n]);
    return 0;
}
