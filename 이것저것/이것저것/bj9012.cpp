//
//  bj9012.cpp
//  이것저것
//
//  Created by 김다원 on 2020/03/18.
//  Copyright © 2020 김다원. All rights reserved.
//

#include <stdio.h>

char arr[51];
int main(void){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        int num = 0;
        scanf("%s", arr);
        for(int j=0; arr[j] != '\0'; j++){
            if(arr[j] == '(')
                num++;
            else if(arr[j] == ')')
                num--;
            if(num < 0){
                break;
            }
        }
        if(num == 0) printf("YES\n");
        else printf("NO\n");
    }
}
