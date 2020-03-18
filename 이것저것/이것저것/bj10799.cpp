//
//  bj10799.cpp
//  이것저것
//
//  Created by 김다원 on 2020/03/18.
//  Copyright © 2020 김다원. All rights reserved.
//

#include <stdio.h>
#include <stack>
using namespace std;

char arr[100001];
//int ch[100001][3]; //짝짓기용, 증가감소용, 레이저용
int main(void){
    scanf("%s", arr);
    stack<char> s;
    
    int result = 0;
    for(int i=0; arr[i] != '\0'; i++){
        if(arr[i] == '(') s.push(arr[i]); //'(' 일 경우에는 스택에 넣어준다.
        else{
            s.pop(); //')' 일 경우에는 스택에서 빼준다.
            if(arr[i-1] == '(') result += s.size(); //레이저일 경우 스택의 사이즈만큼 더해준다.
            else result += 1; //막대기의 끝일 경우 1을 더해준다.
        }
    }
    printf("%d\n", result);
    return 0;
    
    /* 시간초과 -> 스택을 써준다
     int num = 0;
     for(int j=0; arr[j] != '\0'; j++){
        if(arr[j] == '('){
            num++;
            ch[j][1] = 1;
        }
        else if(arr[j] == ')'){
            if(ch[j-1][1] > 0){
                ch[j-1][2] = 1;
                ch[j][2] = 1;
            }
            num--;
            ch[j][1] = -1;
        }
        ch[j][0] = num;
    }
    
    int start = 0, end = 0, sum = 0;
    for(int i=0; arr[i] != '\0'; i++){
        num = 0;
        if(ch[i][1] == -1 && ch[i][2] == 0){
            end = i;
            ch[i][2] = 2;
            for(int j=i-1; j>=0; j--){
                if(ch[j][1] == 1 && ch[j][2] == 0){
                    start = j;
                    ch[j][2] = 2;
                    break;
                }
            }
            for(int j=start; j<end; j++)
                if(ch[j][2] == 1) num++;
            sum += (num/2+1);
        }
    }
    printf("%d\n", sum);*/
}
