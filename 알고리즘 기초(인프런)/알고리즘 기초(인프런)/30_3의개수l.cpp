//
//  30_3의개수l.cpp
//  알고리즘 기초(인프런)
//
//  Created by 김다원 on 2020/10/01.
//

#include <iostream>
using namespace std;

int n;

int main(){
    cin >> n;
    int lt = 1, rt, cur, k = 1, res = 0;
    while(lt != 0){
        lt = n / (k * 10);
        rt = n % k;
        cur = (n / k) % 10;
        
        if(cur > 3)
            res = res + ((lt + 1) * k);
        else if(cur == 3)
            res = res + ((lt * k) + (rt + 1));
        else
            res = res + (lt * k);
        k = k * 10;
    }
    cout << res << endl;
    
    return 0;
}
