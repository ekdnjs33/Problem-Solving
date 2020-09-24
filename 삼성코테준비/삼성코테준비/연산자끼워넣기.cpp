//
//  연산자끼워넣기.cpp
//  삼성코테준비
//
//  Created by 김다원 on 2020/08/24.
//  Copyright © 2020 김다원. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n, c = 0, max_val = -1000000000, min_val = 1000000000;
int num[12];
int cal[12];
bool visited[12];
vector<int> arr;

void calculation(int sum){
    for(int i=0; i<arr.size(); i++){
        if(arr[i] == 0){
            sum += num[i+1];
        }else if(arr[i] == 1){
            sum -= num[i+1];
        }else if(arr[i] == 2){
            sum *= num[i+1];
        }else if(arr[i] == 3){
            sum /= num[i+1];
        }
    }
    max_val = max(max_val, sum);
    min_val = min(min_val, sum);
}
void arrange_cal(int cnt, int size){
    if(cnt == size){
        calculation(num[0]);
        return;
    }
    for(int i=0; i<size; i++){
        if(visited[i] == true) continue;
        
        visited[i] = true;
        arr.push_back(cal[i]);
        arrange_cal(cnt + 1, size);
        arr.pop_back();
        visited[i] = false;
    }
}
int main(){
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> num[i];
    
    for(int i=0; i<4; i++){
        int num;
        cin >> num;
        for(int j=0; j<num; j++){
            cal[c] = i;
            c++;
        }
    }
    
    arrange_cal(0, c);
    
    cout << max_val << "\n" << min_val << endl;
    
    return 0;
}
