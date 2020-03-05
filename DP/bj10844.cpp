//
//  bj10844.cpp
//  DP
//
//  Created by 김다원 on 2020/03/05.
//  Copyright © 2020 김다원. All rights reserved.
//

#include <stdio.h>
#include <cmath>

int d[101];
int dp(int x){
    int cal = pow(2, (x/2)-1);
    if(x==1) return 9;
    if(d[x] != 0) return d[x];
    return d[x] = ((dp(x-1)-cal)*2+cal)%1000000000;
}
int main(void){
    int n;
    scanf("%d", &n);
    printf("%d\n", dp(n));
    return 0;
}
