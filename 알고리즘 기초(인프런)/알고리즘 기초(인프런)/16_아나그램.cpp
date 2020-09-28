//
//  16_아나그램.cpp
//  알고리즘 기초(인프런)
//
//  Created by 김다원 on 2020/09/28.
//

#include <iostream>
using namespace std;

string str1, str2;

int arr[58];

int main(){
    cin >> str1 >> str2;
    for(int i=0; i<str1.size(); i++){
        arr[str1[i]-65]++;
    }
    for(int i=0; i<str2.size(); i++){
        arr[str2[i]-65]--;
    }
    
    for(int i=0; i<58; i++){
        if(arr[i] != 0){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}
