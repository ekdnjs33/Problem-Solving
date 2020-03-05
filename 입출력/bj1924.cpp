//
//  bj1924.cpp
//  입출력
//
//  Created by 김다원 on 2020/03/03.
//  Copyright © 2020 김다원. All rights reserved.
//

#include <stdio.h>

int main(void){
    char week[7][10] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    int month[12] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
    int m, d, total=0, val;
    
    scanf("%d %d", &m, &d);
    for(int i=0; i<m; i++){
        total+=month[i];
    }
    total+=d;
    val=total%7;
    printf("%s\n", week[val]);
    return 0;
}
