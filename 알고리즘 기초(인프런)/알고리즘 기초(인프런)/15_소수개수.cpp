//
//  15_소수개수.cpp
//  알고리즘 기초(인프런)
//
//  Created by 김다원 on 2020/09/28.
//

#include <iostream>
using namespace std;

int n, cnt = 0;

bool isPrime(int x){
    if(x == 1)
        return false;
    
    for(int i=2; i*i<=x; i++){
        if(x % i == 0)
            return false;
    }
    return true;
}
int main(){
    cin >> n;
    for(int i=2; i<=n; i++){
        if(isPrime(i)){
            cnt++;
        }
    }
    cout << cnt << endl;
    
    return 0;
}
