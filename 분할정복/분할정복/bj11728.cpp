//
//  bj11728.cpp
//  분할정복
//
//  Created by 김다원 on 2020/04/01.
//  Copyright © 2020 김다원. All rights reserved.
//

#include <iostream>
using namespace std;

int main(void){
    int n, m;
    cin >> n >> m;
    int A[n], B[m], C[n+m];
    for(int i=0; i<n; i++) cin >> A[i];
    for(int i=0; i<m; i++) cin >> B[i];
    
    /* merge sort 합치기 부분 */
    int i=0, j=0, k=0;
    while(i<n && j<m){
        if(A[i] <= B[j]) C[k++] = A[i++];
        else C[k++] = B[j++];
    }
    while(i<n) C[k++] = A[i++];
    while(j<m) C[k++] = B[j++];
        
    for(int i=0; i<n+m; i++)
        cout << C[i] << ' ';
    cout << '\n';
    return 0;
}
