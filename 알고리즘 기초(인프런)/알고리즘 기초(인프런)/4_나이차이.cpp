//
//  4_나이차이.cpp
//  알고리즘 기초(인프런)
//
//  Created by 김다원 on 2020/09/26.
//

#include <iostream>
using namespace std;

int n, max_val = 0, min_val = 1000, res;

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        int age;
        cin >> age;
        
        if(max_val < age)
            max_val = age;
        
        if(min_val > age)
            min_val = age;
    }
    res = max_val - min_val;
    cout << res << endl;
    return 0;
}
