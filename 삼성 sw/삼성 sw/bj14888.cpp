//
//  bj14888.cpp
//  삼성 sw
//
//  Created by 김다원 on 2020/04/15.
//  Copyright © 2020 김다원. All rights reserved.
//

/* 연산자 끼워넣기 */
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int n;
int arr[12], calc[12];
bool Select[12];
long long Max = -1000000000;
long long Min = 1000000000;
vector<int> V;

void permutation(int cnt, int size){
    if(cnt == size){
        int x = arr[0];
        for(int i=0; i<size; i++){
            if(V[i] == 0)
                x += arr[i+1];
            else if(V[i] == 1)
                x -= arr[i+1];
            else if(V[i] == 2)
                x *= arr[i+1];
            else{
                if(x < 0){
                    x = abs(x)/arr[i+1];
                    x = -x;
                }else
                    x = x/arr[i+1];
            }
        }
        if(x > Max) Max = x;
        if(x < Min) Min = x;
        return;
    }
    for(int i=0; i<size; i++){
        if(Select[i] == true) continue;
        Select[i] = true;
        V.push_back(calc[i]);
        permutation(cnt+1, size);
        V.pop_back();
        Select[i] = false;
    }
}
int main(){
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> arr[i];
    
    int k=0;
    for(int i=0; i<4; i++){
        int c;
        cin >> c;
        for(int j=0; j<c; j++){
            calc[k] = i;
            k++;
        }
    }
    permutation(0, k);
    cout << Max << "\n" << Min << "\n";
    return 0;
}
