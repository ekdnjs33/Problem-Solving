//
//  bj2442.cpp
//  입출력
//
//  Created by 김다원 on 2020/03/04.
//  Copyright © 2020 김다원. All rights reserved.
//

#include <stdio.h>
// 1, 3, ..., 2N-1, 가운데 대칭
int main(void){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        for (int j=0; j<n-i-1; j++){
            printf(" ");
        }
        for (int j=0; j<2*i+1; j++){ //뒤에는 공백이 없어야 한다
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
