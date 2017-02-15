//
//  Puzzle.cpp
//  partial8Puzzle
//
//  Created by Ibrahim Conteh on 2/11/17.
//  Copyright © 2017 Ibrahim Conteh. All rights reserved.
//

#include "Puzzle.hpp"

std::map<char, XY> DESIRED = {
    {'0', {.x = 0, .y = 2}},
    {'1', {.x = 1, .y = 2}},
    {'2', {.x = 2, .y = 2}},
    {'3', {.x = 0, .y = 1}},
    {'4', {.x = 1, .y = 1}},
    {'5', {.x = 2, .y = 1}},
    {'6', {.x = 0, .y = 0}},
    {'7', {.x = 1, .y = 0}},
    {'8', {.x = 2, .y = 0}},
};

const std::string GOAL = "012345678";

// Make a new move and return the string config.
std::string makeMove(std::string oldString, int spot1, int spot2) {
    std::string newString = oldString;
    char charHolder = newString[spot1];
    
    newString[spot1] = newString[spot2];
    newString[spot2] = charHolder;
    
    return newString;
}

/*
// Constructor.
Puzzle::Puzzle() {
    std::cout << "New Board: " << randStr << std::endl;
    e_Puzzle = randStr;
    heuristic = 0;
    this->calCostFunc();
}
 */

// Constructor.
Puzzle::Puzzle(std::string newString) {
    e_Puzzle = newString;
    heuristic = 0;
    this->calCostFunc();
}

// Calculate the cost function for the algorithm.
void Puzzle::calCostFunc() {
    std::map<int, int> heuristicChart;
    XY points, end;
    int total = 0;
    int castTotal;
    // Caculate the heuristic of displacement for each piece and store it within a map structure.
    for (int count = 0; count < e_Puzzle.length(); count++) {
        end = DESIRED[e_Puzzle[count]];
        if (e_Puzzle[count] == '0') {
            // Do this because 0 cannot account for a space and it breaks the cost func.
            total = 1;
            heuristicChart.insert(std::pair<int, int>(count, total));
            continue;
        } else if (e_Puzzle[count] != GOAL[count]) {
            if (count < 3) {
                points.y = 2;
            } else if (count < 6) {
                points.y = 1;
            } else {
                points.y = 0;
            }
            points.x = count % 3;
            total = abs(points.x - end.x) + abs(points.y - end.y);
            heuristicChart.insert(std::pair<int, int>(count, total));
        } else {
            total = 0;
            heuristicChart.insert(std::pair<int, int>(count, total));
        }
    }
    
    // Take the map and use the values to calculate the total cost value.
    for (int count = 1; count < 7; count++) {
        total = (heuristicChart[count] + heuristicChart[count+1] + heuristicChart[count+2]);
        if (count == 1) {
            heuristic = total;
        }
        
        else {
            heuristic = heuristic * total;
        }
    }
    
    //std::cout << heuristic << std::endl;
}

// Generate the children for the puzzle. The heristics are not recorded at this point.
std::vector<std::string> Puzzle::getChildren() {
    // This stores the newMoves.
    std::vector<std::string> newMoveVector;
    // New moves are made.
    std::string newMove;
    int zeroSpot = static_cast<int>(e_Puzzle.find('0'));
    // Puzzle.
    
    switch (zeroSpot) {
        case 0:
            // For index 1.
            newMove = makeMove(e_Puzzle, zeroSpot, 1);
            newMoveVector.push_back(newMove);
            
            // For index 3.
            newMove = makeMove(e_Puzzle, zeroSpot, 3);
            newMoveVector.push_back(newMove);
            break;
            
        case 1:
            // For index 0.
            newMove = makeMove(e_Puzzle, zeroSpot, 0);
            newMoveVector.push_back(newMove);
            
            // For index 4.
            newMove = makeMove(e_Puzzle, zeroSpot, 4);
            newMoveVector.push_back(newMove);
            
            // For index 2.
            newMove = makeMove(e_Puzzle, zeroSpot, 2);
            newMoveVector.push_back(newMove);
            break;
            
        case 2:
            // For index 1.
            newMove = makeMove(e_Puzzle, zeroSpot, 1);
            newMoveVector.push_back(newMove);
            
            // For index 5.
            newMove = makeMove(e_Puzzle, zeroSpot, 5);
            newMoveVector.push_back(newMove);
            break;
            
        case 3:
            // For index 0.
            newMove = makeMove(e_Puzzle, zeroSpot, 0);
            newMoveVector.push_back(newMove);
            
            // For index 4.
            newMove = makeMove(e_Puzzle, zeroSpot, 4);
            newMoveVector.push_back(newMove);
            
            // For index 6.
            newMove = makeMove(e_Puzzle, zeroSpot, 6);
            newMoveVector.push_back(newMove);
            break;
            
        case 4:
            // For index 1.
            newMove = makeMove(e_Puzzle, zeroSpot, 1);
            newMoveVector.push_back(newMove);
            
            // For index 3.
            newMove = makeMove(e_Puzzle, zeroSpot, 3);
            newMoveVector.push_back(newMove);
            
            // For index 5.
            newMove = makeMove(e_Puzzle, zeroSpot, 5);
            newMoveVector.push_back(newMove);
            
            // For index 7.
            newMove = makeMove(e_Puzzle, zeroSpot, 7);
            newMoveVector.push_back(newMove);
            break;
            
        case 5:
            // For index 2.
            newMove = makeMove(e_Puzzle, zeroSpot, 2);
            newMoveVector.push_back(newMove);
            
            // For index 4.
            newMove = makeMove(e_Puzzle, zeroSpot, 4);
            newMoveVector.push_back(newMove);
            
            // For index 8.
            newMove = makeMove(e_Puzzle, zeroSpot, 8);
            newMoveVector.push_back(newMove);
            break;
            
        case 6:
            // For index 3.
            newMove = makeMove(e_Puzzle, zeroSpot, 3);
            newMoveVector.push_back(newMove);
            
            // For index 7.
            newMove = makeMove(e_Puzzle, zeroSpot, 7);
            newMoveVector.push_back(newMove);
            break;
            
        case 7:
            // For index 4.
            newMove = makeMove(e_Puzzle, zeroSpot, 4);
            newMoveVector.push_back(newMove);
            
            // For index 6.
            newMove = makeMove(e_Puzzle, zeroSpot, 6);
            newMoveVector.push_back(newMove);
            
            // For index 8.
            newMove = makeMove(e_Puzzle, zeroSpot, 8);
            newMoveVector.push_back(newMove);
            break;
            
        case 8:
            // For index 5.
            newMove = makeMove(e_Puzzle, zeroSpot, 5);
            newMoveVector.push_back(newMove);
            
            // For index 7.
            newMove = makeMove(e_Puzzle, zeroSpot, 7);
            newMoveVector.push_back(newMove);
            break;
            
        default:
            break;
    }
    
    return newMoveVector;
}

std::vector<Puzzle> Puzzle::generateChildren() {
    std::vector<Puzzle> newChildren;
    std::vector<std::string> stringRepresentation = this->getChildren();
    for (int count = 0; count < stringRepresentation.size(); count++) {
        Puzzle p = Puzzle(stringRepresentation[count]);
        newChildren.push_back(p);
    }
    
    return newChildren;
}
