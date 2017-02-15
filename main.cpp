//
//  main.cpp
//  partial8Puzzle
//
//  Created by Ibrahim Conteh on 2/11/17.
//  Copyright © 2017 Ibrahim Conteh. All rights reserved.
//

#include <ctime>
#include <fstream>
#include <iostream>
#include <vector>
#include "Puzzle.hpp"

bool isValid(std::string);
void hillClimbingRand(Puzzle);
std::string randPuzzle();

int main(int argc, const char * argv[]) {
    // Random generator.
    srand(time(0));
    
    Puzzle p = Puzzle(randPuzzle());
    hillClimbingRand(p);
    return 0;
}

// This is the hill climbing algorithm.
void hillClimbingRand(Puzzle p) {
    std::fstream fileOpen;
    fileOpen.open("state.txt", std::fstream::out);
    // This is the count for how many times the algorithm restarts.
    int restartCount = 0;
    // This is the bool that indicates the global min.
    bool no_gloMin;
    // This is the bool to determine whether the global min has been reached.
    bool min = false;
    // Plateau
    bool no_plateau;
    // This vector stores the children of the current state.
    std::vector<Puzzle> children;
    // This puzzle stores the current puzzle state.
    Puzzle currentPuzzle = p;
    // Loop count for multiple loops of a certain child to parent config.
    int l_count = 0;
    fileOpen << "Start: " << currentPuzzle.returnBoard() << std::endl;
    
    do {
        no_plateau = true;
        no_gloMin = true;
        
        if (currentPuzzle.returnheuristic() == 0) {
            fileOpen << "Found: " << currentPuzzle.returnBoard() << std::endl;
            fileOpen << "Restarts: " << restartCount << std::endl;
            //fileOpen << "Statistics: " << (1 / restartCount)
            std::cout << "Found\n";
            min = true;
            break;
        }
        
        children = currentPuzzle.generateChildren();
        
        // Check if the children plateau.
        for (int count = 0; count < children.size(); count++) {
            if (children[count].returnheuristic() != currentPuzzle.returnheuristic()) {
                no_plateau = true;
                break;
            }
        }
        
        for (int count = 0; count < children.size(); count++) {
            
            if (children[count].returnheuristic() < currentPuzzle.returnheuristic()) {
                currentPuzzle = children[count];
                no_gloMin = true;
            }
            
        }
        
        if (no_plateau || no_gloMin || l_count == 10000) {
            currentPuzzle = Puzzle(randPuzzle());
            fileOpen << currentPuzzle.returnBoard() << std::endl;
            restartCount += 1;
            l_count = 0;
        }
        
        l_count++;
        
    } while (!min);

    fileOpen.close();
    
}

bool isValid(std::string e_Puzz) {
    int inv_count = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = i + 1; j < 9; j++) {
            // Value 0 is used for empty space
            if (e_Puzz[j] && e_Puzz[i] && e_Puzz[i] > e_Puzz[j]) {
                inv_count++;
            }
        }
    }
    
    return (inv_count % 2 == 0);
}

std::string randPuzzle() {
    // This generates a random state.
    std::string randStr = "012345678";
    do {
        for (int count = 7; 0 < count; count--) {
            int randIdx = rand() % (count + 1);
            
            char swapHolder = randStr[randIdx];
            randStr[randIdx] = randStr[count];
            randStr[count] = swapHolder;
        }
    } while (!isValid(randStr));
    return randStr;
}
