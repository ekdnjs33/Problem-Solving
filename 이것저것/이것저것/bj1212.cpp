//
//  bj1212.cpp
//  이것저것
//
//  Created by 김다원 on 2020/03/28.
//  Copyright © 2020 김다원. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int main(void){
    string str;
    cin >> str;
    string t[8] = {"0", "1", "10", "11", "100", "101", "110", "111"};
    
    auto len = str.size();
    cout << t[str[0]-'0'];
    for(int i=1; i<len; i++){
        int k = str[i]-'0';
        if(k == 0 || k == 1){
            cout << "00" << t[k];
        }else if(k ==2 || k ==3){
            cout << "0" << t[k];
        }else{
            cout << t[k];
        }
    }
    cout << "\n";
    return 0;
}

