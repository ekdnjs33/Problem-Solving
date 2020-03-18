//
//  bj10825.cpp
//  이것저것
//
//  Created by 김다원 on 2020/03/16.
//  Copyright © 2020 김다원. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

typedef struct Dohyun{
    string name;
    int lang;
    int engl;
    int math;
}dohyun; // struct Dohyun = dohyun

bool cmp(Dohyun a,  Dohyun b){
    if(a.lang > b.lang) return true;
    else if(a.lang == b.lang){
        if(a.engl < b.engl) return true;
        else if(a.engl == b.engl){
            if(a.math > b.math) return true;
            else if(a.math == b.math){
                if(a.name < b.name) return true;
            }
        }
    }
    return false;
}
int main(void){
    int n;
    cin >> n;
    dohyun d[n];
    for(int i=0; i<n; i++){
        cin >> d[i].name >> d[i].lang >> d[i].engl >> d[i].math;
    }
    sort(d, d+n, cmp);
    for(int i=0; i<n; i++){
        cout << d[i].name << "\n";
    }
    return 0;
}
