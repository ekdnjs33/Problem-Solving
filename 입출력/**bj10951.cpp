//
//  bj10951.cpp
//  입출력
//
//  Created by 김다원 on 2020/03/03.
//  Copyright © 2020 김다원. All rights reserved.
//

#include <stdio.h>

int main(){
    int A, B;
    // 정상적 프로그램 종료를 위해 데이터 소스로부터 더 이상 읽을 수 있는 데이터가
    // 없음을 나타내야 한다. 파일 끝 명시 = EOF
    while(scanf("%d %d", &A, &B) != EOF){
        printf("%d\n", A+B);
    }
    return 0;
}
