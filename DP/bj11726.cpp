//
//  bj11726.cpp
//  DP
//
//  Created by 김다원 on 2020/03/05.
//  Copyright © 2020 김다원. All rights reserved.
//

#include <stdio.h>
int d[1001];
int dp(int x){
    if(x==1) return 1;
    if(x==2) return 2;
    if(d[x] != 0) return d[x];
    return d[x] = (dp(x-1)+dp(x-2))%10007;
}
int main(void){
    int n;
    scanf("%d", &n);
    printf("%d\n", dp(n));
    return 0;
}
