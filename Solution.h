/**
    @author Milad Esmaeilpour
    @version 1.0 August 6, 2020
    @file Solution.h

    This file contains the declaration of the Solution class.
*/

#pragma once

#include <string>
#include <sstream>
#include "Graph.h"

class Solution {
public:
    Solution();
    ~Solution();

    void readInput(); // Reads the user input
    unsigned int nodeSetCount(); // Counts how many set of nodes were input by the user
    void parseInput(Graph *graph_set); // Parses the input and adds nodes with proper x, y, penalty values to the graph

private:
    std::string input;

    std::string splitString(std::string &s);
};