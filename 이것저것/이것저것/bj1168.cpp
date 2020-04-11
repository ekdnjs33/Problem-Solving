//
//  bj1168.cpp
//  이것저것
//
//  Created by 김다원 on 2020/03/27.
//  Copyright © 2020 김다원. All rights reserved.
//

/*
 큐로 했을 때 보다 벡터로 했을 때가 더 시간이 빨랐다.
 */
#include <iostream>
#include <vector>
using namespace std;

int n, k;
vector<int> v;
vector<int> res;

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++) v.push_back(i);
    int idx = k - 1;

    while (!v.empty()) {
        res.push_back(v[idx]);
        v.erase(v.begin() + idx);
        idx += k-1;
        while (idx >= v.size() && !v.empty())
            idx -= v.size();
    }

    cout << "<" << res[0];
    for (int i = 1; i < res.size(); i++)
        cout << ", " << res[i];
    cout << ">\n";
}
