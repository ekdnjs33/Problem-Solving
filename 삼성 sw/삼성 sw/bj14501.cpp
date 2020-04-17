//
//  bj14501.cpp
//  삼성 sw
//
//  Created by 김다원 on 2020/04/11.
//  Copyright © 2020 김다원. All rights reserved.
//

/* 퇴사 */
#include <iostream>
#include <algorithm> //max 사용
using namespace std;

int n, num, max_val = 0;
int day[16][2]; //일해야하는 날 수, 받는 금액

void dfs(int now, int sum){
    if (now >= n){
        max_val = max(max_val, sum);
        return;
    }
    if (now + day[now][0] <= n) //해당날에 상담을 하고, 상담 하는데 걸리는 총 일수 만큼 넘어가는 방법
        dfs(now + day[now][0], sum+day[now][1]);
    
    if (now + 1 <= n) //해당날에 상담을 하지 않고, 그 다음날로 넘어가는 방법(day가 +1만 됨)
        dfs(now + 1, sum);
}
int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> day[i][0] >> day[i][1];
    }
    dfs(0, 0);
    cout << max_val << "\n";
    return 0;
}
