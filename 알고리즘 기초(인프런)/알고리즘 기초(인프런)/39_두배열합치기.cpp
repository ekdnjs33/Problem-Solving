//
//  39_두배열합치기.cpp
//  알고리즘 기초(인프런)
//
//  Created by 김다원 on 2020/10/01.
//

#include <iostream>
using namespace std;

int n, m;
int N[100], M[100], arr[200];

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> N[i];
    }
    cin >> m;
    for(int i=0; i<m; i++){
        cin >> M[i];
    }
    
    int x = 0, y = 0, cnt = 0;
    while(x < n && y < m){
        if(N[x] < M[y]){
            arr[cnt++] = N[x++];
        }
        else{
            arr[cnt++] = M[y++];
        }
    }
    while(x < n)
        arr[cnt++] = N[x++];
    while(y < m)
        arr[cnt++] = M[y++];
    
    for(int i=0; i<cnt; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
