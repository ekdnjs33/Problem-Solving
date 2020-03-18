//
//  bj11651.cpp
//  이것저것
//
//  Created by 김다원 on 2020/03/16.
//  Copyright © 2020 김다원. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
using  namespace std;

int N;
pair<int, int> A[100001];
bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.first < b.first){
        return true;
    }
    else if(a.first == b.first){
        if(a.second < b.second) return true;
        else return false;
    }
    else return false;
}
int main(void){
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%d %d", &A[i].second, &A[i].first);
    }
    sort(A, A+N, cmp);
    
    for(int i=0; i<N; i++){
        printf("%d %d\n", A[i].second, A[i].first);
    }
    return 0;
}
