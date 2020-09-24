//
//  치킨배달.cpp
//  삼성코테준비
//
//  Created by 김다원 on 2020/08/30.
//  Copyright © 2020 김다원. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n, m, min_val = 1000000;
int map[51][51];
bool visited[14];
vector<pair<int, int>> house;
vector<pair<int, int>> chick_place;

void select_chick(int start, int cnt){
    if(cnt == m){
        //도시의 치킨 거리 구하기
        int sum = 0;
        for(int i=0; i<house.size(); i++){
            int min_house = 1000;
            for(int j=0; j<13; j++){
                if(visited[j] == true){
                    int r = abs(house[i].first - chick_place[j].first);
                    int c = abs(house[i].second - chick_place[j].second);
                    min_house = min(min_house, r + c);
                }
            }
            sum += min_house;
        }
        min_val = min(min_val, sum);
        return;
    }
    for(int i=start; i<chick_place.size(); i++){
        visited[i] = true;
        select_chick(i + 1, cnt + 1);
        visited[i] = false;
    }
}
int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> map[i][j];
            if(map[i][j] == 1)
                house.push_back(make_pair(i, j));
            else if(map[i][j] == 2)
                chick_place.push_back(make_pair(i, j));
        }
    }
    
    select_chick(0, 0);
    cout << min_val<< endl;
    
    return 0;
}
