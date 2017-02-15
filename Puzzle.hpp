//
//  Puzzle.hpp
//  partial8Puzzle
//
//  Created by Ibrahim Conteh on 2/11/17.
//  Copyright © 2017 Ibrahim Conteh. All rights reserved.
//

#ifndef Puzzle_hpp
#define Puzzle_hpp

#include <ctime>
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <stdio.h>
#include <cstdlib>
#include <string>
#include <vector>

// This struct is representative of the x-y coordinate plane.
struct XY {
    int x;
    int y;
};

class Puzzle {
private:
    int heuristic;
    std::string e_Puzzle;
public:
    // Constructor.
    //Puzzle();
    
    // Constructor.
    Puzzle(std::string);
    
    // Get the children of the puzzle.
    std::vector<std::string> getChildren();
    
    // Generate the children.
    std::vector<Puzzle> generateChildren();
    
    // Overloading.
    bool operator<(const Puzzle &p) const { return heuristic < p.heuristic; };
    
    // Overloading.
    bool operator==(const Puzzle &p) const { return heuristic == p.heuristic; };

    // Return board.
    std::string returnBoard() const { return e_Puzzle; };
    
    // Calculate the cost function.
    void calCostFunc();
    
    // Return the heuristic value.
    int returnheuristic() const { return heuristic; };
};
#endif /* Puzzle_hpp */
