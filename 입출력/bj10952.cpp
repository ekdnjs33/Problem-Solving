//
//  bj10952.cpp
//  입출력
//
//  Created by 김다원 on 2020/03/03.
//  Copyright © 2020 김다원. All rights reserved.
//

#include <stdio.h>

int main(void){
    int A, B;
    while(1){
        scanf("%d %d", &A, &B);
        if(A!=0 && B!=0){
            printf("%d\n", A+B);
        }else
            return 0;
    }
}
