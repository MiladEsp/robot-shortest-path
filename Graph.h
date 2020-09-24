/**
    @author Milad Esmaeilpour
    @version 1.0 August 6, 2020
    @file Graph.h

    This file contains the declaration of the Graph and GraphNode classes.
*/

#pragma once

#include <cmath>
#include <iostream>
#include <list>
#include <set>
#include <vector>

#define ORIGIN_X 0
#define ORIGIN_Y 0
#define TARGET_X 100
#define TARGET_Y 100
#define ROBOT_SPEED 2
#define NODE_WAIT_TIME 10

class Graph {
   public:
    Graph();
    ~Graph();

    void addNode(int x, int y, int penalty);  // Adds a node to the graph
    void shortestTime();                      // Finds the shortest time to go from the origin to the target

   private:
    class GraphNode {
       public:
        int x, y, penalty;  // Each node of the graph has these three attributes

        GraphNode();
        GraphNode(int x, int y, int penalty);
        ~GraphNode();
    };

    int v;                                  // Number of nodes in the graph
    std::vector<GraphNode> nodes;           // A vector containing all the nodes in the graph
    std::list<std::pair<int, float>>* adj;  // Adjacency list corresponding to the edge and weight pairs

    float edgeWeight(int start_node, int end_node);  // Calculates the weight of an edge between two points
    void addEdge(int start_node, int end_node);      // Adds an edge from the start_node to the end_node with the proper weight to the adjacency list
    void constructAdjList();                         // Initializes and creates the adjacency list
};