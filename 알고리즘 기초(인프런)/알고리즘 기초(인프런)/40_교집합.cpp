//
//  40_교집합.cpp
//  알고리즘 기초(인프런)
//
//  Created by 김다원 on 2020/10/01.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> arr;

int main(){
    cin >> n;
    vector<int> A(n);
    for(int i=0; i<n; i++){
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    
    cin >> m;
    vector<int> B(m);
    for(int i=0; i<m; i++){
        cin >> B[i];
    }
    sort(B.begin(), B.end());
    
    int x = 0, y = 0;
    while(x < n && y < m){
        if(A[x] == B[y]){
            arr.push_back(A[x++]);
            y++;
        }
        else if(A[x] < B[y])
            x++;
        else
            y++;
    }
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
