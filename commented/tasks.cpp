#include "tasks.h"


/*
  * --------[ REDECLARE GLOBAL VARIABLES ]--------
  * Just redeclare everything without the extern here!
*/
TaskHandle_t  task1_taskhandler,
              task2_taskhandler;

SemaphoreHandle_t spi_mutex,
                  i2c_mutex,
                  uart_mutex,
                  data_mutex;

QueueHandle_t task1_queuehandler,
              task2_queuehandler;


/*
  * --------[ BEGIN FUNCTION IMPLEMENTATION ]--------
  * Do the following inside the begin function
  * [1] Define the mutexes
  * [2] Define the queue
  * [3] Execute tasks
*/
void tasks_begin() {
  /*
    * Define the mutex you have declared
  */
  spi_mutex   = xSemaphoreCreateMutex();
  i2c_mutex   = xSemaphoreCreateMutex();
  uart_mutex  = xSemaphoreCreateMutex();
  data_mutex  = xSemaphoreCreateMutex();


  /*
    * Define the queue you have declared
    * Queue parameters are
    * [1] Length  : The number of data can be queued until the queue full
    * [2] Type    : It can be whatever datatype (you may create a struct if you want)
    * Personally, I always use unsigned integer for queue, because it is often use for
    * sending simple trigger to a task.
  */
  task1_queuehandler = xQueueCreate(10, sizeof(uint8_t));
  task2_queuehandler = xQueueCreate(10, sizeof(uint8_t));


  /*
    * Executing tasks with parameters we have defined in tasks.h
  */
  xTaskCreatePinnedToCore(
    first_task,
    "First Task",
    TASK1_STACK_SIZE,
    NULL, // You can add an optional parameter to task1
    TASK1_PRIORITY,
    &task1_taskhandler,
    TASK1_CORE
  );

  xTaskCreatePinnedToCore(
    second_task,
    "Second Task",
    TASK2_STACK_SIZE,
    NULL, // You can add an optional parameter to task2
    TASK2_PRIORITY,
    &task2_taskhandler,
    TASK2_CORE
  );
}