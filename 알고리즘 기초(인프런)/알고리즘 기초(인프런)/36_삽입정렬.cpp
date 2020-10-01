//
//  36_삽입정렬.cpp
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
    
    for(int i=0; i<n; i++){
        int j;
        int tmp = arr[i];
        for(j=i-1; j>=0; j--){
            if(arr[j] > tmp){
                arr[j+1] = arr[j];
            }
            else
                break;
        }
        arr[j+1] = tmp;
    }
    
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
