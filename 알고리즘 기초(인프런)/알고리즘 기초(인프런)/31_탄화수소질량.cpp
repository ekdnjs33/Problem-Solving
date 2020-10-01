//
//  31_탄화수소질량.cpp
//  알고리즘 기초(인프런)
//
//  Created by 김다원 on 2020/10/01.
//

#include <iostream>
#include <cstring>
using namespace std;

string str;

int main(){
    cin >> str;
    long x = str.find('C');
    long y = str.find('H');
    
    int x_num = 1;
    int y_num = 1;
    if(x+1 != y){
        x_num = stoi(str.substr(x+1, y-1));
    }
    if(y+1 != str.size()){
        y_num = stoi(str.substr(y+1));
    }
    int res = 12 * x_num + 1 * y_num;
    cout << res << endl;
    return 0;
}
