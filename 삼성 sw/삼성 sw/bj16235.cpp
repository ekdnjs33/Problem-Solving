//
//  bj16235.cpp
//  삼성 sw
//
//  Created by 김다원 on 2020/04/29.
//  Copyright © 2020 김다원. All rights reserved.
//

/* 나무 재테크 */
#include <iostream>
#include <vector>
using namespace std;

int n, m, k;
int map[11][11];
int A[11][11];
vector<int> tree[11][11];

void init(){
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            map[i][j] = 5;
}

//봄 : 자신의 나이만큼 양분 먹는다(어린 나무 먼저)
void spring(){
    for(int i=0; i<tree.size(); i++){
        int age = tree[i].first;
        int x = tree[i].second.first;
        int y = tree[i].second.second;
        
        if(map[x][y] >= age){
            map[x][y] -= age;
            tree[i].first = age+1;
        }else{
            
        }
    }
}

//여름 : 죽은 나무를 2로 나눠서 양분 저장
void summer(){
    
}

//가을 : 나이가 5의 배수인 나무 번식(나이 1)
void fall(){
    
}

//겨울 : A 양분 추가
void winter(){
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            map[i][j] += A[i][j];
}

int main(){
    cin >> n >> m >> k;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++)
            cin >> A[i][j];
    }
    
    init();
    for(int i=0; i<m; i++){
        int tree_x, tree_y, tree_age;
        cin >> tree_x >> tree_y >> tree_age;
        tree.push_back({tree_age, {tree_x, tree_y}});
    }
    while(k != 0){
        sort(tree.begin(), tree.end());
        spring();
        if(){
            summer();
        }
        if(){
            fall();
        }
        winter();
        k--;
    }
}
