//
//  bj14890.cpp
//  삼성 sw
//
//  Created by 김다원 on 2020/04/14.
//  Copyright © 2020 김다원. All rights reserved.
//

/* 경사로 */
#include <iostream>
using namespace std;

int n, l, res=0;
int map[201][101]; //가로세로

int main(){
    cin >> n >> l;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            cin >> map[i][j];
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            map[i+n][j] = map[j][i];
    }
    /* 다른 사람이 푼 간단한 방법 */
    int j;
    for (int i=0; i<n*2; i++) {
        int cnt = 1;
        for (j=0; j<n-1; j++) {
            if (map[i][j] == map[i][j+1]) cnt++; //같은 값인 경우
            else if (map[i][j]+1 == map[i][j+1] && cnt >= l) cnt = 1; //오른쪽 경사인 경우(오른쪽 값이 커)
            else if (map[i][j]-1 == map[i][j+1] && cnt >= 0) cnt = -l+1; //왼쪽 경사인 경우(왼쪽 값이 커)
            else break;
        }
        if (j == n-1 && cnt >= 0) res++; //무사히 다 돈 경우
    }
    
    /* 내가 푼 방법 */
    /*for(int i=0; i<n*2; i++){
        bool check = true;
        int cnt = 1;
        int before = map[i][0];
        cout << "*i = " << i << "\n";
        for(int j=1; j<n; j++){
            if(before == map[i][j]){ //같은 값인 경우
                cnt++;
            }
            else if(before-map[i][j] == -1){ //오른쪽 경사인 경우
                if(cnt >= l){
                    before = map[i][j];
                    cnt = 1;
                }
                else{
                    check = false;
                    cout << "---------왼 쪽모자람" << "\n";
                    break;
                }
            }
            else if(before-map[i][j] == 1){ //왼쪽 경사인 경우
                int val = 0;
                int h = 0;
                if(j+l <= n){
                    for(int k=j+1; k<j+l; k++){
                        if(map[i][j] != map[i][k]){
                            val = 1;
                            cout << "---------오른쪽모자람 1" << "\n";
                            break;
                        }
                        h++;
                    }
                }else{
                    val = 1;
                    cout << "---------오른쪽모자람 2" << "\n";
                }
                if(val == 1){
                    check = false;
                    break;
                }
                j += h;
                before = map[i][j];
                cnt = 0;
            }
            else{ //경사가 2이상인 경우
                check = false;
                cout << "---------경사" << "\n";
                break;
            }
        }
        if(check){
            res++; //무사히 다 돈 경우
            cout << "---success----------" << "\n";
        }
    }*/
    cout << res << "\n";
    return 0;
}
