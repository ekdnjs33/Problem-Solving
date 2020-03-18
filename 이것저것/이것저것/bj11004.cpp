//
//  bj11004.cpp
//  이것저것
//
//  Created by 김다원 on 2020/03/18.
//  Copyright © 2020 김다원. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
using namespace std;

int main(void){
    int n, k;
    scanf("%d %d", &n, &k);
    int arr[n];
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    sort(arr, arr+n);
    printf("%d\n", arr[k-1]);
    return 0;
}
