//
//  bj11720.cpp
//  입출력
//
//  Created by 김다원 on 2020/03/03.
//  Copyright © 2020 김다원. All rights reserved.
//

#include <stdio.h>

int main(void){
    int t, sum=0;
    char s[101];
    scanf("%d", &t);
    scanf("%s", s);
    for(int i=0; i<t; i++){
        sum += s[i]-48;
    }
    printf("%d\n", sum);
    return 0;
}
