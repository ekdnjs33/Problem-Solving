//
//  7_영단어복구.cpp
//  알고리즘 기초(인프런)
//
//  Created by 김다원 on 2020/09/26.
//

#include <iostream>
#include <cstring>
using namespace std;

string str, new_str = "";

int main(){
    getline(cin, str);
    
    for(int i=0; i<str.size(); i++){
        if(str[i] >= 65 && str[i] <= 90)
            new_str += (str[i] + 32);
        else if(str[i] >= 97 && str[i] <= 122)
            new_str += str[i];
    }
    
    cout << new_str << endl;
    return 0;
}
