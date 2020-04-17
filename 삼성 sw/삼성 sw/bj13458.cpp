//
//  bj13458.cpp
//  삼성 sw
//
//  Created by 김다원 on 2020/04/14.
//  Copyright © 2020 김다원. All rights reserved.
//

/* 시험 감독 */
#include <iostream>
using namespace std;

int n, b, c; //시험장 수, 총감독 감시자 수, 부감독 감시자 수
long long num = 0; //전체 감독 수
int A[1000001]; //시험장 응시자 수
int main(){
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> A[i];
    cin >> b >> c;
    for(int i=0; i<n; i++){
        num++;
        A[i] -= b;
        if(A[i] > 0){
            if(A[i]%c > 0)
                num = num + A[i]/c + 1;
            else
                num = num + A[i]/c;
        }
    }
    cout << num << "\n";
}
