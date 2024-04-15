/*
 * @Author: panyunfei 571686563@qq.com
 * @Date: 2024-04-15 10:41:13
 * @LastEditors: panyunfei 571686563@qq.com
 * @LastEditTime: 2024-04-15 11:09:33
 * @FilePath: /cplusplus/smartPointer/smartPointer.h
 * @Description: 
 * 
 * Copyright (c) 2024 by ${git_name_email}, All Rights Reserved. 
 */
#include <iostream>
using namespace std;

template <class T>
class smatPointer
{
private:
    /* data */
    T * pointer;

public:
    smatPointer();
    smatPointer(T * pointer);
    T * operator->();
    T & operator*();
    ~smatPointer();
};

template <class T> 
T * smatPointer<T>::operator->()
{
     return this->pointer;
}

template <class T> 
T & smatPointer<T>::operator*()
{
      return (*pointer);
}

template <class T> 
smatPointer<T>::smatPointer()
{
     cout << "just for test" << endl;
}

template <class T> 
smatPointer<T>::smatPointer(T * pointer)
{
     this->pointer = pointer;
}

template <class T> 
smatPointer<T>::~smatPointer()
{
     if(pointer != NULL){
         delete pointer;
         pointer = NULL;
           cout << "~smatPointer" << endl;
     }
}
