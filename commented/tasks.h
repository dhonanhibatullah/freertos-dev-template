/*
  * -------[ IFNDEF ]-------
  * Don't forget to add #ifndef in every header file!
  * So that the header file does not called twice.
*/
#ifndef __TASKS_H__
#define __TASKS_H__


/*
  * -------[ INCLUDE ]-------
  * Include your defined library from object1.h and object2.h
*/
#include "object1.h"
#include "object2.h"


/*
  * -------[ TASKS PARAMETER ]-------
  * In declaring tasks, there are several parameters that need to be considered,
  * usually defined with #define. The following shows the parameters.
  * [1] Stack Size  : Size of memory allocated for the task
  * [2] Priority    : An unsigned integer value, bigger value means higher priority
  * [3] Core        : ESP32 has 2 cores that works independently, 0 and 1
  * [4] Delay       : It is convenient to have delay for each task so that the mcu can rest
*/
#define TASK1_STACK_SIZE  12800
#define TASK1_PRIORITY    1
#define TASK1_CORE        0
#define TASK1_DELAY       50

#define TASK2_STACK_SIZE  25600
#define TASK2_PRIORITY    1
#define TASK2_CORE        1
#define TASK2_DELAY       30


/*
  * -------[ TASKS ]-------
  * This is all the asynchronous tasks you want to run simultaneously.
  * Be careful on defining the tasks, we have to minimize the communication 
  * between tasks. You can declare as much tasks as you wish.

  * It is good to implement each task on a different implementation (.cpp) file.
  * In this example, first_task() and second_task() implemented on
  * task1.cpp and task2.cpp respectively
*/
void first_task(void* pvParameters);
void second_task(void* pvParameters);


/*
  * -------[ FREERTOS KERNEL OBJECT ]-------
  * There are 3 main FreeRTOS kernel objects:
  * [1] Task Handle       : For controlling the task, i.e running, ready, blocked, suspended, etc.
  * [2] Queue Handle      : Creating queue that can be communicated between tasks
  * [3] Semaphore Handle  : Used to control the access to "crucial" process, which can not be done simultaneously between tasks!

  * Write all the kernel objects in extern, so that every implementation file can access the object freely.

  * It is convenient to have queuehandle for every tasks, even though we are not intending to use it at the beginning,
  * but trust me, it is good to have default queuehandle for every tasks!
*/
extern TaskHandle_t task1_taskhandler,
                    task2_taskhandler;

extern SemaphoreHandle_t  spi_mutex,
                          i2c_mutex,
                          uart_mutex,
                          data_mutex;

extern QueueHandle_t  task1_queuehandler,
                      task2_queuehandler;


/*
  * -------[ GLOBAL VARIABLES ]-------
  * Declare every global variables you needed here!
  * Don't forget to use extern keyword
*/
extern String task1_msg,
              task2_msg;


/*
  * -------[ BEGIN FUNCTION ]-------
  * This functions starts all the task. See the implementation on tasks.cpp.
*/
void tasks_begin();


#endif