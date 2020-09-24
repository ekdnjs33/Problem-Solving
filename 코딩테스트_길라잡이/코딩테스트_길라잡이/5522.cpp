//
//  5522.cpp
//  코딩테스트_길라잡이
//
//  Created by 김다원 on 2020/08/16.
//  Copyright © 2020 김다원. All rights reserved.
//

#include <iostream>
using namespace std;

int main(){
    int k;
    int sum = 0;
    for(int i=0; i<5; i++){
        cin >> k;
        sum += k;
    }
    cout << sum << "\n";
}
