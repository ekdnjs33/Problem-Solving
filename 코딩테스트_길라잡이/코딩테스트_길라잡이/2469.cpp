//
//  2469.cpp
//  코딩테스트_길라잡이
//
//  Created by 김다원 on 2020/08/16.
//  Copyright © 2020 김다원. All rights reserved.
//

#include <iostream>
using namespace std;

int main(){
    int k, n;
    cin >> k >> n;
    char arr[k];
    char map[n][k-1];
    char arr1[k], arr2[k];
    
    for(int i=0; i<k; i++)
        cin >> arr[i];
    
    for(int i=0; i<n; i++){
        for(int j=0; j<k-1; j++)
            cin >> map[i][j];
    }
    for(int i=0; i<k; i++){
        
    }
}
