//
//  QuickSort.cpp
//  자료구조
//
//  Created by 김다원 on 2020/08/09.
//  Copyright © 2020 김다원. All rights reserved.
//

#include <iostream>
using namespace std;

void swap(int *arr, int a, int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

int Partition(int *arr, int start, int end){ //두 파트로 나누는 기준
    int pivot = arr[(start+end)/2];
    
    while(start <= end){
        while(arr[start] < pivot) start++;
        while(arr[end] > pivot) end--;
        
        if(start <= end){
            swap(arr, start, end);
            start++;
            end--;
        }
    }
    return start;
}

void QuickSort(int *arr, int start, int end){ //두 파트로 나눠서 각각 퀵 소트
    int part2 = Partition(arr, start, end);
    
    if(start < part2-1){
        QuickSort(arr, start, part2-1);
    }
    if(part2 < end){
        QuickSort(arr, part2, end);
    }
}

int main(){
    int arr[] = {3, 9, 4, 7, 5, 0, 1, 6, 8, 2};
    for(int i=0; i<10; i++){
        cout << arr[i] << " ";
    }
    QuickSort(arr, 0, 9);
    cout << "\n";
    for(int i=0; i<10; i++){
        cout << arr[i] << " ";
    }
}
