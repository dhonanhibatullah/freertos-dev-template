#include "tasks.h"


void first_task(void* pvParameters) {

  uint8_t   task_state    = 0,
            task_in_req   = 0,
            task_out_req  = 0;

  ObjectOne object_one = ObjectOne();

  
  while(true) {

    xQueueReceive(
      task1_queuehandler,
      &task_in_req,       
      pdMS_TO_TICKS(10)   
    );

    switch(task_in_req) {
      
      case 1:
        break;

      case 2:
        break;

      default:
        break;
    }
    task_in_req = 0;


    switch(task_state) {

      case 0:
        break;

      case 1:
        break;

      case 2:
        break;

      default:
        break;
    }


    vTaskDelay(pdMS_TO_TICKS(TASK1_DELAY));
  }
}