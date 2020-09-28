//
//  8_올바른괄호.cpp
//  알고리즘 기초(인프런)
//
//  Created by 김다원 on 2020/09/26.
//

#include <iostream>
using namespace std;

string str;
int cnt = 0;

int main(){
    cin >> str;
    for(int i=0; i<str.size(); i++){
        if(str[i] == '(')
            cnt++;
        else if(str[i] == ')')
            cnt--;
        if(cnt < 0)
            break;
    }
    
    if(cnt == 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
