//
//  28_N!의0의개수.cpp
//  알고리즘 기초(인프런)
//
//  Created by 김다원 on 2020/10/01.
//

#include <iostream>
#include <vector>
using namespace std;

int n, res;
vector<int> arr;
int cnt[1000];

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
    for(int i=1; i<=n; i++){
        if(isPrime(i))
            arr.push_back(i);
    }
    
    for(int i=n; i>1; i--){
        int num = i;
        int k = 0;
        while(num > 1){
            if(num % arr[k] == 0){
                cnt[k]++;
                num /= arr[k];
            }
            else
                k++;
        }
    }
    if(cnt[0] > cnt[2])
        res = cnt[2];
    else
        res = cnt[0];
    cout << res << endl;
    
    return 0;
}
