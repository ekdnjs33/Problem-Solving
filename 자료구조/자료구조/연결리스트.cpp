//
//  연결리스트.cpp
//  자료구조
//
//  Created by 김다원 on 2020/08/21.
//  Copyright © 2020 김다원. All rights reserved.
//

#include <iostream>
using namespace std;

typedef struct node{
    string data;
    struct node *next;
}Node;

/*
Node *head = NULL; //전역 변수

void add_first(string item){ //(string item, Node *head)한다고 코드가 제대로 돌아가지 않는다.
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = item;
    temp->next = head;
    head = temp; //head가 전역 변수인 경우만 가능
}
*/

//연결리스트의 맨 앞에 새로운 노드 삽입
void add_F(string item, Node **ptr_head){ //포인터 변수 head의 주소를 매개변수로 받는다.
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = item;
    temp->next = *ptr_head;
    *ptr_head = temp; //head가 전역 변수가 아닌 경우
}
//뒤에 삽입하는 것은 쉽지만, 전에 삽입하는 것은 어렵다.
int add_after(string item, Node *prev){
    if(prev == NULL)
        return 0;
    
    Node *tmp = (Node *)malloc(sizeof(Node));
    tmp->data = item;
    tmp->next = prev->next;
    prev->next = tmp;
    
    return 1;
}

//연결리스트의 첫 번째 노드 삭제
Node *remove_first(Node **head){
    if(*head == NULL)
        return NULL;
    else{
        Node *tmp = *head;
        *head = (*head)->next;
        return tmp;
    }
}
//뒤에 노드 삭제
Node *remove_after(Node *prev){
    Node *tmp = prev->next;
    if(tmp == NULL)
        return NULL;
    else{
        prev->next = tmp->next;
        return tmp;
    }
}

//연결리스트 순회하기
Node *find(string word, Node **head){
    Node *p = *head;
    while(p != NULL){
        if(p->data == word)
            return p;
        p = p->next;
    }
    return NULL;
}
//연결리스트의 index번째 노드의 주소를 반환한다.
Node *get_node(int index, Node **head){
    if(index < 0)
        return NULL;
    
    Node *p = *head;
    for(int i=0; i<index && p!=NULL; i++)
        p = p->next;
    
    return p;
}

//index번째 위치에 새로운 노드를 만들어서 삽입
int add(int index, string item, Node **head){
    if(index < 0)
        return 0;
    
    if(index == 0){
        add_F(item, head);
        return 1;
    }
    
    Node *prev = get_node(index-1, head);
    if(prev != NULL) {
        add_after(item, prev);
        return 1;
    }
    
    return 0;
}

//index번째 노드를 삭제하고, 그 노드에 저장된 데이터를 반환
Node *remove(int index, Node **head){
    if(index < 0)
        return NULL;
    if(index == 0)
        return remove_first(head);
    
    Node *prev = get_node(index-1, head);
    if(prev == NULL)
        return NULL;
    else{
        return remove_after(prev);
    }
}

//실제로 이렇게 코딩하지 않아, 반복문을 사용하거나 다르게 만들겠지?
int main(){
    Node *head = (Node *)malloc(sizeof(Node));
    head->data = "Tuesday";
    head->next = NULL;
    
    Node *q = (Node *)malloc(sizeof(Node));
    q->data = "Thursday";
    q->next = NULL;
    head->next = q;
    
    q = (Node *)malloc(sizeof(Node));
    q->data = "Monday";
    q->next = head;
    head = q;
    
    //add_first("Jane");
    
    add_F("Dawon", &head); //head의 주소를 넘겨줘야 한다!
    
    add_after("Minjune", head);
    
    remove_first(&head);
    
    remove_after(head);
    
    cout << "->" << find("Thursday", &head)->data << endl;
    
    cout << "->" << get_node(1, &head)->data << endl;
    
    add(1, "new thing", &head);
    
    remove(2, &head);
    
    Node *p = head;
    while(p != NULL){
        cout << p->data << endl;
        p = p->next;
    }
}
