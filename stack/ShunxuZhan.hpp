//
//  ShunxuZhan.hpp
//  duilie
//
//  Created by 植亚汉 on 2019/1/30.
//  Copyright © 2019 植亚汉. All rights reserved.
//

#ifndef ShunxuZhan_hpp
#define ShunxuZhan_hpp

#include <stdio.h>

typedef int ElemType;

struct Stack {
    
    ElemType *stack;
    int top;
    int MaxSize;
};


class StackClass {
    
public:
    void InitStack(Stack& S);
    void Push(Stack& S,ElemType item);
    ElemType Pop(Stack& S);
    ElemType Peek(Stack& S);
    bool EmptyStack(Stack& S);
    void ClearStack(Stack& S);
};


#endif /* ShunxuZhan_hpp */
