//
//  bj2739.cpp
//  입출력
//
//  Created by 김다원 on 2020/03/03.
//  Copyright © 2020 김다원. All rights reserved.
//

#include <stdio.h>
int main(void){
    int N;
    scanf("%d", &N);
    for(int i=1; i<10; i++){
        printf("%d * %d = %d\n", N, i, N*i);
    }
    return 0;
}
