
//
//  bj2193.cpp
//  DP
//
//  Created by 김다원 on 2020/03/07.
//  Copyright © 2020 김다원. All rights reserved.
//

#include <stdio.h>

long long d[91][2];
int main(void){
    int n;
    long long sum=0;
    scanf("%d", &n);
    d[1][1] = 1;
    
    for(int i=2; i<=n; i++){
        d[i][0] = d[i-1][0]+d[i-1][1];
        d[i][1] = d[i-1][0];
    }
    sum = d[n][0]+d[n][1];
    printf("%lld\n", sum);
    return 0;
}
