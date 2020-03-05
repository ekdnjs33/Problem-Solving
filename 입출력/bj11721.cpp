//
//  bj11721.cpp
//  입출력
//
//  Created by 김다원 on 2020/03/03.
//  Copyright © 2020 김다원. All rights reserved.
//

#include <stdio.h>

int main(void){
    char s[101];
    scanf("%s", s);
    printf("%c", s[0]);
    for(int i=1; s[i]!='\0'; i++){
        if(i%10 == 0){
            printf("\n");
        }
        printf("%c", s[i]);
    }
    return 0;
}
