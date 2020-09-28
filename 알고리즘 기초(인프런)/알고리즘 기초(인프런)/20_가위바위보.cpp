//
//  20_가위바위보.cpp
//  알고리즘 기초(인프런)
//
//  Created by 김다원 on 2020/09/29.
//

#include <iostream>
using namespace std;

int n;
int A[101], B[101];

int main(){
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> A[i];
    for(int i=0; i<n; i++)
        cin >> B[i];
    
    for(int i=0; i<n; i++){
        int res = A[i] - B[i];
        if(res == 0)
            cout << "D" << endl;
        else if(res == 1 || res == -2)
            cout << "A" << endl;
        else
            cout << "B" << endl;
    }
    
    return 0;
}
