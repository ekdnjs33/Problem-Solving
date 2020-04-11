//
//  bj1517.cpp
//  분할정복
//
//  Created by 김다원 on 2020/04/04.
//  Copyright © 2020 김다원. All rights reserved.
//

#include <iostream>
using namespace std;

int A[500000];
int cnt = 0;
/* bubble sort 이용하면 시간초과가 나는 문제
 bubble sort에서 swap 조건을 이용해 merge sort 사용해야한다.*/
int bubble(int n){
    for(int i=0; i<n-1; i++){
        int check = cnt;
        for(int j=n-1; j>i; j--){
            if(A[j-1] > A[j]){
                int tmp = A[j-1];
                A[j-1] = A[j];
                A[j] = tmp;
                cnt++;
            }
        }
        if(check == cnt) break;
    }
    return cnt;
}
int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> A[i];

    cout << bubble(n);
    return 0;
}
