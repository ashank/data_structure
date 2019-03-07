//
//  ShunxuZhan.cpp
//  duilie
//
//  Created by 植亚汉 on 2019/1/30.
//  Copyright © 2019 植亚汉. All rights reserved.
//

#include "ShunxuZhan.hpp"
#include <iostream>


void StackClass::InitStack(Stack& S){
    
    S.MaxSize = 10;
    S.stack = new ElemType[S.MaxSize]();
    //动态存储失败
    if (!S.stack) {
        std::cout << "动态存储失败\n";
        exit(1);
    }
    
    //初始置栈为空
    S.top = -1;
};


void StackClass::Push(Stack& S, ElemType item) {
    
    if (S.top == S.MaxSize -1) {
        //计算数据类型占用的地址字节数目
        int k = sizeof(ElemType);
        S.stack = (ElemType*) realloc(S.stack, 2*S.MaxSize*k);
        S.MaxSize = 2*S.MaxSize;
    }
    
    //栈顶指针后移动一个位置
    S.top++;
    //将新元素插入到栈顶
    
    S.stack[S.top] = item;
    
};


ElemType StackClass::Pop(Stack& S){
    
    if (S.top==-1) {
        std::cout << "栈为空\n";
        exit(1);
    }else{
        ElemType item = S.stack[S.top];
        S.top = S.top --;
        return item;
        
    }

};

ElemType StackClass::Peek(Stack& S){
    
    if (S.top==-1) {
        std::cout << "栈为空\n";
        exit(1);
    }else{
        ElemType item = S.stack[S.top];
        return item;
    }
};



bool StackClass:: EmptyStack(Stack& S){
    return S.top == -1;
};



void StackClass::ClearStack(Stack& S){
    
    if (S.stack) {
        
        delete [] S.stack;
        S.stack = 0;
        
    }
    
    S.top = -1;
    S.MaxSize = 0;

};
