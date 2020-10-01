//
//  32_선택정렬.cpp
//  알고리즘 기초(인프런)
//
//  Created by 김다원 on 2020/10/01.
//

#include <iostream>
using namespace std;

int n;
int arr[100];

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    for(int i=0; i<n-1; i++){
        int idx = i;
        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[idx])
                idx = j;
        }
        int tmp = arr[i];
        arr[i] = arr[idx];
        arr[idx] = tmp;
    }
    
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
