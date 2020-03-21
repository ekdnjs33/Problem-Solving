//
//  bj10866.cpp
//  이것저것
//
//  Created by 김다원 on 2020/03/20.
//  Copyright © 2020 김다원. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int arr[20001];
int f = 10000;
int b = 9999;
void push_front(int x){
    f--;
    arr[f] = x;
}
void push_back(int x){
    b++;
    arr[b] = x;
}
void pop_front(){
    if(f > b) printf("%d\n", -1);
    else{
        printf("%d\n", arr[f]);
        arr[f] = 0;
        f++;
    }
}
void pop_back(){
    if(f > b) printf("%d\n", -1);
    else{
        printf("%d\n", arr[b]);
        arr[b] = 0;
        b--;
    }
}
void size(){
    printf("%d\n", b-f+1);
}
void empty(){
    if(f > b) printf("%d\n", 1);
    else printf("%d\n", 0);
}
void front(){
    if(f > b) printf("%d\n", -1);
    else{
        printf("%d\n", arr[f]);
    }
}
void back(){
    if(f > b) printf("%d\n", -1);
    else{
        printf("%d\n", arr[b]);
    }
}
int main(void){
    int n, k;
    char a[15];
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%s", a);
        if(strcmp(a, "push_front") == 0){
            scanf("%d", &k);
            push_front(k);
        }
        else if(strcmp(a, "push_back") == 0){
            scanf("%d", &k);
            push_back(k);
        }
        else if(strcmp(a, "pop_front") == 0) pop_front();
        else if(strcmp(a, "pop_back") == 0) pop_back();
        else if(strcmp(a, "size") == 0) size();
        else if(strcmp(a, "empty") == 0) empty();
        else if(strcmp(a, "front") == 0) front();
        else if(strcmp(a, "back") == 0) back();
    }
    return 0;
}
