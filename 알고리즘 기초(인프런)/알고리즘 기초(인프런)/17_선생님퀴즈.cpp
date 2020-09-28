//
//  17_선생님퀴즈.cpp
//  알고리즘 기초(인프런)
//
//  Created by 김다원 on 2020/09/28.
//

#include <iostream>
using namespace std;

int n;

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        int num, ans;
        cin >> num >> ans;
        
        int sum = 0;
        for(int i=1; i<=num; i++)
            sum += i;
        
        if(sum == ans)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    
    return 0;
}
