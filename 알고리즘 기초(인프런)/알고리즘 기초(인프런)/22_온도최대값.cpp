//
//  22_온도최대값.cpp
//  알고리즘 기초(인프런)
//
//  Created by 김다원 on 2020/09/30.
//

#include <iostream>
#include <vector>
using namespace std;

int n, k, res, sum = 0;
vector<int> arr;

int main(){
    cin >> n >> k;
    for(int i=0; i<n; i++){
        int num;
        cin >> num;
        arr.push_back(num);
    }
    
    for(int i=0; i<k; i++){
            sum += arr[i];
        }
    res = sum;
    for(int i=k; i<n; i++){
        sum = sum + arr[i] - arr[i-k];
        if(sum > res)
            res = sum;
    }
    cout << res << endl;
    
    return 0;
}
