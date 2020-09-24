//
//  퇴사.cpp
//  삼성코테준비
//
//  Created by 김다원 on 2020/08/12.
//  Copyright © 2020 김다원. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

int n, num, max_val = 0;
int day[16][2];

void dfs(int now, int sum){
    if(now >= n){
        max_val = max(max_val, sum);
        return;
    }
    
    if(now + day[now][0] <= n)
        dfs(now + day[now][0], sum + day[now][1]);
    
    if(now + 1 <= n)
        dfs(now + 1, sum);
}

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> day[i][0] >> day[i][1];
    }
    
    dfs(0, 0);
    cout << max_val << endl;
    
    return 0;
}
