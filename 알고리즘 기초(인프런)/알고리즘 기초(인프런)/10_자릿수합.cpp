//
//  10_자릿수합.cpp
//  알고리즘 기초(인프런)
//
//  Created by 김다원 on 2020/09/26.
//

#include <iostream>
using namespace std;

int n, max_sum = 0, max_num;

int digit_sum(int num){
    int res = 0;
    while(num > 0){
        res += (num % 10);
        num = num / 10;
    }
    return res;
}
int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        
        int sum = digit_sum(a);
        if(max_sum < sum){
            max_sum = sum;
            max_num = a;
        }
        else if(max_sum == sum){
            if(max_num < a)
                max_num = a;
        }
    }
    cout << max_num << endl;
    return 0;
}
