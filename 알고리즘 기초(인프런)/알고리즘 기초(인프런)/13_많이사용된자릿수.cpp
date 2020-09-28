//
//  13_많이사용된자릿수.cpp
//  알고리즘 기초(인프런)
//
//  Created by 김다원 on 2020/09/28.
//

#include <iostream>
#include <cstring>
using namespace std;

string n;
int max_val = 0, res;
int arr[10];

int main(){
    cin >> n;
    
    for(int i=0; i<n.size(); i++){
        int k = n[i] - 48;
        arr[k]++;
    }
    
    for(int i=0; i<10; i++){
        if(max_val <= arr[i]){
            max_val = arr[i];
            res = i;
        }
    }
    cout << res << endl;
    
    return 0;
}
