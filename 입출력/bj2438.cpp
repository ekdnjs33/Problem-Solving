//
//  bj2438.cpp
//  입출력
//
//  Created by 김다원 on 2020/03/04.
//  Copyright © 2020 김다원. All rights reserved.
//

#include <stdio.h>

int main(void){
    int n;
    scanf("%d", &n);
    
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
