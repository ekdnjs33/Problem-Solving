//
//  LinckedList.cpp
//  자료구조
//
//  Created by 김다원 on 2020/08/12.
//  Copyright © 2020 김다원. All rights reserved.
//

#include <iostream>
using namespace std;

template <class T>
class LinckedList {
private:
    LinckedList *next;
    T data;
    
public:
    LinckedList(const T &value): next(NULL), data(value){}
    ~LinckedList() {}
    
    LinckedList *getNext() const {
        return next;
    }
    const T& value() const {
        return data;
    }
    void setNext( LinckedList *elem ) {
        next = elem;
    }
    void setValue( const T &value ) {
        data = value;
    }
};
