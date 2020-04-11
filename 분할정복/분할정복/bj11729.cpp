//
//  bj11729.cpp
//  분할정복
//
//  Created by 김다원 on 2020/04/02.
//  Copyright © 2020 김다원. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int res=0;
vector<int> fir;
vector<int> sec;
void hanoi(int n, int from, int mid, int to){
    if(n == 1){
        fir.push_back(from);
        sec.push_back(to);
        res++;
    }
    else{
        hanoi(n-1, from, to, mid);
        fir.push_back(from);
        sec.push_back(to);
        res++;
        hanoi(n-1, mid, from, to);
    }
}
int main(){
    int n;
    cin >> n;
    hanoi(n, 1, 2, 3);
    cout << res << "\n";
    for(int i=0; i<res; i++){
        cout << fir[i] << " " << sec[i] << "\n";
    }
    return 0;
}
