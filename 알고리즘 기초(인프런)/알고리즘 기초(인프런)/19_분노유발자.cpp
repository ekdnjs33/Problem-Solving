//
//  19_분노유발자.cpp
//  알고리즘 기초(인프런)
//
//  Created by 김다원 on 2020/09/29.
//

#include <iostream>
using namespace std;

int n, cnt = 0;
int arr[101];

int main(){
    cin >> n;
    for(int i=1; i<=n; i++)
        cin >> arr[i];
    
    int max = arr[n];
    for(int i=n-1; i>=1; i--){
        if(max < arr[i]){
            max = arr[i];
            cnt++;
        }
    }
    cout << cnt << endl;
    
    return 0;
}
