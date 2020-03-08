//
//  bj2011.cpp
//  DP
//
//  Created by 김다원 on 2020/03/08.
//  Copyright © 2020 김다원. All rights reserved.
//

#include <stdio.h>

int main(void){
    char arr[5000];
    int a[5001];
    int len = 0;
    scanf("%s", arr);
    for(int i=0; arr[i]!='\0'; i++){
        a[i+1] = arr[i]-48;
        len++;
    }
    long long dp[len+1];
    if(a[1] != 0){
        dp[0] = dp[1] = 1;
        for(int i=2; i<=len; i++){
            dp[i] = 0;
            if(a[i] == 0){
                if(a[i-1]*10+a[i] <= 26 && a[i-1]*10+a[i] > 0){
                    dp[i] += dp[i-2];
                    printf("dp[%d] = %lld\n", i, dp[i]);
                }
                else{
                    printf("%d\n", 0);
                    return 0;
                }
            }else{
                if(a[i-1] != 0){
                    if(a[i-1]*10+a[i] <= 26 && a[i-1]*10+a[i] > 0){
                        dp[i] += dp[i-2];
                        printf("dp[%d] = %lld\n", i, dp[i]);
                    }
                }
                dp[i] += dp[i-1];
                printf("dp[%d] = %lld\n", i, dp[i]);
            }
            dp[i] = dp[i]%1000000;
            printf("**dp[%d] = %lld\n", i, dp[i]);
        }
        printf("%lld\n", dp[len]);
    }
    else{
        printf("%d\n", 0);
        return 0;
    }
    return 0;
}
