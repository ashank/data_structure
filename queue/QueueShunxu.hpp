//
//  QueueShunxu.hpp
//  duilie
//
//  Created by 植亚汉 on 2019/1/27.
//  Copyright © 2019 植亚汉. All rights reserved.
//

#ifndef QueueShunxu_hpp
#define QueueShunxu_hpp

#include <stdio.h>

typedef int ElemType;

struct SQueue {
    
    //队列中元素个数最多为QueueMaxSize-1个
    int QueueMaxSize;
    //队列，ElemType类型为int
    ElemType *queue;
    //front指出实际队头元素所在位置的前一个位置
    int front;
    //rear指出实际队尾元素所在的位置
    int rear;
    
    //队列长度变量
    int len;
};


class CQueue {
    
public:
    CQueue();
    void InitQueue(SQueue& Q);
    void AddToQueue(SQueue& Q,ElemType item);
    ElemType PeekQueue(SQueue& Q);
    bool IsEmptyQueue(SQueue& Q);
    void ClearQueue(SQueue& Q);
    ElemType RemoveFromQueue(SQueue& Q);
};

#endif /* QueueShunxu_hpp */
