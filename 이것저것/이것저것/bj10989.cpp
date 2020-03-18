//
//  bj10989.cpp
//  이것저것
//
//  Created by 김다원 on 2020/03/17.
//  Copyright © 2020 김다원. All rights reserved.
//

#include <stdio.h>

int arr[10001]; // 10000보다 작거나 같은 자연수이다
int main(void){
    int n, max = 0;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        int a;
        scanf("%d", &a);
        arr[a]++;
        if (a > max) max = a;
    }
    for(int i=1; i<=max; i++){
        for(int j=0; j<arr[i]; j++)
            printf("%d\n", i);
    }
    return 0;
}
