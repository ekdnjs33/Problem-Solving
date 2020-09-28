//
//  6_숫자만추출.cpp
//  알고리즘 기초(인프런)
//
//  Created by 김다원 on 2020/09/26.
//

#include <iostream>
#include <cstring>
using namespace std;

string str, new_str = "";
int res, cnt = 0;

int main(){
    cin >> str;
    for(int i=0; i<str.size(); i++){
        if(str[i] >= 48 && str[i] <= 57)
            new_str += str[i];
    }
    res = stoi(new_str);
    
    for(int i=1; i<=res; i++){
        if(res % i == 0)
            cnt++;
    }
    cout << res << "\n" << cnt << endl;
    return 0;
}
