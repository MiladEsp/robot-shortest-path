/**
    @author Milad Esmaeilpour
    @version 1.0 August 6, 2020
    @file Graph.cpp
    
    This file contains the definition of the Graph and GraphNode classes.
*/

#include "Graph.h"

// Constructor for the Graph class
Graph::Graph() {
    addNode(ORIGIN_X, ORIGIN_Y, 0); // Adds origin as the first node to the graph
    v = 1;
}

// Destructor for the Graph class 
Graph::~Graph() { 
    delete[] adj; // Frees the memory allocated to the adjacency list on the heap
}

// A constructor for the GraphNode class
Graph::GraphNode::GraphNode() : x(0), y(0), penalty(0) {}

// A constructor for the GraphNode class
Graph::GraphNode::GraphNode(int x, int y, int penalty) : x(x), y(y), penalty(penalty) {}

// Destructor for the GraphNode class
Graph::GraphNode::~GraphNode() {}

/**
    Adds a node the graph with x, y, penalty values
    Increments the node count of the graph
*/
void Graph::addNode(int x, int y, int penalty) {
    nodes.emplace_back(x, y, penalty);
    v++;
}

/**
    Calculates the weight of an edge between the start and end nodes
    The weight is based on the time it will take the robot to reach the end node from the start node
    The wait time at the end node or the penalties in case some nodes are skipped are also considered in the weight
*/
float Graph::edgeWeight(int start_node, int end_node) {
    float weight;

    // Calculates the total penalty incured by skipping all the nodes in between the start and the end
    auto sumPenalties = [&](int start, int end) {
        int total_penalty = 0;
        for (int i = start+1;i < end; i++) {
            total_penalty += nodes[i].penalty;
        }
        return total_penalty;
    };

    // Calculates the time needed to travel from the start node to the end
    auto timeToTravel = [&](int start, int end) {
        return std::sqrt(std::pow((nodes[end].x - nodes[start].x), 2) + std::pow((nodes[end].y - nodes[start].y), 2)) / ROBOT_SPEED;
    };

    // If the two nodes are immediate nodes, the weight will be the time to travel from the start node to the end node plus the wait time at the end node
    if (end_node - start_node == 1) {
        weight = timeToTravel(start_node, end_node) + NODE_WAIT_TIME;
    }
    // The start and end nodes are not immediate nodes, so the penalties for skipping some nodes will need to be considered
    else {
        weight = timeToTravel(start_node, end_node) + sumPenalties(start_node, end_node) + NODE_WAIT_TIME;
    }

    return weight;
}

/**
    Adds an edge with the correct weight to the adjacency list
    Since the problem is formulated as a directed graph, there will be only one edge from the start to the end
*/
void Graph::addEdge(int start_node, int end_node) {
    float weight = edgeWeight(start_node, end_node);
   
    adj[start_node].push_back(std::make_pair(end_node, weight));
}

/**
    Initializes and constructs the adjacency list
    The problem is formulated as a directed graph where every node is connected to all the nodes after it
*/
void Graph::constructAdjList() {
    adj = new std::list <std::pair<int, float>>[v];

    for (int i = 0;i < v;i++) {
        for (int j = i + 1;j < v;j++) {
            addEdge(i, j);
        }
    }
}

/**
    Finds the shortest time from the origin to the target via the Dijkstra algorithm
*/
void Graph::shortestTime() {
    constructAdjList();

    /**
        Create a set to store nodes that are being processed
        First key stores the weight, and the second key stores the node
        Since it's a set, it will be sorted
    */
    std::set<std::pair<float, int>> bucket;

    // Create a vector for shortest time and initialize all instances to INFINITY
    std::vector<float> shortest_time(v, INFINITY);

    // Initialize the set by inserting the origin with a time of zero
    bucket.insert(std::make_pair(0.0, 0));
    shortest_time[0] = 0.0;

    // Loop until all shortest times are finalized at which point the bucket will be an empty set
    while (bucket.size()) {
        
        // First node in set is the shortest time node. Extract it from the set
        std::pair<float, int> tmp = *(bucket.begin());
        bucket.erase(bucket.begin());

        // node label is stored in the second element of the pair
        int start_node = tmp.second;

        // Iterate through all adjacent vertices of `u'
        std::list<std::pair<int, float>>::iterator it;
        for (it = adj[start_node].begin(); it != adj[start_node].end(); it++) {
            int end_node = it->first;
            float weight = it->second; // Weight of the edge from the start_node to end_node

            // Check if there is shorter path to v through u
            if (shortest_time[end_node] > shortest_time[start_node] + weight) {

                /**
                    If shortest_time[v] is not INFINITY, it means that it already is
                    in the set bucket, so remove it and insert it again with an updated lesser time
                */
                if (shortest_time[end_node] != INFINITY)
                    bucket.erase(bucket.find(std::make_pair(shortest_time[end_node], end_node)));

                // Update the lesser time of v and insert into the set
                shortest_time[end_node] = shortest_time[start_node] + weight;
                bucket.insert(std::make_pair(shortest_time[end_node], end_node));
            }
        }
    }

    // Print out the shortest time from the origin to the target rounded to three decimal places
    std::cout.setf(std::ios::fixed, std::ios::floatfield);
    std::cout.precision(3);
    std::cout << std::roundf(shortest_time[v - 1] * 1000) / 1000 << std::endl;
}
