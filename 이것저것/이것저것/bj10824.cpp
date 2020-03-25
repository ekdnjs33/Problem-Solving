//
//  bj10824.cpp
//  이것저것
//
//  Created by 김다원 on 2020/03/25.
//  Copyright © 2020 김다원. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;

int main(void){
   int a, b, c, d;
    cin >> a >> b >> c >> d;
    string s1 = to_string(a) + to_string(b); //a+b결합
    string s2 = to_string(c) + to_string(d); //c+d결합
    
    //a, b, c, d 모두 1,000,000일 경우 long long 값이 나올 수 있다
    long long n1 = stoll(s1);
    long long n2 = stoll(s2);
    cout << n1+n2 << "\n";
    return 0;
}
