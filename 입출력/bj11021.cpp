//
//  bj11021.cpp
//  입출력
//
//  Created by 김다원 on 2020/03/03.
//  Copyright © 2020 김다원. All rights reserved.
//

#include <stdio.h>

int main(void){
    int t, A, B;
    scanf("%d", &t);
    for(int i=1; i<=t; i++){
        scanf("%d %d", &A, &B);
        printf("Case #%d: %d\n", i, A+B);
    }
    return 0;
}
