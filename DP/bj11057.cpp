//
//  bj11057.cpp
//  DP
//
//  Created by 김다원 on 2020/03/07.
//  Copyright © 2020 김다원. All rights reserved.
//

#include <stdio.h>

int d[1001][10];
int main(void){
    int n, sum=0;
    scanf("%d", &n);
    for(int i=0; i<10; i++) d[1][i] = 1;
    
    for(int i=2; i<=n; i++){
        for(int j=0; j<10; j++){
            for(int k=j; k<10; k++)
                d[i][j] += d[i-1][k];
            d[i][j] = d[i][j]%10007;
        }
    }
    
    for(int i=0; i<10; i++) sum += d[n][i];
    printf("%d\n", sum%10007);
    return 0;
}
