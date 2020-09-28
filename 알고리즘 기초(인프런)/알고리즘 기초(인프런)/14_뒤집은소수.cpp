//
//  14_뒤집은소수.cpp
//  알고리즘 기초(인프런)
//
//  Created by 김다원 on 2020/09/28.
//

#include <iostream>
using namespace std;

int n;

int reverse(int x){
    int num = 0;
    while(x > 0){
        num = (num * 10) + (x % 10);
        x = x / 10;
    }
    return num;
}
bool isPrime(int nx){
    if(nx == 1)
        return false;
    
    for(int i=2; i<nx/2; i++){
        if(nx % i == 0)
            return false;
    }
    return true;
}
int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        int nx = reverse(x);
        if(isPrime(nx))
            cout << nx << " ";
    }
    cout << endl;
    
    return 0;
}
