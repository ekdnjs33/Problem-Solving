//
//  bj10845.cpp
//  이것저것
//
//  Created by 김다원 on 2020/03/18.
//  Copyright © 2020 김다원. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int arr[10000];
int k = 0;
int f = 0;
void push(int x){
    k++;
    arr[k] = x;
}
void pop(){
    if(k == f) printf("%d\n", -1);
    else{
        f++;
        printf("%d\n", arr[f]);
        arr[f] = 0;
    }
}
void size(){
    printf("%d\n", k-f);
}
void empty(){
    if(k == f) printf("%d\n", 1);
    else printf("%d\n", 0);
}
void front(){
    if(k == f) printf("%d\n", -1);
    else{
        printf("%d\n", arr[f+1]);
    }
}
void back(){
    if(k == f) printf("%d\n", -1);
    else{
        printf("%d\n", arr[k]);
    }
}
int main(void){
    int n, b;
    char a[10];
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%s", a);
        if(strcmp(a, "push") == 0){
            scanf("%d", &b);
            push(b);
        }
        else if(strcmp(a, "pop") == 0) pop();
        else if(strcmp(a, "size") == 0) size();
        else if(strcmp(a, "empty") == 0) empty();
        else if(strcmp(a, "front") == 0) front();
        else if(strcmp(a, "back") == 0) back();
    }
    return 0;
}
