# Problem Description

Consider a 100m by 100m area. Certain points are identified within the space as waypoints for your robot to visit. The points are ordered, i.e., there is a waypoint 1, a waypoint 2, etc. Your robot must start at (0,0). From there, it should go to waypoint 1, stop for 10 second, go to waypoint 2, stop for 10 second, and so on. It must finally end up at, and stop for 10 second on (100,100).
Each waypoint except (0,0) and (100,100) has a time penalty for missing it. As a result, if your robot goes straight from waypoint 1 to waypoint 3, skipping waypoint 2, it would incur waypoint 2's penalty. Once your robot hits waypoint 3, it cannot go back to waypoint 2. Since your robot must stop for 10 seconds on each waypoint, it is not in danger of hitting a waypoint accidentally too soon. For example, if waypoint 3 lies directly between waypoints 1 and 2, your robot can go straight from 1 to 2, right over 3, without stopping. Your final score is the amount of time (in seconds) your robot takes to reach (100,100), completing the course, plus all penalties. Smaller scores are better.

Consider that your robot moves at a speed of 2 m/s, but it can turn very quickly. Assume that it always moves in straight lines between target points. Since the robot is slow, it might be better to skip some waypoints and incur their penalty, rather than actually maneuvering to them. Given a description of a course, determine the robot's best (lowest) possible time.

## Input  

There will be several test cases fed into your solution via stdin. Each test case will begin with a line with one integer, N (1 <= N <= 1000) which is the number of waypoints on the course. Each of the next N lines will describe a waypoint with three integers, X, Y and P, where (X, Y) is a location on the course ( 1 <= X, Y <= 99, X and Y in meters) and P is the penalty incurred if your robot misses that waypoint (1 <= P <= 100). The waypoints will be given in order -- the first line after N is target 1, the next is waypoint 2, and so on. All the waypoints on a given course will be unique -- there will be at most one waypoint point at any location on the course. End of input will be marked by a line with a single 0.

## Output  

For each test case, output a single decimal number, indicating the smallest possible time for that course. Output this number rounded (NOT truncated) to three decimal places. Print each answer on its own line on stdout and do not print any blank lines between answers.


## How to run the program

First, build the program on your computer. Place the input to the program in a text file in the format described above (**sample_input.txt** for example). Then enter the following command and the shortest time to reach the target from the origin will be shown on the command prompt.

```
cat sample_input.txt | ./solution_exe
```

If you want to save the result to a text file, enter the following command.

```
cat sample_input.txt | ./solution_exe | tee sample_output.txt
```
