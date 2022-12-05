#include <iostream>
#include <cstdlib>
#include "StackQueue.h"
#include "Maze.h"
#include "Left_Hand_Rule.hpp"

using namespace std;

int main()
{
    Maze maze("input_maze.txt");
    StackQueue<char> stackqueue;

    cout << "First Pass:" << endl;
    while(!maze.is_solved()){
        LeftHandRule(maze, stackqueue);
        stackqueue.print_elements();
        maze.print_state();
        cout << endl;
    }
    cout << endl;
    cout << "Second Pass:" << endl;
    stackqueue.print_elements();
    maze.print_state();
    cout << endl;

    // reinitialize the maze
    new (&maze) Maze("input_maze.txt");

    while(!maze.is_solved()){
        LHR_stage_two(maze, stackqueue);
        stackqueue.print_elements();
        maze.print_state();
        cout << endl;
    }
    return 0;
}
