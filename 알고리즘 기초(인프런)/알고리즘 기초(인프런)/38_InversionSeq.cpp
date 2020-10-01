//
//  38_InversionSeq.cpp
//  알고리즘 기초(인프런)
//
//  Created by 김다원 on 2020/10/01.
//

#include <iostream>
using namespace std;

int n;
int seq[101];

int main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        int num;
        cin >> num;
        
        int cnt = 0;
        for(int j=1; j<=n; j++){
            if(cnt == num && seq[j] == 0){
                seq[j] = i;
                break;
            }
            if(seq[j] == 0)
                cnt++;
        }
    }
    
    for(int i=1; i<=n; i++){
        cout << seq[i] << " ";
    }
    cout << endl;
    return  0;
}
