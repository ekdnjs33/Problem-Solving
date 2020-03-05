//
//  bj2445.cpp
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
        for(int j=0; j<n; j++){
            if(j<i+1)
                printf("*");
            else
                printf(" ");
        }
        for(int j=n; j<2*n; j++){
            if(j+i>2*n-2)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
    for(int i=n; i<2*n-1; i++){
        for(int j=0; j<n; j++){
            if(j<2*n-1-i)
                printf("*");
            else
                printf(" ");
        }
        for(int j=n; j<2*n; j++){
            if(j>i)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}
