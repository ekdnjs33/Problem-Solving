//
//  bj1992.cpp
//  분할정복
//
//  Created by 김다원 on 2020/04/03.
//  Copyright © 2020 김다원. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int map[65][65];
bool check(int a, int b, int n){
    int tmp = map[a][b];
    for(int i=a; i<a+n; i++){
        for(int j=b; j<b+n; j++){
            if(tmp != map[i][j])
                return false;
        }
    }
    return true;
}
void divide(int a, int b, int n){
    if(check(a, b, n)){
        cout << map[a][b];
    }
    else{
        int newsize = n/2;
        cout << "(";
        for(int i=0; i<2; i++){
            for(int j=0; j<2; j++)
                divide(a+i*newsize, b+j*newsize, newsize);
        }
        cout << ")";
    }
}
int main(){
    int n;
    cin >> n;
    string str;
    for(int i=0; i<n; i++){
        cin >> str;
        for(int j=0; j<n; j++){
            map[i][j] = str[j]-'0';
        }
    }
    /*for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            cout << map[i][j] << " ";
        cout << "\n";
    }*/
    divide(0, 0, n);
    return 0;
}
