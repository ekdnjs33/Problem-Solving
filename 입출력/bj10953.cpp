//
//  bj10953.cpp
//  입출력
//
//  Created by 김다원 on 2020/03/03.
//  Copyright © 2020 김다원. All rights reserved.
//

#include <stdio.h>

int main(void){
    int t, A, B;
    char c; // 콤마 붙일 곳을 선언
    scanf("%d", &t);
    for(int i=0; i<t; i++){
        scanf("%d %c %d", &A, &c, &B);
        printf("%d\n", A+B);
    }
    return 0;
}
