//
//  5_나이계산.cpp
//  알고리즘 기초(인프런)
//
//  Created by 김다원 on 2020/09/26.
//

#include <iostream>
#include <cstring>
using namespace std;

string str;
int age;

int main(){
    cin >> str;
    int year = stoi(str.substr(0, 2));
    long long n = str.find("-");
    int sex = stoi(str.substr(n+1, 1));
    
    if(sex == 1 || sex == 2)
        age = 120 - year;
    else if(sex == 3 || sex == 4)
        age = 20 - year;
    
    if(sex == 2 || sex == 4)
        cout << age << " W" << endl;
    else if(sex == 1 || sex == 3)
        cout << age << " M" << endl;
    
    return 0;
}
