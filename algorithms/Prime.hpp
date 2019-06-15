//
//  Prime.h
//  Algorithms
//
//  Created by Harshavardhan K K on 03/07/16.
//  Copyright © 2016 Harshavardhan K. All rights reserved.
//


class Primes {
    
private:
    
    int primes[5000];
    int number;

public:
    
    void getNumber(int n) {
        number = n;
    }
    
    void gen_sieve_primes(int turns) {
        
        for (int p = 2; p < turns; p++) { // for all elements in array
            
            if (primes[p] == 0) // it is not multiple of any other prime
                
                primes[p] = 1; // mark it as prime

            // mark all multiples of prime selected above as non primes
            
            int c = 2;
            int mul = p * c;
            
            for (; mul < turns;)  {
                
                primes[mul] = -1;
                c++;
                mul = p * c;
                
            }
            
        }
        
    }
    
   
  
};
