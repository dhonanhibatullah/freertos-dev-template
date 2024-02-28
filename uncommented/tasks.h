#ifndef __TASKS_H__
#define __TASKS_H__

#include "object1.h"
#include "object2.h"

#define TASK1_STACK_SIZE  12800
#define TASK1_PRIORITY    1
#define TASK1_CORE        0
#define TASK1_DELAY       50

#define TASK2_STACK_SIZE  25600
#define TASK2_PRIORITY    1
#define TASK2_CORE        1
#define TASK2_DELAY       30


void first_task(void* pvParameters);
void second_task(void* pvParameters);


extern TaskHandle_t task1_taskhandler,
                    task2_taskhandler;

extern SemaphoreHandle_t  spi_mutex,
                          i2c_mutex,
                          uart_mutex,
                          data_mutex;

extern QueueHandle_t  task1_queuehandler,
                      task2_queuehandler;

extern String task1_msg,
              task2_msg;


void tasks_begin();


#endif