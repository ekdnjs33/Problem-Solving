//
//  Stack.cpp
//  자료구조
//
//  Created by 김다원 on 2020/08/12.
//  Copyright © 2020 김다원. All rights reserved.
//

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(){
    stack<int> stack1;
    stack1.push(1);
    stack1.push(2);
    stack1.push(3);
    stack1.push(4);
    
    cout << stack1.top() << endl;
    
    stack1.pop();
    cout << stack1.top() << endl;
    
    stack1.pop();
    cout << stack1.top() << endl;
    
    stack1.pop();
    if(stack1.empty())
        cout << "true" << endl;
    else
        cout << "false" << endl;
    cout << stack1.top() << endl;
    
    stack1.pop();
    if(stack1.empty())
           cout << "true" << endl;
       else
           cout << "false" << endl;
}

