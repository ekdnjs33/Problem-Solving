//
//  bj10814.cpp
//  이것저것
//
//  Created by 김다원 on 2020/03/16.
//  Copyright © 2020 김다원. All rights reserved.
//

#include <iostream>
#include <algorithm>
using  namespace std;

int n;
pair<int, string> A[100001];
bool cmp(pair<int, string> a, pair<int, string> b){
    if(a.first < b.first){
        return true;
    }
    else return false;
}
int main(void){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> A[i].first >> A[i].second;
    }
    stable_sort(A, A+n, cmp);
    
    for(int i=0; i<n; i++){
        cout << A[i].first << " " << A[i].second << "\n";
    }
    return 0;
}
