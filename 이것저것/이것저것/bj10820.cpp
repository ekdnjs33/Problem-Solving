//
//  bj10820.cpp
//  이것저것
//
//  Created by 김다원 on 2020/03/20.
//  Copyright © 2020 김다원. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int main(void){
    string arr;
    while(true){
        getline(cin, arr);
        if(arr.size() == 0) break;

        int a = 0, b = 0, n = 0, s = 0;
        for(int i=0; arr[i] != '\0'; i++){
            if(arr[i] >= 'a' && arr[i] <= 'z') a++;
            else if(arr[i] >= 'A' && arr[i] <= 'Z') b++;
            else if(arr[i] >= '0' && arr[i] <= '9') n++;
            else if(arr[i] == ' ') s++;
        }
        cout << a << " " << b << " " << n << " " << s << "\n";
    }
    return 0;
}
