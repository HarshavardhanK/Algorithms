//
//  GenObs.cpp
//  Algorithms
//
//  Created by Harshavardhan K K on 21/07/16.
//  Copyright © 2016 Harshavardhan K. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <iostream>

// Create general objects that the above data structures can store.

class Performance {
    
private:
    std::string performance;
    
public:
    
    void setPerformance(std::string performance) {
        this->performance = performance;
    }
    
    std::string getPerformance() {
        return performance;
    }
    
    friend std::ostream& operator <<(std::ostream& a, Performance& b);
    
};


class Student {
    
private:
    
    std::string name;
    
    int rollNo;
    double percentage;
    
    Performance performance;
    
public:
    
    Student(std::string name, int rollNo, double percentage) {
        
        this->name = name;
        this->rollNo = rollNo;
        this->percentage = percentage;
        
    }
    
    void setPerformance(std::string performance) {
        this->performance.setPerformance(performance);
    }
    
    Student() {};
    
    std::string getName() {
        return name;
    }
    
    double getPercentage() {
        return percentage;
    }
    
    int getRollNo() {
        return rollNo;
    }
    
    Performance getPerformance() {
        return performance;
    }
};


std::ostream& operator <<(std::ostream& a, Performance& b) {
    a << b.getPerformance();
    return a;
}



