#include <iostream>
#include <cstdlib>
#include "Maze.h"
// implement Left Hand Rule:

using namespace std;

template <class T>
void LeftHandRule(Maze& maze, StackQueue<T>& stackqueue){
    // acting as a stack
    if(maze.can_move_left()){
        maze.move_left();
        if(stackqueue.peek_rear() != 'B')
            stackqueue.push_rear('L');
        else{
            stackqueue.pop_rear();
            switch (stackqueue.pop_rear()){
                case 'F':
                    stackqueue.push_rear('R');
                    break;
                case 'R':
                    stackqueue.push_rear('B');
                    break;
                case 'L':
                    stackqueue.push_rear('F');
                    break;
            }
        }
    }
    else if(maze.can_move_forward()){
        maze.move_forward();
        if(stackqueue.peek_rear() != 'B')
            stackqueue.push_rear('F');
        else{
            stackqueue.pop_rear();
            switch (stackqueue.pop_rear()){
                case 'L':
                    stackqueue.push_rear('R');
                    break;
                case 'F':
                    stackqueue.push_rear('B');
                    break;
            }
        }
    }
    else if(maze.can_move_right()){
        maze.move_right();
        if(stackqueue.peek_front() != 'B')
            stackqueue.push_rear('R');
        else{
            stackqueue.pop_rear();
            switch (stackqueue.pop_rear()){
                case 'L':
                    stackqueue.push_rear('B');
                    break;
            }
        }
    }
    else{
        maze.move_back();
        stackqueue.push_rear('B');
    }
}

template <class T>
void LHR_stage_two(Maze& maze, StackQueue<T>& stackqueue){
    T temp;
    if(!stackqueue.is_empty()){
        temp = stackqueue.pop_front();
        if(temp == 'L')
            maze.move_left();
        else if(temp == 'F')
            maze.move_forward();
        else if(temp == 'R')
            maze.move_right();
        else
            cout << "ERROR" << endl;
    }
}
