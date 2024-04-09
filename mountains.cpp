#include "mountains.h"
#include <iostream>
#include <cmath>
using namespace std;
//  ------------------------------------------------------------------------------------------
//          Modification Functions
//  ------------------------------------------------------------------------------------------



void Nucleate(Topograph& mountainName, int x, int y) {
    // Add a point at (x, y) to the graph
    mountainName[x][y] = 10000;
}

void Grow(Topograph& mountainName, int startSize, int step, int whenToUpscale) {
    // Add a new point to the structure
    
    int added = 0;
    int boxSize = startSize*(pow(2,step));
    //while (added/boxSize < whenToUpscale)  //while fewer than the percent have been added
    for(int i = 0; i < 2*boxSize; i++)
    {
        //code to add a random point
        int x = 0.5*boxSize + rand()%(boxSize/2);
        int y = 0.5*boxSize + rand()%(boxSize/2);
        bool done = false;
        while(done == false){
            if( (x < boxSize - 1    && mountainName[x + 1][y + 0]) >= selected ||
                (y < boxSize - 1    && mountainName[x + 0][y + 1]) >= selected ||
                (       x > 0       && mountainName[x - 1][y + 0]) >= selected ||
                (       y > 0       && mountainName[x + 0][y - 1]) >= selected   )
            {
                cout << "marking (" << to_string(x).c_str() << "," << to_string(y).c_str() << ")" << endl;
                mountainName[x][y] += selected;  
                done = true;
            }
            else{
                //pick a random either x or y
                int xORy = rand();
                int upORdown = rand();
                if(xORy%2 == 0){
                    if(x == 0){
                        x = 1;
                    }else if(x == boxSize - 1){
                        x = boxSize - 2;
                    }else{
                        if(upORdown%2 == 0){
                            x++;
                        }else{
                            x--;
                        }
                    }
                }else{
                    if(y == 0){
                        y = 1;
                    }else if(y == boxSize - 1){
                        y = boxSize - 2;
                    }else{
                        if(upORdown%2 == 0){
                            y++;
                        }else{
                            y--;
                        }
                    }
                }
            }
        }    
        added++;
    }
}

void Blur(Topograph& mountainName, int value) {
    // Implementation for Blur function
    // Blur the graph with the specified value
    // Modify the mountainName accordingly
}

void Upscale(Topograph& mountainName, int multiplier) {
    // Implementation for Upscale function
    // Upscale the graph by the specified multiplier
    // Modify the mountainName accordingly
}

void Create(Topograph& mountainName, int startSize, int multiplier, float whenToUpscale) {
    // Create a topographical map based on provided parameters
    
    int x = startSize/4 + rand()%(startSize/2);
    int y = startSize/4 + rand()%(startSize/2);
    Nucleate(mountainName, x, y);
    //displayFromTop(mountainName);
    Grow(mountainName, startSize, 0, whenToUpscale);
    
    
}

//  ------------------------------------------------------------------------------------------
//          Display Functions
//  ------------------------------------------------------------------------------------------
void displayFromTop(const Topograph& mountainName) {
    // Display the mountain from above
    for(int x = 0; x < 2*mountainRadius; x++){
        for(int y = 0; y < 2*mountainRadius; y++){
            cout << mountainName[x][y];
            cout << " ";
        }
        cout << endl;
    }
}

void displayFromNorth(const Topograph& mountainName) {
    // Implementation for displayFromNorth function
    // Display the mountain from the North
}

void displayFromEast(const Topograph& mountainName) {
    // Implementation for displayFromEast function
    // Display the mountain from the East
}

void displayFromSouth(const Topograph& mountainName) {
    // Implementation for displayFromSouth function
    // Display the mountain from the South
}

void displayFromWest(const Topograph& mountainName) {
    // Implementation for displayFromWest function
    // Display the mountain from the West
}