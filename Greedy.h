//
//  Greedy.h
//  Algorithms
//
//  Created by Harshavardhan K K on 17/09/17.
//  Copyright © 2017 Harshavardhan K. All rights reserved.
//

#ifndef Greedy_h
#define Greedy_h

void activitySelection(int* start, int *finish, int length) {
    
    int i = 0;
    
    cout << i << " ";
    
    for(int j = 1; j < length; j++) {
        
        if(start[j] >= finish[i]) {
            cout << j << " ";
            i = j;
        }
    }
}


#endif /* Greedy_h */
