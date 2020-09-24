//
//  bj15686.cpp
//  삼성 sw
//
//  Created by 김다원 on 2020/04/26.
//  Copyright © 2020 김다원. All rights reserved.
//

/* 치킨 배달 */
#include <iostream>
#include <vector>
#include <utility> //pair 사용
#include <cmath> //abs 사용
using namespace std;

int n, m, sumMin = 10000;
vector<pair<int, int>> chicken;
vector<pair<int, int>> home;
bool Select[13];
int arr[100][13];

int sum(long cSize, long hSize){
    int res = 0, min;
    for(int i=0; i<hSize; i++){
        min = 2*n;
        for(int j=0; j<cSize; j++){
            if(Select[j] == true){
                if(arr[i][j] < min)
                    min = arr[i][j];
            }
        }
        res += min;
    }
    return res;
}

//치킨집 m만큼 조합
void combination(int idx, int cnt, long cSize, long hSize){
    if(cnt == m){
        int val = sum(cSize, hSize);
        if(val < sumMin)
            sumMin = val;
        return;
    }
    for(int i=idx; i<cSize; i++){
        if(Select[i] == true) continue;
        Select[i] = true;
        combination(i, cnt+1, cSize, hSize);
        Select[i] = false;
    }
}

int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int a;
            cin >> a;
            if(a == 1)
                home.push_back({i, j});
            else if(a == 2)
                chicken.push_back({i, j});
        }
    }
    for(int i=0; i<home.size(); i++){
        for(int j=0; j<chicken.size(); j++){
            arr[i][j] = abs(home[i].first-chicken[j].first) + abs(home[i].second-chicken[j].second);
            //cout << arr[i][j] << " ";
        }
        //cout << "\n";
    }
    combination(0, 0, chicken.size(), home.size());
    cout << sumMin << "\n";
    return 0;
}
