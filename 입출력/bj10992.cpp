//
//  bj10992.cpp
//  입출력
//
//  Created by 김다원 on 2020/03/05.
//  Copyright © 2020 김다원. All rights reserved.
//

#include <stdio.h>

int main(void){
    int n, mid;
    scanf("%d", &n);
    mid = n-1;
    for(int i=1; i<=n; i++){
        if(i==n)
            for(int j=0; j<2*n-1; j++) printf("*");
        else{
            for(int j=0; j<n-i; j++) printf(" ");
            for(int j=n-i; j<n+i-1; j++){
                if(j == mid-(i-1) || j == mid+(i-1)) printf("*");
                else printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
