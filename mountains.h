#ifndef MOUNTAINS_H
#define MOUNTAINS_H

// Define a type for 2D array
const int mountainRadius = 16;
const int maxHeight = 100;
const int selected = 999;
typedef int Topograph[2*mountainRadius][2*mountainRadius];
typedef char Skyline[maxHeight][2*mountainRadius];

//  ------------------------------------------------------------------------------------------
//  Modification Functions
    void Nucleate(Topograph& mountainName, int x, int y);       // adds a point at (x,y) to the graph
    void Grow(Topograph& mountainName, int startSize, int step, int whenToUpscale);// adds a new point to the structure
    void Blur(Topograph& mountainName, int value);              // blurs the graph
    void Upscale(Topograph& mountainName, int multipler);       // upscale the graph by a multiplier

    void Create(Topograph& mountainName, int startSize, int multiplier, int whenToUpscale);
        // startSize:       dimensions of topogrpahical map to begin with
        // multipler:       how much to upscale by when you upscale   
        // whenToUpscale:   what percent of the map filled to upscale it
//  ------------------------------------------------------------------------------------------


//  ------------------------------------------------------------------------------------------
//  Display Functions
    void displayFromTop(const Topograph& mountainName);     // displays the mountain from above
    void displayFromNorth(const Topograph& mountainName);   // displays the mountain from the North
    void displayFromEast(const Topograph& mountainName);    // displays the mountain from the East
    void displayFromSouth(const Topograph& mountainName);   // displays the mountain from the South
    void displayFromWest(const Topograph& mountainName);   // displays the mountain from the West
//  ------------------------------------------------------------------------------------------

#endif // MOUNTAINS_H