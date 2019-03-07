//
//  main.cpp
//  guangyibiao
//
//  Created by 植亚汉 on 2019/1/13.
//  Copyright © 2019 植亚汉. All rights reserved.
//

#include <iostream>
#include <stdlib.h>

typedef char ElemType;
struct GLNode {
    bool tag; //标志域
    
    //值域或者子表表头指针域
    union {
        ElemType data;
        GLNode* sublist;
    };
    
    GLNode* next; //指向后继结点指针域
};

class Generalized1 {
    
public:
    
    Generalized1(){
        std::cout<< "create"<<std::endl;
    };
    
    int lenght(GLNode* GL){
        
        if (GL == NULL) {
            return 1+lenght(GL);
        }
        
        return 0;
    };
    
    
    
    int depth(GLNode* GL){
        
        int max = 0;
        
        while (GL != NULL) {
            if (GL->tag == true) {
                int dep = depth(GL->sublist);
                if (dep>max) {
                    max = dep;
                }
            }
            GL = GL->next;
        };
        
        return  max+1;
        
    };
    
    
    void create(GLNode*& GL){
        
        char ch;
        std::cin>> ch;
        
        if (ch == '#') {
            
            GL = NULL;
        }else if (ch == '('){
            GL == new GLNode;
            GL->tag = true;
            create(GL);
        }else {
            GL == new GLNode;
            GL->tag = false;
            GL->data = ch;
            
        }
        
        std::cin>>ch;
        
        if (GL == NULL) {
        }else if(ch == ','){
            create(GL->next);
        }else if(ch == ')' || ch == ';'){
            GL->next = NULL;
        }
    };
    
    
    void print(GLNode* GL){
        
        if (GL->tag == true) {
            std::cout<<'(';
            if (GL->sublist == NULL) {
                std::cout<<'#';
            } else {
                print(GL->sublist);
                std::cout<<')';
            }
        } else {
            std::cout<<GL->data;
        }
        
        if (GL->next!=NULL) {
            std::cout<<',';
            print(GL->next);
        }
    };
    
};




int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    Generalized1 gl;
    GLNode* g= NULL;
    
    gl.create(g);
    gl.print(g);
    std::cout<<std::endl;
    
    std::cout<<"changdu=="<<gl.lenght(g->sublist)<<std::endl;
    std::cout<<"shendu=="<<gl.depth(g->sublist)<<std::endl;
    
    return 10;
}









