//
//  23_연속부분증가수열.cpp
//  알고리즘 기초(인프런)
//
//  Created by 김다원 on 2020/09/30.
//

#include <iostream>
using namespace std;

int n, start, res = 0, cnt = 1;

int main(){
    cin >> n;
    cin >> start;
    for(int i=1; i<n; i++){
        int num;
        cin >> num;
        
        if(start <= num){
            cnt++;
            if(cnt > res)
                res = cnt;
        }
        else
            cnt = 1;
        
        start = num;
    }
    cout << res << endl;
    
    return 0;
}
