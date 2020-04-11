//
//  bj2745.cpp
//  이것저것
//
//  Created by 김다원 on 2020/03/27.
//  Copyright © 2020 김다원. All rights reserved.
//

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(void){
    string str;
    int b, num = 0, s;
    cin >> str >> b;
    int len = str.size()-1;
    for(int i=len; i>=0; i--){
        if(str[i] >= 48 && str[i] <= 57){
            s = str[i]-48;
            num += s*pow(b, len-i);
        }
        else if(str[i] >= 'A' && str[i] <= 'Z'){
            s = str[i]-55;
            num += s*pow(b, len-i);
        }
    }
    cout << num << "\n";
    return 0;
}
