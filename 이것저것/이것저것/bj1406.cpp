//
//  bj1406.cpp
//  이것저것
//
//  Created by 김다원 on 2020/03/25.
//  Copyright © 2020 김다원. All rights reserved.
//

/*
 이 문제는 원래 삽입, 삭제를 O(1) 시간에 해야 하는 것이 정해입니다.
 string은 1차원 배열의 형태이기 때문에 중간에 원소를 껴넣거나 제거하는 것이 O(길이)의 시간이 걸립니다.
 이 작업을 O(1)에 할 수 있도록 링크드 리스트를 사용하거나, 스택 2개를 쓰는 풀이를 생각해보세요.
 배열이나 vector, string 쓰는 경우는 O(n)이 걸린다.
 */

#include <iostream>
#include <cstring>
#include <list>
using namespace std;

int main(void){
    string str;
    int n;
    char a, k;
    list<char> L;
    cin >> str >> n;
    for(char c : str) L.push_back(c);
    list<char>::iterator pos = L.end(); //iterator 정의하는 법
    for(int i=0; i<n; i++){
        cin >> a;
        if(a == 'P'){
            cin >> k;
            L.insert(pos, k);
        }else if(a == 'L'){
            if(pos != L.begin()) pos--;
        }else if(a == 'D'){
            if(pos != L.end()) pos++;
        }else if(a == 'B'){
            if(pos != L.begin()){
                pos--;
                pos = L.erase(pos);
            }
        }
    }
    for(char c : L) cout << c;
    cout << "\n";
    return 0;
}
