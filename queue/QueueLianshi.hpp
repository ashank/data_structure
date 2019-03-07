//
//  QueueLianshi.hpp
//  duilie
//
//  Created by 植亚汉 on 2019/1/27.
//  Copyright © 2019 植亚汉. All rights reserved.
//

#ifndef QueueLianshi_hpp
#define QueueLianshi_hpp

#include <stdio.h>

typedef int  ElemType;
//结点类型
struct LNode {
    //值域
    ElemType data;
    //链接指针域
    LNode* next;
};


struct LinkQueue {
    
    //队首指针
    LNode* front;
    //队尾指针
    LNode* rear;
    
};


class CLinkQueue  {
    
public:
    
    CLinkQueue();
    void InitQueue(LinkQueue& LQ);
    void AddToQueue(LinkQueue& LQ, ElemType item);
    int RemoveFromQueue(LinkQueue& LQ);
    int PeekQueue(LinkQueue& LQ);
    bool IsEmptyQueue(LinkQueue& LQ);
    void ClearQueue(LinkQueue& LQ);
};


#endif /* QueueLianshi_hpp */
