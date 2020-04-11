//
//  bj2447.cpp
//  분할정복
//
//  Created by 김다원 on 2020/04/03.
//  Copyright © 2020 김다원. All rights reserved.
//

#include <iostream>
using namespace std;

char map[2200][2200];
void divide(int a, int b, int n){
    if(n == 1) map[a][b] = '*';
    else{
        int newsize = n/3;
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(i != 1 || j != 1)
                    divide(a+newsize*i, b+newsize*j, newsize);
            }
        }
    }
}
int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            map[i][j] = ' ';
    }
    divide(0, 0, n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            cout << map[i][j];
        cout << "\n";
    }
    return 0;
}
