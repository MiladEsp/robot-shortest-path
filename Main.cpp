/**
    @author Milad Esmaeilpour
    @version 1.0 August 6, 2020
    @file Main.cpp

    This file contains the main() function of the C++ program.
*/

/**
    Assumption: In order to reach the target (100,100) from the origin (0,0), any number of waypoints may be skipped depending on their penalty values.

    This means that the entire problem can be seen as a directed graph where each node (i.e. waypoint) is connected to all the nodes that come after it. That is, assuming we have n nodes,
    the origin is connected to nodes {2, 3, ..., n}, node 2 is connected to nodes {3, 4, ..., n), ... and node n-1 is connected to only node n.

    The wait time of 10 seconds at each node, the time to travel to other nodes and the penalties associated with skipping the nodes will be accounted for in the
    weights of the directed edges connecting the nodes.

    The problem of finding the shortest time from origin to the target point can then be solved via the Dijkstra algorithm.
*/

/**
    Due to lack of time, following are the areas where the current program could be further improved:

    1 - The Dijkstra algorithm currently uses std::set for storing and retrieving the shortest times.
    However, by using std::priority_queue, the performance of the algorithm could be improved.

    2 - Currently, it is assumed that the user input will exactly match what is described in the problem description.
    Not following the exact format can lead to the program crashing. Exception handling and error checking will need to be implemented.
    In addition, since this program might be deployed on an autonomous robot, safety measures will also have to be added to the code, e.g. a kill switch
    or an automatic shut down in case the robot sensors indicate sudden motion or deviation from the expected path.
*/

#include "Solution.h"

int main() {
    Solution solution;

    solution.readInput();

    unsigned int node_set_count = solution.nodeSetCount();

    Graph *graph_set = new Graph [node_set_count];

    solution.parseInput(graph_set);

    for (unsigned int i = 0;i < node_set_count;i++) {
        graph_set[i].shortestTime();
    }

    delete[] graph_set;

    return 0;
}
