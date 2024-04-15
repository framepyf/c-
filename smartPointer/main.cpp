/*
 * @Author: panyunfei 571686563@qq.com
 * @Date: 2024-04-15 10:51:16
 * @LastEditors: panyunfei 571686563@qq.com
 * @LastEditTime: 2024-04-15 11:09:59
 * @FilePath: /cplusplus/smartPointer/main.cpp
 * @Description: 
 * 
 * Copyright (c) 2024 by ${git_name_email}, All Rights Reserved. 
 */

#include <iostream>
#include "smartPointer.h"
#include "Person.h"

int main(){
      string name = "xiaowang";
     Person * p = new Person(name,30);

     smatPointer<Person> pointer(p);
     pointer->showPeron();
     (*pointer).showPeron();

     return 0;
}