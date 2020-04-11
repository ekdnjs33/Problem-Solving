//
//  bj1780.cpp
//  분할정복
//
//  Created by 김다원 on 2020/04/02.
//  Copyright © 2020 김다원. All rights reserved.
//

#include <iostream>
using namespace std;

int N;
int map[2200][2200]; // 3의 7승 = 2187
int ans[3]; // -1, 0, 1개수 세는 배열

bool check(int a, int b, int n) {
    int test = map[a][b];
    for(int i=a; i<a+n; i++) {
        for(int j=b; j<b+n; j++) {
            if(test != map[i][j]) return false;
        }
    }
    return true;
}
int divide(int a, int b, int n) {
    if(check(a, b, n)) { // 모두 같으면
        ans[map[a][b]+1]++;
    }
    else { // 같지 않으면 9등분으로 나눠
        int newsize = n/3;
        for (int i=0; i<3; i++) {
            for (int j=0; j<3; j++) {
                divide(a + newsize*i, b + newsize*j, newsize);
            }
        }
    }
    return 0;
}
int main() {
    cin >> N;
    for(int i =0; i<N; i ++) {
        for(int j=0; j<N; j ++) {
            cin >> map[i][j];
        }
    }
    
    divide(0, 0, N);
    for(int i=0; i<3; i++){
        cout << ans[i] << "\n";
    }
    return 0;
}
