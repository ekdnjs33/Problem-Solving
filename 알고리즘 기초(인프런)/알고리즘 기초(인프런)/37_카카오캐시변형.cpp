//
//  37_카카오캐시변형.cpp
//  알고리즘 기초(인프런)
//
//  Created by 김다원 on 2020/10/01.
//

#include <iostream>
using namespace std;

int s, n;
int cache[10];

int main(){
    cin >> s >> n;
    for(int i=0; i<n; i++){
        int num;
        cin >> num;
        int j;
        for(j=0; j<s; j++){
            if(cache[j] == num){
                int k;
                for(k=j-1; k>=0; k--){
                    cache[k+1] = cache[k];
                }
                cache[k+1] = num;
                break;
            }
        }
        if(j == s){
            int k;
            for(k=s-2; k>=0; k--){
                cache[k+1] = cache[k];
            }
            cache[k+1] = num;
        }
    }
    for(int i=0; i<s; i++){
        cout << cache[i] << " ";
    }
    cout << endl;
    return 0;
}
