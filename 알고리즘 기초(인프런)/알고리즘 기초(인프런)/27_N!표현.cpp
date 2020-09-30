//
//  27_N!표현.cpp
//  알고리즘 기초(인프런)
//
//  Created by 김다원 on 2020/10/01.
//

#include <iostream>
#include <vector>
using namespace std;

int n;
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
    cout << n << "! = ";
    for(int i=0; i<arr.size(); i++){
        cout << cnt[i] << " ";
    }
    cout << endl;
    
    return 0;
}
/*
    for(i=2; i<=n; i++){
         tmp=i;
         j=2;
         while(1){
             if(tmp % j == 0){
                 ch[j]++;
                 tmp = tmp / j;
             }else
                j++;
             if(tmp == 1) break;
         }
     }
     for(j=2; j<=n; j++){
         if(ch[j] != 0) print
     }
 */
