//
//  2DGrid.cpp
//  Algorithms
//
//  Created by Harshavardhan K K on 22/09/17.
//  Copyright © 2017 Harshavardhan K. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* External Variables */
int currentTime;
/* Prototypes */
float distance(int x1, int y1, int x2, int y2);
void updateLocation(int location[], int x, int y);
float profit(int pickupSteps, int dropSteps, float dropDistance, int requestTime);
void permuteRoutes(int routes[][100], int *arr, int n, int l);
void findPath(int currentLocation[], int x1, int y1, int x2, int y2, int waitTime);
int maxIndex(float profit[], int n);
void finalRoute(int passengers[][5], int route[], int numberOfPassengers);

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int nop;
    int currentLocation[2] = {0, 0};
    extern int currentTime;
    scanf("%d", &nop);
    int passengers[nop][5];
    for(int i = 0;i<nop;++i)
    {
        scanf("%d %d %d %d %d", &passengers[i][0], &passengers[i][1], &passengers[i][2], &passengers[i][3], &passengers[i][4]);

    }


    static int routes[600000][100];
    static float sum[600000];
    
    int x1, y1, x2, y2, dropSteps, pickupSteps;
    float dropDistance, pickupDropDistance;
    
    int nopArray[nop];
    
    for(int i=0;i<nop;i++) {
        nopArray[i]=i;
    }
    
    permuteRoutes(routes, nopArray, nop, 0);

    unsigned long long int maxRoutes=1;
    for(int i=1; i<=nop; ++i) { maxRoutes =maxRoutes* i; }
    //maxRoutes=pow(nop, 2);

    if(nop==1)                                maxRoutes=1;

    for (int i = 0; i < maxRoutes; ++i)
    {

        sum[i] = 0.0; //Sum of all profit in each possible route
        currentTime = 0;
        pickupSteps=0;
        dropSteps=0;
        currentLocation[0] = 0;
        currentLocation[1]=0;

        for (int j = 0 ; j < nop; ++j)
        {

            int pickupIndex = routes[i][j];
            x1 = passengers[pickupIndex][1];
            y1 = passengers[pickupIndex][2];
            x2 = passengers[pickupIndex][3];
            y2 = passengers[pickupIndex][4];
            pickupDropDistance = distance(x1,y1, currentLocation[0], currentLocation[1]);

            dropDistance = distance(x1, y1, x2, y2);

            pickupSteps = (abs(x1- currentLocation[0])+abs(y1- currentLocation[1]));

            dropSteps = (abs(x1- x2)+abs(y1- y2));

            sum[i]+= profit(pickupSteps, dropSteps, dropDistance,  passengers[pickupIndex][0]);

            //printf("|%d:%f\n", i, profit(pickupSteps, dropSteps, dropDistance,  passengers[pickupIndex][0]));
            int waitTime = passengers[pickupIndex][0]-currentTime-pickupSteps;
            if(waitTime > 0)
                waitTime = abs(waitTime);
            else
                waitTime=0;
            currentTime = currentTime + pickupSteps + dropSteps+ waitTime;
            updateLocation(currentLocation, x2, y2);

        }
    }

    int routeIndex = maxIndex(sum, maxRoutes);
    finalRoute(passengers, routes[routeIndex], nop);

    for(int i =0; i < maxRoutes; i++)
        printf("|%d:%f\n", i, sum[i]);
    for(int i= 0; i<maxRoutes;i++){
        for(int j=0;j<nop;j++){
            printf("%d:{%d}",i,  routes[i][j]);}
        printf("\n");
    }
    printf("|%f", sum[routeIndex]);

}


void permuteRoutes(int routes[][100], int *arr, int n, int l)

{
    static int k=0, m=0;
    
    if(l==n-1)
    {
        for(int i=0; i<n; i++){
            routes[m][i]=arr[i];
            printf("$%d$", routes[m][i]);
            k++;
            if((k%n) == 0)
                ++m;
        }
    }
    for(int i=l; i<n; i++)
    {
        swap(&arr[i], &arr[l]);
        permuteRoutes(routes, arr, n, l+1);
        swap(&arr[i], &arr[l]);
    }
    
    
}


float distance(int x1, int y1, int x2, int y2)

{
    int x =pow(x1-x2, 2);
    int y = pow(y1-y2, 2);
    float z = pow((x+y), 0.5);
    return z;
}


void updateLocation(int location[], int x, int y)

{
    location[0] = x;
    location[1] = y;
}

/* Profit Factor - Lower it is more is profit
 Fare = (Distance b/w Pickup & Drop)/(Profit Factor + Distance to Pickup)
 */

float profit(int pickupSteps, int dropSteps, float dropDistance, int requestTime)
{
    float a = dropSteps + abs(pickupSteps - (requestTime - currentTime));
    if((pickupSteps - (requestTime - currentTime))<0)
        a=dropSteps;
    float b = dropDistance;
    
    return ((float)b)/a;
}

