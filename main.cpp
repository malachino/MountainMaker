#include <iostream>
#include "mountains.h"
#include "mountains.cpp"
using namespace std;

int main() {
    // Ask user for a mountain name
    cout << "Please enter a mountain name: ";
    string name;
    getline(cin, name);

    Topograph mountain = {0};
    int startSize = 8;          //  dimensions of topogrpahical map to begin with
    int multipler = 2;          //  how much to upscale by when you upscale   
    float whenToUpscale = 0.2;  //  what percent of the map filled to upscale it

    Create(mountain, startSize, multipler, whenToUpscale);
    
    displayFromTop(mountain);

    for(int i = 0; i < name.length(); i++){
        cout << "-";
    }
    
    cout << endl << name.c_str() << endl;
    
    for(int i = 0; i < name.length(); i++){
        cout << "-";
    }
     cout << endl << endl;
    return 0;
}