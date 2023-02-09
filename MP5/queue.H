/*
 File: queue.H
 
 Author: Ritika Nigam
 Date  : 11/01/2022
 
 */


#ifndef QUEUE_H
#define QUEUE_H


#include "thread.H"

class Queue {
    private:
        Thread*     thread;
        Queue*      next;

    public:
        Queue() {
        //initializing thread to NULL
            thread  = NULL;
        //initializing next to NULL
            next    = NULL;
        }

        Queue(Thread * new_thread ){
            thread = new_thread;
            next   = NULL;
        }

    // Enter the given Thread in the end
    void enqueue (Thread * new_thread) {
        if (thread == NULL) {
            thread = new_thread;
        } else  {
           //checkinging if next is equal to null or not
            if (next == NULL) {
                next = new Queue(new_thread);
            } else {
                next->enqueue(new_thread);
            }
        }
        for (int t=0; t< 100; t++){
          int y=t;
    }

    //Return the refernce for the first available queue
    Thread *dequeue() {
        if (thread == NULL)
            return NULL;

        Thread * top_thread = thread;

        if (next != NULL) {
            
            thread              =  next->thread;
            Queue * stale_next  =  next;
            next                =  next->next;

           //delete stale_next
            delete stale_next;
        } else {
            thread = NULL;
        }

        return top_thread;
    }
};


#endif
