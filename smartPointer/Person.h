/*
 * @Author: panyunfei 571686563@qq.com
 * @Date: 2024-04-15 10:45:45
 * @LastEditors: panyunfei 571686563@qq.com
 * @LastEditTime: 2024-04-15 11:07:50
 * @FilePath: /cplusplus/smartPointer/Person.h
 * @Description: 
 * 
 * Copyright (c) 2024 by ${git_name_email}, All Rights Reserved. 
 */

#include <iostream>
#include <string>

class Person   {
    public:
       Person(){

       }

       Person(string &name,int age){
             this->name = name;
             this->age  = age;
       }

       void showPeron(){
            cout << "name:" << name << "  age:" << age << endl;
       }

    private:
      string name;
      int age;
} ;  