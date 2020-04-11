//
//  bj11005.cpp
//  이것저것
//
//  Created by 김다원 on 2020/03/27.
//  Copyright © 2020 김다원. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int main(void){
    int n, b;
    cin >> n >> b;
    vector<int> v;
    
    while(1){
        v.push_back(n%b); //나머지를 차례로 벡터에 넣음
        n = n/b;
        if(n == 0) break;
    }
    vector<int>::reverse_iterator iter; //뒤에서부터 꺼내야 하니까
    for(iter = v.rbegin(); iter != v.rend(); iter++){
        if(*iter >= 10){
            char c = *iter-10+'A'; //A=10
            cout << c;
        }else
            cout << *iter;
    }
    cout << "\n";
    return 0;
}
