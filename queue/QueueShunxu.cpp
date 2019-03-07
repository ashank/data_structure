//
//  QueueShunxu.cpp
//  duilie
//
//  Created by 植亚汉 on 2019/1/27.
//  Copyright © 2019 植亚汉. All rights reserved.
//

#include "QueueShunxu.hpp"

CQueue:: CQueue(){
    
}

void CQueue::InitQueue(SQueue& Q){
    
    //分配大小
    Q.QueueMaxSize = 10;
    Q.len = 0;
    Q.queue = new ElemType[Q.QueueMaxSize];
    Q.front = Q.rear = 0;
    
    std::printf("init=====\n");
};

void CQueue::AddToQueue(SQueue& Q, ElemType item){
    
    // 1、先判断队列 是否已满，未满则添加元素进队列，满员了 需要先扩大容量在进队列
    
    std::cout << "当前对首指针 ==";
    std::cout << Q.front;
    std::cout << "\n";
    
    
    std::cout << "当前对尾指针 ==";
    std::cout << (Q.rear+1) % Q.QueueMaxSize;
    std::cout << "\n";
    
    bool b = (Q.rear+1) % Q.QueueMaxSize == Q.front;
    if (b) {
        //获取每种变量类型所占用的内存的字节数
        int k = sizeof(ElemType);
        std::cout << "变量所占内存字节数==";
        std::cout << k;
        std::cout << "\n";
        
        //队列大小
        Q.queue = (ElemType*) realloc(Q.queue, 2 * Q.QueueMaxSize * k);
        std::cout << "队列==";
        std::cout <<  Q.queue;
        std::cout << "\n";
        
        //** 把原队列的尾部内容向后移动Maxsize个位置，队列中元素个数最多为QueueMaxSize-1个
        
        //如果队尾指针位置  等于最后一个位置
        if(Q.rear != (Q.QueueMaxSize - 1)){
            for (int i = 0; i < Q.rear ; i++) {
                Q.queue[i+Q.QueueMaxSize] = Q.queue[i];
            }
            //将队尾指针向后移动QueueMaxSize 个位置
            Q.rear += Q.QueueMaxSize;
            
        }
        
        //扩大两倍的空间
        Q.QueueMaxSize = 2* Q.QueueMaxSize;
        
        std::cout << "队列大小==";
        std::cout <<  Q.QueueMaxSize;
        std::cout << "\n";
    }
    
    //修改入队，队尾指针
    Q.rear = (Q.rear+1) % Q.QueueMaxSize;
    //赋值给队尾指针
    Q.queue[Q.rear] = item;
};


/**
 *  读取队列首个元素，不修改状态
 */
ElemType CQueue::PeekQueue(SQueue& Q){
    
    //头尾指针相等，则队列为空
    if (Q.rear == Q.front) {
        std::printf("队列已空，无法读取\n");
        exit(1);
    }
    
    //队列首个元素是 对首指针的下一个元素，所以要先找到  实际首个元素的指针位置
    int positon = (Q.front+1) % Q.QueueMaxSize;
    //获取首个元素
    ElemType item =  Q.queue[positon];
    
    return item;
};



bool CQueue::IsEmptyQueue(SQueue& Q){
    return Q.front = Q.rear;
}

ElemType CQueue::RemoveFromQueue(SQueue& Q){
    
    if (Q.front == Q.rear) {
        
        std::printf("队列已空\n");
        exit(1);
    }
    
    Q.front = (Q.front+1) %Q.QueueMaxSize;
    
    return Q.queue[Q.front];
    
}

void CQueue::ClearQueue(SQueue& Q){
    
    InitQueue(Q);
    Q.QueueMaxSize = 0;
    
}

