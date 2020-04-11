//
//  bj2448.cpp
//  분할정복
//
//  Created by 김다원 on 2020/04/03.
//  Copyright © 2020 김다원. All rights reserved.
//

#include <iostream>
using namespace std;

char DB[][6]=
{ "  *  ",
  " * * ",
  "*****" };
char map[3500][6500];
void divide(int a, int b, int n){
    //cout << n << "," << a << "," << b << "\n";
    if(n == 1){
        for (int i=0; i<3; i++)
            for (int j=0; j<5; j++)
                map[a+i][b+j] = DB[i][j];
        return;
    }
    divide(a, b+3*n/2, n/2);
    divide(a+3*n/2, b, n/2);
    divide(a+3*n/2, b+3*n, n/2);
}
int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<2*n-1; j++)
            map[i][j] = ' ';
    }
    divide(0, 0, n/3);
    for(int i=0; i<n; i++){
        for(int j=0; j<2*n-1; j++)
            cout << map[i][j];
        cout << "\n";
    }
    return 0;
}
