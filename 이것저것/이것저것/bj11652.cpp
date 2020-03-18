//
//  bj11652.cpp
//  이것저것
//
//  Created by 김다원 on 2020/03/17.
//  Copyright © 2020 김다원. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
using namespace std;

int main(void){
    int n;
    scanf("%d", &n);
    long long arr[n];
    for(int i=0; i<n; i++){
        scanf("%lld", &arr[i]);
    }
    sort(arr, arr+n);
    
    long long ans = arr[0];
    int max =1, cnt = 1;
    for(int i=1; i<n; i++){
        if(arr[i-1] == arr[i]) cnt++;
        else cnt = 1;
        
        if(cnt > max){
            max = cnt;
            ans = arr[i];
        }
    }
    printf("%lld\n", ans);
    return 0;
}
