//
//  33_3등성적?.cpp
//  알고리즘 기초(인프런)
//
//  Created by 김다원 on 2020/10/01.
//

#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[100];

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr, arr+n, greater<>()); //내림차순 정렬
    
    int idx = 1;
    for(int i=1; i<n; i++){
        if(arr[i-1] != arr[i])
            idx++;
        
        if(idx == 3){
            cout << arr[i] << endl;
            break;
        }
    }
    return 0;
}
