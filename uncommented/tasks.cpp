#include "tasks.h"


TaskHandle_t  task1_taskhandler,
              task2_taskhandler;

SemaphoreHandle_t spi_mutex,
                  i2c_mutex,
                  uart_mutex,
                  data_mutex;

QueueHandle_t task1_queuehandler,
              task2_queuehandler;


void tasks_begin() {
  
  spi_mutex   = xSemaphoreCreateMutex();
  i2c_mutex   = xSemaphoreCreateMutex();
  uart_mutex  = xSemaphoreCreateMutex();
  data_mutex  = xSemaphoreCreateMutex();

  task1_queuehandler = xQueueCreate(10, sizeof(uint8_t));
  task2_queuehandler = xQueueCreate(10, sizeof(uint8_t));

  xTaskCreatePinnedToCore(
    first_task,
    "First Task",
    TASK1_STACK_SIZE,
    NULL,
    TASK1_PRIORITY,
    &task1_taskhandler,
    TASK1_CORE
  );

  xTaskCreatePinnedToCore(
    second_task,
    "Second Task",
    TASK2_STACK_SIZE,
    NULL,
    TASK2_PRIORITY,
    &task2_taskhandler,
    TASK2_CORE
  );
}