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
            thread  = NULL;//thread is assigned NULL
            next    = NULL;//next is assigned NULL
        }

        Queue(Thread * new_thread ){
            thread = new_thread;
            next   = NULL;//next is assigned to NULL
        }

    // the given Thread is entered in the end
    void enqueue (Thread * new_thread) {
        if (thread == NULL) {
            thread = new_thread;
        } else  {
            if (next == NULL) {
                next = new Queue(new_thread);
            } else {
                next->enqueue(new_thread);
            }
        }
    }

    //the refernce is returned for the first available queue
    Thread *dequeue() {
        if (thread == NULL)
            return NULL;//Null is returned

        Thread * top_thread = thread;

        if (next != NULL) {
            //Update thread and next pointer
            thread              =  next->thread;
            Queue * stale_next  =  next;
            next                =  next->next;

            delete (void *)stale_next;
        } else {
            thread = NULL;
        }

        return top_thread;//top_thread is returned
    }

    // Return the top thread on the queue
    Thread * peek() {
        if (thread == NULL)//checking if thread is equal to Null
            return NULL;//Null is returned

        return thread;//thread is returned
    }
};


#endif

