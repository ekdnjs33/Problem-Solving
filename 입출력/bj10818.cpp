//
//  bj10818.cpp
//  입출력
//
//  Created by 김다원 on 2020/03/04.
//  Copyright © 2020 김다원. All rights reserved.
//

#include <stdio.h>

int main(void){
    int n, num, max=-1000000, min=1000000;
    scanf("%d", &n);
    
    for(int i=0; i<n; i++){
        scanf("%d", &num);
        if(num>max)
            max=num;
        if(min>num)
            min=num;
    }
    printf("%d %d\n", min, max);
    return 0;
}
