//
//  Queue.hpp
//  Algorithms
//
//  Created by Harshavardhan K K on 04/07/16.
//  Copyright © 2016 Harshavardhan K. All rights reserved.
//

#ifndef Queue_hpp
#define Queue_hpp

#include <stdint.h>
#include <stdbool.h>
#include <exception>
#include <iostream>

namespace Algorithm {
    
    template <typename T>
    
    class Queue {
        
    private:
        
        class QueueEmptyException: public std::exception {
            
        public:
            
            virtual const char* what() const throw() {
                return "Queue is empty";
            }
            
        } excp_empty;
        
    private:
        
        uint32_t capacity;
        uint32_t size;
        uint32_t front; // index of the first element
        uint32_t rear; // index of the last element
        
        T* elements;
        
    public:
        
        // constructor takes argument the maximum number of elements of the queue
        
        Queue(uint32_t max) {
            
            this->capacity = max;
            this->size = 0;
            this->front = 0;
            this->rear = -1;
            
            elements = new T[capacity];
        }
        
        ~Queue() {
            delete []elements;
        }
        
    private:
        Queue(const Queue&);
        Queue& operator=(const Queue&);
        
    public:
        
         void dequeue() {
            // if queue size is 0, then it is empty. So cannot pop
            
            if (size == 0) {
                return;
            }
            
            size--;
            front++;
            
            // Removing an element is equivalent to incrementing index of front by 1
            
            if (front == capacity) {
                front = 0;
            }
            
            return;
        }
        
        // return the front element
        
        const T& _front() const {
            if (size == 0) {
                throw excp_empty;
            }
            
            return elements[front];
        }
        
        bool isEmpty() const {
            return size == 0;
        }
        
        // enqueue an element
        // returns false when the queue is full
        
        bool enqueue(const T& element) {
            if (size == capacity) {
                return false;
            }
            
            size++;
            rear++;
            
            if (rear == capacity) {
                rear = 0;
            }
            
            elements[rear] = element;
            
            return true;
        }
        
        uint32_t get_count() const {
            return size;
        }
        
        uint32_t get_capacity() const {
            return capacity;
        }
        
        void displayElements() const {
            
            uint32_t i = front;
            
            while (i <= rear) {
                std::cout << elements[i++] << std::endl;
                
            }
        }
    };
}

#endif /* Queue_hpp */
