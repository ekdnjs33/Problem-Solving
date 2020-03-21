//
//  bj11655.cpp
//  이것저것
//
//  Created by 김다원 on 2020/03/20.
//  Copyright © 2020 김다원. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int main(void){
    string s;
    char a;
    getline(cin, s);
    for(int i=0; i<s.size(); i++){
        if(s[i] >= 'a' && s[i] <= 'z'){ //97
            a = (s[i]-97+13)%26+97;
            cout << a;
        }
        else if(s[i] >= 'A' && s[i] <= 'Z'){ //65
            a = (s[i]-65+13)%26+65;
            cout << a;
        }
        else{
            cout << s[i];
        }
    }
    cout << "\n";
    return 0;
}
