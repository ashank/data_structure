//
//  main.cpp
//  queue
//
//  Created by 植亚汉 on 2019/3/5.
//  Copyright © 2019 植亚汉. All rights reserved.
//

#include <iostream>
#include "QueueShunxu.cpp"
#include "QueueLianshi.cpp"


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World Queue!\n";
    
    
    //    CQueue cQueue;
    //
    //    SQueue *Q = new SQueue();
    //
    //    cQueue.InitQueue(*Q);
    //
    //    for (int i = 10; i < 20; i++) {
    //         cQueue.AddToQueue(*Q, i);
    //    }
    //
    //    //首个元素
    //    std::cout << "首个元素=";
    //    std::cout << cQueue.PeekQueue(*Q);
    //    std::cout << "\n";
    //
    //    //判断空的，0为空，1为非空
    //    std::cout << cQueue.IsEmptyQueue(*Q);
    //    std::cout << "\n";
    //
    //    //出列
    //    std::cout << "首个元素出列=";
    //    std::cout << cQueue.RemoveFromQueue(*Q);
    //    std::cout << "\n";
    //
    //    cQueue.AddToQueue(*Q,22);
    
    
    //链式存储
    LinkQueue q;
    CLinkQueue* clq = NULL;
    
    clq->InitQueue(q);
    
    
    for (int i= 0; i<10; i++) {
    
        clq->AddToQueue(q, i*10);
    }
    
    std::cout << "对首元素==";
    std::cout << clq->RemoveFromQueue(q);
    std::cout << "\n";
    
    std::cout << "对首元素==";
    std::cout << clq->RemoveFromQueue(q);
    std::cout << "\n";
    
    std::cout << "对首元素==";
    std::cout << clq->RemoveFromQueue(q);
    std::cout << "\n";
    
    clq->AddToQueue(q, 68);
    
    
    
    
    return 0;
}
