#include "tasks.h"

/*
  * ---------[ TASK1 IMPLEMENTATION ]----------
  * Define whatever you want to do in task1 here.
  * The following template is the common template I use
*/

void first_task(void* pvParameters) {
  /*
    * --------[ LOCAL VARIABLES ]--------
    * There are some local variables you will always need inside a task.
    * [1] task_state    : the state of the task, this is used for designing a common FSM scheme with switch-case
    * [2] task_in_req   : incomming queue request from other task
    * [3] task_out_req  : outcomming queue request to other task
    * [4] object_one    : your defined object for the task
  */
  uint8_t   task_state    = 0,
            task_in_req   = 0,
            task_out_req  = 0;

  ObjectOne object_one = ObjectOne();

  
  /*
    * ---------[ LOOP ]--------
    * This is where you write your usual void loop() code.
  */
  while(true) {
    /*
      * --------[ CHECK THE QUEUE ]--------
      * Read the queue from your specific queue handler for this task
      * i.e. task1_queuehandler
    */
    xQueueReceive(
      task1_queuehandler,
      &task_in_req,       // the data from queue is asserted here
      pdMS_TO_TICKS(10)   // waiting time for a queue, put zero if do not want to wait
    );


    /*
      * --------[ DETERMINE THE ACTION FOR RECEIVED QUEUE ]--------
      * Do something with the received queue!
      * You may redefine the number 1, 2, ... with #define to make it more readable
    */
    switch(task_in_req) {
      
      case 1:
        break;

      case 2:
        break;

      default:
        break;
    }
    task_in_req = 0; // remember to reset


    /*
      * --------[ TASK'S MAIN TASK ]--------
      * Design the FSM of the task using the task_state
      * You may redefine the number 1, 2, ... with #define to make it more readable
    */
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


    /*
      * -------[ PUT THE DELAY OF THE TASK HERE! ]---------
    */
    vTaskDelay(pdMS_TO_TICKS(TASK1_DELAY));
  }
}