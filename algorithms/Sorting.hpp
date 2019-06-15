//
//  Sorting.cpp
//  Algorithms
//
//  Created by Harshavardhan K K on 25/08/16.
//  Copyright © 2016 Harshavardhan K. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "Generics.h"

template <typename T>

class Sorts {
    
public:
    
    int get_max(int* arr, int n) {
        
        int max = arr[0];
        
        for(int i = 0; i < n; i++) {
            if(arr[i] > max)
                max = arr[i];
        }
        
        return max;
    }
    
    void bubbleSort(T* array, int size) {
        
        for(int i = 0; i < size - 1; i++) {
            
            for (int j = 0; j < size - i - 1; j++) {
                
                if (array[j] < array[j - 1]) {
                    swapValue(&array[j], &array[j - 1]);
                }
            }
        }
    }
    
    void insertionSort(T* array, int size) {
        
        for (int i = 0; i < size; i++) {
            int j = i;
            int num = array[j];
            
            while(j > 0 && num < array[j-1]) {
                swapValue(&array[j], &array[j-1]);
                j--;
            }
            
            array[j] = num;
        }
    }
    
    
    void selectionSort(T* array, int size) {
        
        int minIndex = 0;
        
        for (int i = 0; i < size - 1; i++) {
            minIndex = i;
            
            for (int j = i + 1; j < size; j++) {
                
                if (array[j] < array[minIndex]) {
                    minIndex = j;
                }
            }
            
            if (minIndex != i) {
                swapValue(&array[i], &array[minIndex]);
            }
        }
    }
    
    void mergeSort(T* array, int left, int right) {
        
        if (left < right) {
            int mid = (right + left) / 2;
            
            mergeSort(array, left, mid);
            mergeSort(array, mid, right);
            merge(array, left, mid, right);
        }
        
    }
    
    void merge(T* array, int first, int mid, int last) {
        
        int left = first;
        int right = mid + 1;
        int temp = 0;
        
        int arr[last - first + 1];
        
        while (left <= mid && right <= last) {
            
            if (array[left] < array[right]) {
                arr[temp++] = array[left++];
                
            } else {
                arr[temp++] = array[right++];
            }
        }
        
        while (left <= mid) {
            arr[temp++] = array[left++];
        }
        
        while (right <= last) {
            arr[temp++] = array[right++];
        }
        
        for (int i = 0; i < temp; i++) {
            array[i + first] = array[i];
        }
    }
    
    int searchKey(T* array, T key, int size) {
        
        selectionSort(array, size);
        displayArray(array, size);
        
        cout << "The search index is according to the sorted array\n";
        
        return binarySearch(array, key, 0, size);
        
    }
    
    int linearSearch(T* array, T key, int size) {
        
        for(int i = 0; i < size; i++) {
            
            if (array[i] == key) {
                return i;
            }
        }
        
        return -1;
    }
    
    int binarySearch(T* array, T key, int left, int right) {
        
        if (left > right) {
            return -1;
        }
        
        int mid = (right + left) / 2;
        T ele = array[mid];
        
        if (key < ele) {
            return binarySearch(array, key, left, mid - 1);
            
        } else if(key > ele) {
            return binarySearch(array, key, mid + 1, right);
            
        } else if(key == ele) {
            return mid;
        }
        
        return -1;
    }
    
    void sort(T* array) {
        
        mergeSort(array, 0, sizeof(array) / sizeof(*array));
    }
    
    void countingSort(int* arr, int n, int exp) {
        
        int output[n], count[10] = {0};
        
        for(int i = 0; i < n; i++)
            count[(arr[i] / exp) % 10]++;
        
        // Change count[i] so that count[i] now contains actual position of this digit in output
        
        for(int i = 1; i < 10; i++)
            count[i] += count[i - 1];
        
        // Build the output array
        for(int i = n - 1; i >= 0; i--) {
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }
        
        // Copy the outpt array to arr[], so that arr[] now contains sorted numbers according to current digit
        for(int i = 0; i < n; i++)
            arr[i] = output[i];
    }
    
    
    void radixSort(int* arr, int n) {
        
        int max = get_max(arr, n);
        
        // Do counting sort for every digit, exp is 10^i where i is current digit number
        for(int exp = 1; max / exp > 0; exp *= 10)
            countingSort(arr, n, exp);
    }
    
    void cocktailShakerSort(int* arr, int n) {
        
        bool swapped = true;
        int end = n - 1;
        int start = 0;
        
        while(swapped) {
            
            swapped = false;
            
            for(int i = 0; i < end; ++i) {
                
                if(arr[i] > arr[i+1]) {
                    swap(arr[i], arr[i+1]);
                    swapped = true;
                    
                }

            }
            
            if(!swapped)
                break;
            
            swapped = false;
            
            --end;
            
            for(int i = end - 1; i > start; --i) {
                
                if(arr[i] > arr[i+1]) {
                    swap(arr[i], arr[i+1]);
                    swapped = true;
                }
            }
            
            ++start;
            
        }
    }
    
};




