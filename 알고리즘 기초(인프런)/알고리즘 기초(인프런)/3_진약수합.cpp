//
//  3_진약수합.cpp
//  알고리즘 기초(인프런)
//
//  Created by 김다원 on 2020/09/26.
//

#include <iostream>
using namespace std;

int n, sum = 1;

int main(){
    cin >> n;
    cout << 1;
    for(int i=2; i<n; i++){
        if(n % i == 0){
            sum += i;
            cout << " + " << i;
        }
    }
    cout << " = " << sum << endl;
    return 0;
}
