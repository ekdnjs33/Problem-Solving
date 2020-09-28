//
//  18_층간소음.cpp
//  알고리즘 기초(인프런)
//
//  Created by 김다원 on 2020/09/29.
//

#include <iostream>
using namespace std;

int n, m, res = 0;

int main(){
    cin >> n >> m;
    int cnt = 0;
    for(int i=0; i<n; i++){
        int k;
        cin >> k;
        
        if(k > m)
            cnt++;
        else
            cnt = 0;
        
        if(cnt > res)
            res = cnt;
    }
    if(res == 0)
        res = -1;
    cout << res << endl;
    
    return 0;
}
