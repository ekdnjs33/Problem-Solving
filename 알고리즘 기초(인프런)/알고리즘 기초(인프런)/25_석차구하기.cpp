//
//  25_석차구하기.cpp
//  알고리즘 기초(인프런)
//
//  Created by 김다원 on 2020/09/30.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int ranking[101];
vector<pair<int, int>> arr;

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        int num;
        cin >> num;
        
        arr.push_back({num, i});
    }
    sort(arr.begin(), arr.end(), greater<>());
    int start = arr[0].first;
    ranking[arr[0].second] = 1;
    int cnt = 1;
    for(int i=1; i<n; i++){
        cnt++;
        if(start > arr[i].first){
            ranking[arr[i].second] = cnt;
            start = arr[i].first;
        }
        else{
            ranking[arr[i].second] = ranking[arr[i-1].second];
        }
    }
    for(int i=0; i<n; i++){
        cout << ranking[i] << " ";
    }
    cout << endl;
    
    return 0;
}
