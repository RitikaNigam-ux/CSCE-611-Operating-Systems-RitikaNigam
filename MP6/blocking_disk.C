/*
     File        : blocking_disk.c

     Author      : Ritika Nigam
     Modified    : 11/20/2022

     Description : 

*/

/*--------------------------------------------------------------------------*/
/* DEFINES */
/*--------------------------------------------------------------------------*/

    /* -- (none) -- */

/*--------------------------------------------------------------------------*/
/* INCLUDES */
/*--------------------------------------------------------------------------*/

#include "assert.H"
#include "utils.H"
#include "console.H"
#include "blocking_disk.H"
#include "scheduler.H"
#include "thread.H"

extern Scheduler* SYSTEM_SCHEDULER;//extern

//CONSTRUCTOR 
/*--------------------------------------------------------------------------*/

BlockingDisk::BlockingDisk(DISK_ID _disk_id, unsigned int _size) 
  : SimpleDisk(_disk_id, _size) {
    disk_queue_size = 0;//disk queue size intialized to 0
    this->disk_queue =  new Queue();
}

void BlockingDisk::wait_until_ready() {
    if (!SimpleDisk::is_ready()) {
        Thread *current_thread = Thread::CurrentThread();
        this->disk_enqueue(current_thread);
        SYSTEM_SCHEDULER->yield();
    }

}

void BlockingDisk::disk_enqueue(Thread *thread) {
    this->disk_queue->enqueue(thread);
    //disk_queue_size is incremented
    disk_queue_size++;
}

bool BlockingDisk::is_ready() {
    return SimpleDisk::is_ready();
}


//SIMPLE_DISK FUNCTIONS
/*--------------------------------------------------------------------------*/

void BlockingDisk::read(unsigned long _block_no, unsigned char * _buf) {
  // -- REPLACE THIS!!!
  SimpleDisk::read(_block_no, _buf);

}


void BlockingDisk::write(unsigned long _block_no, unsigned char * _buf) {
  // -- REPLACE THIS!!!
  SimpleDisk::write(_block_no, _buf);
}
