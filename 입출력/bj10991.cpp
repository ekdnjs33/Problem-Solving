//
//  bj10991.cpp
//  입출력
//
//  Created by 김다원 on 2020/03/05.
//  Copyright © 2020 김다원. All rights reserved.
//

#include <stdio.h>

int main(void){
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        for(int j=0; j<n-i; j++) printf(" ");
        if(n%2==0){
            for(int j=n-i; j<n+i; j++){
                    if(j%2==i%2)
                        printf("*");
                    else
                        printf(" ");
            }
        }else{
            for(int j=n-i; j<n+i-1; j++){
                if(j%2==(i+1)%2)
                    printf("*");
                else
                    printf(" ");
            }
        }
        printf("\n");
        /*
        for (int i=1; i<=n; ++i) {
            for (int j=1; j<=n-i; ++j) {
                cout << " ";
             }
             for (int j=1; j<i; ++j) { // "*"과 " "을 한 쌍으로 본다
                 cout << "* ";
             }
             cout << "*\n";
         }
         */
    }
    return 0;
}
