//
//  스타트링크.cpp
//  삼성코테준비
//
//  Created by 김다원 on 2020/08/27.
//  Copyright © 2020 김다원. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, min_val = 1000000;
int arr[21][21];
bool selected[21];

void compare_sum(){
    int sum1 = 0, sum2 = 0;
    vector<int> t1, t2;
    for(int i=0; i<n; i++){
        if(selected[i] == true)
            t1.push_back(i);
        else
            t2.push_back(i);
    }
    
    for(int i=0; i<n/2; i++){
        for(int j=0; j<n/2; j++){
            sum1 += arr[t1[i]][t1[j]];
            sum2 += arr[t2[i]][t2[j]];
        }
    }
    min_val = min(min_val, abs(sum1-sum2));
}
void combination(int start, int cnt){
    if(cnt == 0){
        compare_sum();
        return;
    }
    for(int i=start; i<n; i++){
        selected[i] = true;
        combination(i + 1, cnt - 1);
        selected[i] = false;
    }
}
int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }
    combination(0, n/2);
    
    cout << min_val << endl;
    
    return  0;
}
