/*
  * -------[ IFNDEF ]-------
  * Don't forget to add #ifndef in every header file!
  * So that the header file does not called twice.
*/
#ifndef __OBJECT2_H__
#define __OBJECT2_H__


/*
  * ----------[ INCLUDE ]----------
  * Include any necessary libraries here
*/
#include <Arduino.h>


/*
  * ---------[ CREATE YOUR OBJECT ]-----------
  * The goal of object or class here is to ease the process
  * of writing the code for your tasks later and make your task
  * code looks cleaner too!
*/
class ObjectTwo {
  
  private:
    uint8_t foo;

  public:
    ObjectTwo();
};


#endif