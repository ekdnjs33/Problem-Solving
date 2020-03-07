//
//  bj10844.cpp
//  DP
//
//  Created by 김다원 on 2020/03/05.
//  Copyright © 2020 김다원. All rights reserved.
//

#include <stdio.h>

long long d[101][10];
int main(void){
    int n;
    long long sum=0;
    scanf("%d", &n);
    for(int i=1; i<=9; i++) d[1][i] = 1;
    
    for(int i=2; i<=n; i++){
        for(int j=0; j<=9; j++){
            if(j==0) d[i][j] = d[i-1][j+1];
            else if(j==9) d[i][j] = d[i-1][j-1];
            else d[i][j] = (d[i-1][j-1]+d[i-1][j+1])%1000000000;
        }
    }
    for(int i=0; i<=9; i++) sum += d[n][i];
    printf("%lld\n", sum%1000000000);
    return 0;
}
