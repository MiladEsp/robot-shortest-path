/**
    @author Milad Esmaeilpour
    @version 1.0 August 6, 2020
    @file Solution.cpp
    
    This file contains the definition of the Solution class.
*/

#include "Solution.h"

// Constructor for the Solution class
Solution::Solution() : input("") {}

// Destructor for the Solution class
Solution::~Solution() {}

// Reads the user input
void Solution::readInput() {
    std::string line = "";

    while (!std::cin.eof()) {

        if (std::getline(std::cin, line)) {

            input.append(line);
            input.append("\n");
        }
    }
}

// Counts how many set of nodes were input by the user
unsigned int Solution::nodeSetCount() {
    std::istringstream iss(input);
    std::string token = "";

    unsigned int node_set_count = -1; // Since it will also count the 0 at the end of the input

    while (getline(iss, token)) {
        if (token.find(" ") == std::string::npos) {
            node_set_count++;
        }
    }
    return node_set_count;
}

// Parses the input and adds nodes with proper x, y, penalty values to a graph
void Solution::parseInput(Graph *graph_set) {
    std::istringstream iss(input);
    std::string token = "";

    int graph_set_index = -1; // Since C++ indexing starts from 0 and the if statement below is triggered at the beginning

    while (getline(iss, token)) {
        if (token.find(" ") == std::string::npos) {
            if (graph_set_index != -1) {
                // Append the target node to the end of the graph
                graph_set[graph_set_index].addNode(TARGET_X, TARGET_Y, 0);
            }
            // A new set of nodes is going to be saved
            graph_set_index++;
        }
        else {
            // Find the x, y, penalty values for a specific node and add it to the graph
            int temp_x = atoi(splitString(token).c_str());
            int temp_y = atoi(splitString(token).c_str());
            int temp_penalty = atoi(splitString(token).c_str());

            graph_set[graph_set_index].addNode(temp_x, temp_y, temp_penalty);
        }
    }
}

// Used to find the x, y, penalty values of each node from the user input
std::string Solution::splitString(std::string &s) {

    size_t pos = 0;
    std::string token = "";

    // Create a substring from the start of the string to the space
    pos = s.find(" ");
    token = s.substr(0, pos);

    // Erase the substring
    s.erase(0, pos + 1);

    return token;
}