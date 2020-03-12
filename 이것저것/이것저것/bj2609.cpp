//
//  bj2609.cpp
//  이것저것
//
//  Created by 김다원 on 2020/03/12.
//  Copyright © 2020 김다원. All rights reserved.
//

#include <stdio.h>
int gcd(int a, int b){ // 최대공약수
    int max, min, x=1;
    if(a > b){
        max = a;
        min = b;
    }else{
        max = b;
        min = a;
    }
    while(1){
        x = max%min;
        if(x == 0) break;
        max = min;
        min = x;
    }
    return min;
}
int lcm(int a, int b, int c){ // 최소공배수
    return a*b/c;
}
int main(void){
    int a, b, g, l;
    scanf("%d %d", &a, &b);
    g = gcd(a, b);
    l = lcm(a, b, g);
    printf("%d\n%d\n", g, l);
    return 0;
}
