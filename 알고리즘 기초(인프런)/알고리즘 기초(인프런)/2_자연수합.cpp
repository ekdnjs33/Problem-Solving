//
//  2_자연수합.cpp
//  알고리즘 기초(인프런)
//
//  Created by 김다원 on 2020/09/26.
//

#include <iostream>
using namespace std;

int a, b, sum = 0;

int main(){
    cin >> a >> b;
    sum = a;
    cout << a;
    for(int i=a+1; i<=b; i++){
        sum += i;
        cout << " + " << i;
    }
    cout << " = " << sum << endl;
    return 0;
}
