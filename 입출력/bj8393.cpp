//
//  bj8393.cpp
//  입출력
//
//  Created by 김다원 on 2020/03/04.
//  Copyright © 2020 김다원. All rights reserved.
//

#include <stdio.h>

int main(void){
    int n, sum=0;
    scanf("%d", &n);
    for(int i=0; i<=n; i++){
        sum+=i;
    }
    printf("%d\n", sum);
    return 0;
}