void findPath(int currentLocation[], int x1, int y1, int x2, int y2, int waitTime)
{
    int x= currentLocation[0];
    int y = currentLocation[1];
    for(int k =0; k<2; ++k){
        while(x!=x1  || y!=y1)
        {
            if(x>x1){
                printf("1");
                --x;}
            else if(x<x1){
                printf("3");
                ++x;}
            
            if(y>y1){
                printf("4");
                --y;}
            else if(y<y1){
                printf("2");
                ++y;}
        }
        while(waitTime != 0)
        {
            printf("0");
            --waitTime;
        }
        
        x=x1;
        y=y1;
        x1=x2;
        y1=y2;
        
    }
    
}

int maxIndex(float profit[], int n)
{
    float max = profit[0];
    int maxIndex=0;
    for(int i=0; i<n;++i)
    {
        if(profit[i]>max)
        {
            max = profit[i];
            maxIndex=i;
        }
    }
    
    return maxIndex;
}

void finalRoute(int passengers[][5], int route[], int numberOfPassengers)
{
    /*    for(int j=0;j<numberOfPassengers;j++){
     printf("{%d}", route[j]);}*/
    float sum = 0.0, pickupDropDistance, dropDistance; //Sum of all profit factors in each possible route
    int currentTime = 0;
    int pickupSteps=0;
    int dropSteps=0;
    int currentLocation[2] = {0, 0};
    int x1, x2, y1, y2;
    
    for (int i = 0 ; i < numberOfPassengers; ++i)
    {
        
        int pickupIndex = route[i];
        x1 = passengers[pickupIndex][1];
        y1 = passengers[pickupIndex][2];
        x2 = passengers[pickupIndex][3];
        y2 = passengers[pickupIndex][4];
        pickupDropDistance = distance(x1,y1, currentLocation[0], currentLocation[1]);
        
        dropDistance = distance(x1, y1, x2, y2);
        
        pickupSteps = (abs(x1- currentLocation[0])+abs(y1- currentLocation[1]));
        
        dropSteps = (abs(x1- x2)+abs(y1- y2));
        
        sum= sum + profit((abs(x1- currentLocation[0])+abs(y1- currentLocation[1])), dropSteps, dropDistance,  passengers[pickupIndex][0]);
        
        
        
        int waitTime = passengers[pickupIndex][0]-currentTime-pickupSteps;
        if(waitTime > 0)
            waitTime = abs(waitTime);
        else
            waitTime=0;
        
        findPath(currentLocation, x1, y1, x2, y2, waitTime);
        
        currentTime = currentTime + pickupSteps + dropSteps + waitTime;
        
        updateLocation(currentLocation, x2, y2);
        
    }
}

#include <iostream>
using namespace std;

void minimum_cost() {
    
    int X = 3, Y = 3;
    int cost[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    
//    for(int i = 0; i < X; i++) {
//
//        for(int j = 0; j < Y; j++) {
//            cout << "E: "; cin >> cost[i][j];
//        }
//    }
    
    int min_cost[X][Y];
    min_cost[0][0] = cost[0][0];
    
    for(int i = 1; i < Y; i++)
        min_cost[i][0] = min_cost[i-1][0] + cost[i][0];
    for(int j = 1; j < X; j++)
        min_cost[0][j] = min_cost[0][j-1] + cost[0][j];
    
    
    for(int i = 1; i < X; i++) {
        
        for(int j = 1; j < Y; j++) {
            min_cost[i][j] = min(min_cost[i-1][j], min_cost[i][j-1]) + cost[i][j];
        }
    }
    
    cout << "Minimum cost from (0,0) to (X, Y) is " << min_cost[X-1][Y-1] << endl;
    
}

#define MOD 1000000007

void blocked_min_path() {
    
    int M, N, P, a, b;
    
    cout << "M: "; cin >> M; cout << "N: "; cin >> N; cout << "P:"; cin >> P;
    
    int grid[M][N];
    
    for(int i = 0; i < M; i++)
        for(int j = 0; j < N; j++)
            grid[i][j] = 0;
    
    for(int i = 0; i < P; i++) {
        cout << "a: "; cin >> a; cout << "b: "; cin >> b;
        grid[a][b] = -1;
    }
    
    if(grid[0][0] == -1)
        return;
    
    for(int i = 0; i < M; i++)
        
        if(grid[i][0] == 0)
            grid[i][0] = 1;
        else
            break;
    
    for(int i = 1; i < N; i++)
        
        if(grid[1][i] == 0)
            grid[1][i] = 1;
        else
            break;
    
    for(int i = 1; i < M; i++)
        
        for(int j = 1; j < N; j++) {
            
            if(grid[i][j] == -1)
                continue;
            
            if(grid[i-1][j] > 0)
                grid[i][j] = (grid[i][j] + grid[i-1][j] + MOD) % MOD;
            
            if(grid[i][j-1] > 0)
                grid[i][j] = (grid[i][j] + grid[i][j-1] + MOD) % MOD;
        }
    
    cout << (grid[M-1][N-1] >= 0 ? grid[M-1][N-1] : 0) << endl;
    

}







































