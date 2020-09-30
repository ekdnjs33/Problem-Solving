//
//  26_마라톤.cpp
//  알고리즘 기초(인프런)
//
//  Created by 김다원 on 2020/09/30.
//

#include <iostream>
using namespace std;

int n;
int arr[10001];

int main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }
    for(int i=1; i<=n; i++){
        int ranking = i;
        for(int j=1; j<i; j++){
            if(arr[i] > arr[j])
                ranking--;
        }
        cout << ranking << " ";
    }
    cout << endl;
    return 0;
}
