//
//  bj9095.cpp
//  DP
//
//  Created by 김다원 on 2020/03/05.
//  Copyright © 2020 김다원. All rights reserved.
//

#include <stdio.h>

int d[12];
int dp(int x){
    if(x==1) return 1;
    if(x==2) return 2;
    if(x==3) return 4;
    if(d[x] != 0) return d[x];
    return d[x] = dp(x-1)+dp(x-2)+dp(x-3);
}
int main(void){
    int t, n;
    scanf("%d", &t);
    for(int i=0; i<t; i++){
        scanf("%d", &n);
        printf("%d\n", dp(n));
    }
    return 0;
}
