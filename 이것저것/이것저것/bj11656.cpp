//
//  bj11656.cpp
//  이것저것
//
//  Created by 김다원 on 2020/03/25.
//  Copyright © 2020 김다원. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int main(void){
    string a, temp;
    cin >> a;
    long n = a.length();
    //string b[n];
    vector<string> b;
    for(int i=0; i<n; i++){
        temp = a.substr(i);
        b.push_back(temp);
        //b[i] = a.substr(i);
    }
    sort(b.begin(), b.end()); //vector로 할 때
    //sort(b, b+n); //배열로 할 때
    for(int i=0; i<n; i++){
        cout << b[i] << "\n";
    }
    return 0;
}
