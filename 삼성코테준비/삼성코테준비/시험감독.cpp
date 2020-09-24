//
//  시험감독.cpp
//  삼성코테준비
//
//  Created by 김다원 on 2020/08/27.
//  Copyright © 2020 김다원. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int n, b, c;
long long sum;
vector<int> exam_num;

void counting(){
    for(int i=0; i<n; i++){
        exam_num[i] -= b;
        if(exam_num[i] <= 0) continue;
        
        if(exam_num[i] % c > 0)
            sum += (exam_num[i]/c + 1);
        else
            sum += exam_num[i]/c;
    }
}

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        int num;
        cin >> num;
        exam_num.push_back(num);
    }
    cin >> b >> c;
    
    sum = n;
    counting();
    cout << sum << endl;
    
    return 0;
}
