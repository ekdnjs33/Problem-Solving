//
//  11_숫자총개수s.cpp
//  알고리즘 기초(인프런)
//
//  Created by 김다원 on 2020/09/26.
//

#include <iostream>
using namespace std;

int n, cnt = 0;

int main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        int k = i;
        while(k > 0){
            k = k / 10;
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
