//
//  경사로.cpp
//  삼성코테준비
//
//  Created by 김다원 on 2020/09/07.
//  Copyright © 2020 김다원. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

int n, l, cnt = 0;
int h;
int arr[100][100];
bool visit_row[100][100], visit_col[100][100];


int main(){
    cin >> n >> l;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }
    //가로
    for(int i=0; i<n; i++){
        int j;
        for(j=0; j<n-1; j++){
            int h = arr[i][j];
            int next_h = arr[i][j+1];
            
            if(abs(next_h - h) > 1) break;
            
            if(next_h - h == 1){
                int end = j-l+1;
                if(end < 0) break;
                else{
                    int k;
                    for(k=j; k>=end; k--){
                        if(arr[i][k] != h || visit_row[i][k])
                            break;
                        visit_row[i][k] = true;
                    }
                    if(k != end-1)
                        break;
                }
            }
            else if(next_h - h == -1){
                int end = j+l;
                if(end >= n) break;
                else{
                    int k;
                    for(k=j+1; k<=end; k++){
                        if(arr[i][k] != next_h || visit_row[i][k])
                            break;
                        visit_row[i][k] = true;
                    }
                    if(k != end+1)
                        break;
                    j = j+l-1;
                }
            }
        }
        if(j == n-1)
            cnt++;
    }
    //세로
    for(int i=0; i<n; i++){
        int j;
        for(j=0; j<n-1; j++){
            int h = arr[j][i];
            int next_h = arr[j+1][i];
            
            if(abs(next_h - h) > 1) break;
            
            if(next_h - h == 1){
                int end = j-l+1;
                if(end < 0) break;
                else{
                    int k;
                    for(k=j; k>=end; k--){
                        if(arr[k][i] != h || visit_col[k][i])
                            break;
                        visit_col[k][i] = true;
                    }
                    if(k != end-1)
                        break;
                }
            }
            else if(next_h - h == -1){
                int end = j+l;
                if(end >= n) break;
                else{
                    int k;
                    for(k=j+1; k<=end; k++){
                        if(arr[k][i] != next_h || visit_col[k][i])
                            break;
                        visit_col[k][i] = true;
                    }
                    if(k != end+1)
                        break;
                    j = j+l-1;
                }
            }
        }
        if(j == n-1)
            cnt++;
    }
    
    cout << cnt << endl;
    
    return 0;
}
