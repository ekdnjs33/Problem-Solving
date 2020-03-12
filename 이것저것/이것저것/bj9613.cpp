//
//  bj9613.cpp
//  이것저것
//
//  Created by 김다원 on 2020/03/12.
//  Copyright © 2020 김다원. All rights reserved.
//

#include <stdio.h>
int gcd(int a, int b){
    int max = a, min = b, x;
    if(b > a){
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
int main(void){
    int t, n;
    long long g;
    scanf("%d", &t);
    for(int i=0; i<t; i++){
        scanf("%d", &n);
        int arr[n];
        g = 0;
        for(int j=0; j<n; j++){
            scanf("%d", &arr[j]);
        }
        for(int j=0; j<n; j++){
            for(int k=j+1; k<n; k++){
                g += gcd(arr[j], arr[k]);
            }
        }
        printf("%lld\n", g);
    }
    return 0;
}
