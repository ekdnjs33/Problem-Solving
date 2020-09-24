//
//  BOGGLE.cpp
//  알고리즘 문제해결전략
//
//  Created by 김다원 on 2020/08/03.
//  Copyright © 2020 김다원. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int testCase;
const int dx[8] = {-1, -1, -1, 1, 1, 1, 0, 0};
const int dy[8] = {-1, 0, 1, -1, 0, 1, -1, 1};
char board[5][5] = {0};

bool inRange(int y, int x){
    if(y >= 0 && y < 5 && x >= 0 && x < 5)
        return true;
    else
        return false;
}

bool hasWord(int y, int x, const string& word) {
    if(!inRange(y, x)) return false;
    if(board[y][x] != word[0]) return false;
    if(word.size() == 1) return true;
    
    for(int dir=0; dir<8; ++dir){
        int nextY = y + dy[dir];
        int nextX = x + dx[dir];
        
        if(hasWord(nextY, nextX, word.substr(1)))
            return true;
    }
    return false;
}

int main() {
    cin >> testCase;
    
    for (int i=0; i<testCase; i++) {
        for(int j=0; j<5; j++){
            for(int k=0; k<5; k++){
                char temp;
                cin >> temp;
                board[j][k] = temp;
            }
        }
        
        int test;
        cin >> test;
        vector<string> arr;
        for(int j=0; j<test; j++){
            string w;
            cin >> w;
            arr.push_back(w);
        }
        
        for(int j=0; j<test; j++){
            bool check = false;
            for(int k=0; k<5; k++){
                for(int h=0; h<5; h++){
                    if(hasWord(k, h, arr[j])){
                        check = true;
                        k = 5; h = 5;
                    }
                }
            }
            
            if(check)
                cout << arr[j] << " YES\n";
            else
                cout << arr[j] << " NO\n";
        }
    }
}
