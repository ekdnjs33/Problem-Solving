//
//  bj2751.cpp
//  이것저것
//
//  Created by 김다원 on 2020/03/12.
//  Copyright © 2020 김다원. All rights reserved.
//

#include <stdio.h>

int arr[1000000];
void sort(int* a, int n){ // 선택 정렬 = 시간 초과
    int tmp;
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(a[i] > a[j]){
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
}
void qsort(int *array, int left, int right) { // 퀵 정렬
    int mLeft = left, mRight = right;
    int pivot = array[(left+right)/2];
    int tmp;
    
    while(mLeft <= mRight) {
        while(pivot > array[mLeft]) mLeft++;
        while(pivot < array[mRight]) mRight--;
        
        if(mLeft <= mRight) {
            tmp = arr[mLeft];
            arr[mLeft] = arr[mRight];
            arr[mRight] = tmp;
            mLeft++;
            mRight--;
        }
    }
    if(left < mRight) qsort(arr, left, mRight);
    if(mLeft < right) qsort(arr, mLeft, right);
}
int main(void){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    qsort(arr, 0, n-1);
    for(int i=0; i<n; i++)
        printf("%d\n", arr[i]);
    return 0;
}
