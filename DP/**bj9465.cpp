//
//  bj9465.cpp
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
    int t, n;
    scanf("%d", &t);
    for(int k = 0; k < t; k++){
        scanf("%d", &n);
        int arr[2][n+1];
        int d[2][n+1];
        for(int i = 0; i < 2; i++){
            for(int j = 1; j <= n; j++){
                scanf("%d", &arr[i][j]);
            }
        }
        
        d[0][0] = d[1][0] = 0;
        d[0][1] = arr[0][1];
        d[1][1] = arr[1][1];
        for(int i = 2; i <= n; i++){
            d[0][i] = max(d[1][i-1], d[1][i-2]) + arr[0][i];
            d[1][i] = max(d[0][i-1], d[0][i-2]) + arr[1][i];
        }
        printf("%d\n", max(d[0][n], d[1][n]));
    }
    return 0;
}
