//
//  1392.cpp
//  코딩테스트_길라잡이
//
//  Created by 김다원 on 2020/08/16.
//  Copyright © 2020 김다원. All rights reserved.
//

#include <iostream>
using namespace std;

int main(){
    int n, q;
    int k, sum = 0;
    int melody[101];
    
    cin >> n >> q;
    for(int i=1; i<=n; i++){
        cin >> k;
        sum += k;
        melody[i] = sum;
    }
    for(int i=0; i<q; i++){
        cin >> k;
        for(int j=1; j<=n; j++){
            if(k/melody[j] == 0){
                cout << j << "\n";
                break;
            }
        }
    }
}

