//
//  Stack.hpp
//  Algorithms
//
//  Created by Harshavardhan K K on 03/07/16.
//  Copyright © 2016 Harshavardhan K. All rights reserved.
//

#ifndef Stack_hpp
#define Stack_hpp

#include <stdint.h>
#include <stdbool.h>
#include <exception>
#include "Generic.h"

#endif /* Stack_hpp */

namespace Algorithm {
    
    template <typename T = uintptr_t>
    
    class Stack {
    private:
        
        class StackEmptyException: public std::exception {
        public:
            
            virtual const char * what() const throw() {
                return " stack is empty";
            }
        } excp_empty;
        
        class StackIndexOutOfBoundException: public std::exception {
        public:
            virtual const char * what() const throw() {
                return "Index out of bound";
            }
        }excp_ioob;
        
        uint32_t m_capacity; // the total capacity
        uint32_t m_size; // current stack size
        
        T * m_elements;
        
    public:
        
        // capacity is the maximum elements the stack can hold
        
        Stack(uint32_t capacity) {
            
            this->m_capacity = capacity;
            this->m_size = 0;
            this->m_elements = new T[capacity];
        }
        
        ~Stack() {
            delete [] m_elements;
        }
        
    private:
        Stack(const Stack&);
        Stack& operator=(const Stack&);
        
    public:
        
        // test whether the stack is empty
        
        inline bool is_emppty() const {
            return m_size == 0 ? true : false;
        }
        
        inline void pop() {
            if(m_size != 0)
                m_size--;
            return;
        }
        
        // get the top element
        inline const T& top() const {
            if (m_size == 0) throw excp_empty;
            
            return m_elements[m_size - 1];
        }
        
        inline bool push(const T& value) {
            if (m_size == m_capacity) {
                return false;
                
            } else {
                m_elements[m_size++] = value;
            }
            
            return true;
        }
        
        // return the stack size count
        inline uint32_t count() const {return m_size; }
        
        inline const T& operator[] (uint32_t idx) const {
            if (idx >= m_capacity) {
                throw excp_ioob;
            }
            
            return m_elements[m_size - 1 - idx];
        }
    };
}
