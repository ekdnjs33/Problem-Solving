//
//  bj2446.cpp
//  입출력
//
//  Created by 김다원 on 2020/03/05.
//  Copyright © 2020 김다원. All rights reserved.
//

#include <stdio.h>

int main(void){
    int n;
    scanf("%d", &n);
    for(int i=1; i<n; i++){
        for(int j=1; j<i; j++) printf(" ");
        for(int j=i; j<=2*n-i; j++) printf("*");
        printf("\n");
    }
    for(int i=n; i<2*n; i++){
        for(int j=1; j<2*n-i; j++) printf(" ");
        for(int j=2*n-i; j<=i; j++) printf("*");
        printf("\n");
    }
    return 0;
}
