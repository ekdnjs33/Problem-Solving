//
//  bj10809.cpp
//  이것저것
//
//  Created by 김다원 on 2020/03/20.
//  Copyright © 2020 김다원. All rights reserved.
//

#include <iostream>
#include <stdio.h>
using namespace std;

int main(void){
    char arr[101];
    int cnt[26];
    fill_n(cnt, 26, -1);
    scanf("%s", arr);
    for(int i=0; arr[i] != '\0'; i++){
        int k = arr[i] - 97;
        if(cnt[k] == -1) cnt[k] = i;
    }
    printf("%d", cnt[0]);
    for(int i=1; i<26; i++){
        printf(" %d", cnt[i]);
    }
    printf("\n");
    return 0;
}
