//
//  21_카드게임.cpp
//  알고리즘 기초(인프런)
//
//  Created by 김다원 on 2020/09/30.
//

#include <iostream>
using namespace std;

int A[10], B[10];
int Ascore = 0, Bscore = 0, winner = 0;

int main(){
    for(int i=0; i<10; i++){
        cin >> A[i];
    }
    for(int i=0; i<10; i++){
        cin >> B[i];
    }
    
    for(int i=0; i<10; i++){
        if(A[i] == B[i]){
            Ascore += 1;
            Bscore += 1;
        }
        else if(A[i] > B[i]){
            Ascore += 3;
            winner = 1;
        }
        else{
            Bscore += 3;
            winner = 2;
        }
    }
    cout << Ascore << " " << Bscore << endl;
    if(Ascore == Bscore){
        if(winner == 0)
            cout << "D" << endl;
        else if(winner == 1)
            cout << "A" << endl;
        else
            cout << "B" << endl;
    }
    else if(Ascore > Bscore)
        cout << "A" << endl;
    else
        cout << "B" << endl;
    
    return 0;
}
