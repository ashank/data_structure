//
//  QueueLianshi.cpp
//  duilie
//
//  Created by 植亚汉 on 2019/1/27.
//  Copyright © 2019 植亚汉. All rights reserved.
//

#include "QueueLianshi.hpp"
#include <iostream>

void CLinkQueue:: InitQueue(LinkQueue& LQ){
    
    LQ.front = LQ.rear = NULL;
    
};

void CLinkQueue:: AddToQueue(LinkQueue& LQ, ElemType item){
    
    //加入一个新的元素，就创建一个新的结点
    LNode* newptr = new LNode();
    //将值传给新结点的值域
    newptr -> data = item;
    //把新结点的指针域为空
    newptr -> next = NULL;
    //若链队为空，则新结点既是对首也是队尾
    if (LQ.rear == NULL) {
        LQ.front = LQ.rear = newptr;
    }else {
        //链队不为空，则新结点就被链接到队尾，并修改队尾指针
        LQ.rear = LQ.rear-> next = newptr;
    }
    
};


int CLinkQueue:: RemoveFromQueue(LinkQueue& LQ){
    
    if (LQ.front == NULL) {
        
        exit(1);
    }
    
    //获取队首的元素
    ElemType item = LQ.front->data;
    //获取队首的指针
    LNode* p = LQ.front;
    //对首指针指向下一个
    LQ.front = p->next;
    
    if(LQ.front == NULL){
        //删除后链队为空，则队尾指针也为空
        
        LQ.rear = NULL;
    }
    
    //回收删除的结点；
    delete p;
    
    return item;
    
}

int CLinkQueue:: PeekQueue(LinkQueue& LQ){
    if (LQ.front == NULL) {
        exit(1);
    }
    return LQ.front->data;
    
}




bool CLinkQueue:: IsEmptyQueue(LinkQueue& LQ){
    
    return LQ.front ==NULL || LQ.rear == NULL;
}



void CLinkQueue::ClearQueue(LinkQueue& LQ){
    
    //获取队首指针
    LNode* p = LQ.front;
    //依次删除队列中的每个结点
    while (p!=NULL) {
        LQ.front = LQ.front->next;
        delete p;
        p= LQ.front;
    }
    
    LQ.rear = NULL;
}



