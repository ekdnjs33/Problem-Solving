//
//  bj1373.cpp
//  이것저것
//
//  Created by 김다원 on 2020/03/27.
//  Copyright © 2020 김다원. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int main(void){
    string str;
    //vector<int> res;
    cin >> str;
    //long long num = 0;
    int len = str.size();
    if(len%3 == 1){
        cout << str[0];
    }
    else if(len%3 == 2){
        cout << (str[0]-'0')*2 + (str[1]-'0');
    }
    for(int i=len%3; i<len; i+=3){
        cout << (str[i]-'0')*4 + (str[i+1]-'0')*2 + (str[i+2]-'0');
    }
    /*for(int i=len-1; i>=0; i--){ //10진법으로 변환
        int a = str[i]-48;
        num += a*pow(2, len-i);
    }
    cout << num << "\n";
    while(1){
        res.push_back(num%8); //나머지를 차례로 벡터에 넣음
        num = num/8;
        if(num == 0) break;
    }
    vector<int>::reverse_iterator iter;
    for(iter = res.rbegin(); iter != res.rend(); iter++){
        cout << *iter;
    }*/
    cout << "\n";
    return 0;
}
