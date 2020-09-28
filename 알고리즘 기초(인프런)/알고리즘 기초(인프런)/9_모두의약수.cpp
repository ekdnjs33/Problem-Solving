//
//  9_모두의약수.cpp
//  알고리즘 기초(인프런)
//
//  Created by 김다원 on 2020/09/26.
//

#include <iostream>
using namespace std;

int n;
int cnt[50001];

int main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=i; j<=n; j+=i){
            cnt[j]++;
        }
    }
    for(int i=1; i<=n; i++)
        cout << cnt[i] << " ";
    cout << endl;
    return 0;
}
