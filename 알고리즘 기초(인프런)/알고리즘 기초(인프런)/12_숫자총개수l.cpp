//
//  12_숫자총개수l.cpp
//  알고리즘 기초(인프런)
//
//  Created by 김다원 on 2020/09/27.
//

#include <iostream>
using namespace std;

int n, sum = 0, cnt = 1, digit = 9, res = 0;

int main(){
    cin >> n;
    while(sum + digit < n){
        sum = sum + digit;
        res = res + (cnt * digit);
        cnt++;
        digit = digit * 10;
    }
    res = res + ((n - sum) * cnt);
    cout << res << endl;
    return 0;
}

