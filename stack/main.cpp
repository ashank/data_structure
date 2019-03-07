//
//  main.cpp
//  stack
//
//  Created by 植亚汉 on 2019/3/5.
//  Copyright © 2019 植亚汉. All rights reserved.
//

#include <iostream>
#include "ShunxuZhan.cpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    //顺序栈
        Stack S;
        StackClass sc ;
    
        sc.InitStack(S);
    
        int a[8] ={3,8,5,17,9,30,15,22};
    
        int i;
        for (i=0; i<8; i++) {
            sc.Push(S, a[i]);
        }
    
        std::cout << "首元素==\n";
        std::cout << sc.Pop(S);
        std::cout << "\n";
    
        sc.Push(S, 68);
    
    
        std::cout << "首元素==\n";
        std::cout << sc.Peek(S);
        std::cout << "\n";
    
    
        std::cout << "删除首元素==\n";
        std::cout << sc.Pop(S);
        std::cout << "\n";
    
    
        while (!sc.EmptyStack(S)) {
            std::cout << "删除元素==\n";
            std::cout << sc.Pop(S);
            std::cout << "\n";
        }
    
        sc.ClearStack(S);
    return 0;
}
