//
//  bj11718.cpp
//  입출력
//
//  Created by 김다원 on 2020/03/03.
//  Copyright © 2020 김다원. All rights reserved.
//

#include <stdio.h>

int main(void){
    char* s;
    while (fgets(s, 101, stdin)){
        printf("%s", s);
    }
    return 0;
}
