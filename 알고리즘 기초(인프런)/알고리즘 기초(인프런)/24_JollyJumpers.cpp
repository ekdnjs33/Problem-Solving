//
//  24_JollyJumpers.cpp
//  알고리즘 기초(인프런)
//
//  Created by 김다원 on 2020/09/30.
//

#include <iostream>
#include <cmath>
using namespace std;

int n, start;
bool arr[100];

int main(){
    cin >> n;
    cin >> start;
    for(int i=1; i<n; i++){
        int num;
        cin >> num;
        
        arr[abs(start-num)] = true;
        start = num;
    }
    for(int i=1; i<n; i++){
        if(arr[i] == false){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}
