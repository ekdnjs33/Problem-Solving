//
//  1_배수합.cpp
//  알고리즘 기초(인프런)
//
//  Created by 김다원 on 2020/09/26.
//

#include <iostream>
using namespace std;

int n, m, sum = 0;

int main(){
    cin >> n >> m;
    for(int i=m; i<=n; i+=m){
        sum += i;
    }
    cout << sum << endl;
    return  0;
}
