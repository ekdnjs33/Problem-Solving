//
//  bj1158.cpp
//  이것저것
//
//  Created by 김다원 on 2020/03/27.
//  Copyright © 2020 김다원. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

int main(void){
    int n, k;
    queue<int> q;
    cin >> n >> k;
    for(int i=1; i<=n; i++)
        q.push(i);
    
    cout << "<";
    while(q.size()){
        if(q.size() == 1){ //큐에 원소가 1개 남은 경우
            cout << q.front() << ">\n";
            q.pop();
            break;
        }
        for(int i=1; i<k; i++){
            q.push(q.front());
            q.pop();
        }
        cout << q.front() << ", ";
        q.pop();
    }
    return 0;
}
