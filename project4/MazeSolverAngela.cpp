#include "MazeSolver.h"
#include <iostream>
#include <fstream>

using namespace std;
MazeSolver::MazeSolver(string input_file){
  int row, col;
  ifstream fin(input_file);
  if(fin.fail()){
    cerr << "Cannot read from input_file_name" << endl;
    exit(1);
  }
  else {
    fin >> row >> col;
    initializeMaze(row, col);
    fillMaze(fin);
    initializeSolution();
    maze_ready = true;
    fin.close();
  }
}

MazeSolver::~MazeSolver() {
  if (maze_ready == true) {
    delete maze_;
    delete solution_;
  }
}

void MazeSolver::initializeMaze(int rows, int columns){
  maze_rows_ = rows;
  maze_columns_ = columns;
  maze_ = new char*[rows];
  for (int i = 0; i < rows; ++i) {
    maze_[i] = new char[columns];
  }
  //the first element of the array is the row and second element is the column
}
void MazeSolver::fillMaze(ifstream& input_stream){
  //fill the maze
  char c;
  int counter = 0;
  for (size_t i = 0; i < maze_rows_; i++) {
    for (size_t j = 0; j < maze_columns_; j++) {
      input_stream >> c;
      maze_[i][j] = c;
    }
  }
  for (size_t i = 0; i < maze_rows_; i++) {
    for (size_t j = 0; j < maze_columns_; j++) {
      cout << maze_[i][j];
    }
    cout << endl;
  }
}
void MazeSolver::initializeSolution(){
  solution_ = new char*[maze_rows_];
  for (int i = 0; i < maze_rows_; ++i) {
    solution_[i] = new char[maze_columns_];
  }
  copyMazetoSolution();
  maze_ready = true;
}
void MazeSolver::copyMazetoSolution(){
  for (size_t i = 0; i < maze_rows_; i++) {
    for (size_t j = 0; j < maze_columns_; j++) {
      solution_[i][j] = maze_[i][j];
    }
  }
}

bool MazeSolver::mazeIsReady() {
  return maze_ready;
};

bool MazeSolver::extendPath(Position current_position) {
  bool extended = false;
  if (isExtensible(current_position,SOUTH)){
    backtrack_stack_.push(getNewPosition(current_position,SOUTH));
    extended = true;
  }
  if (isExtensible(current_position,EAST)){
    backtrack_stack_.push(getNewPosition(current_position,EAST));
    extended = true;
  }
  return extended;
}

Position MazeSolver::getNewPosition(Position old_position, direction dir) {
  Position south = {old_position.row +1, old_position.column};
  Position east = {old_position.row, old_position.column+1};

  if(dir == SOUTH){
    return south;
  }
  else if(dir == EAST){
    return east;
  }
  return {-1, -1}; //no move

}

bool MazeSolver::isExtensible(Position current_position, direction dir) {
  int r = current_position.row;
  int c = current_position.column;
  if ((r+1 < maze_rows_) && (dir==SOUTH) && (maze_[r+1][c]=='_' || maze_[r+1][c]=='$')){
    return true;
  }
  else if ((c+1 < maze_columns_) && (dir==EAST) && (maze_[r][c+1]=='_' || maze_[r][c+1]=='$')){
    return true;
  }
  return false;
}

bool MazeSolver::solveMaze() {
  Position curr_position = {0,0};
  backtrack_stack_.push(curr_position);
  while(!backtrack_stack_.empty()){
    if(solution_[curr_position.row][curr_position.column]=='$'){
      cout << "Found exit!!!" << endl;
      return true;
    }
    else if(extendPath(curr_position)){
      solution_[curr_position.row][curr_position.column] = '>';
      curr_position = backtrack_stack_.top();
    }
    else{
      maze_[curr_position.row][curr_position.column] = 'X';
      solution_[curr_position.row][curr_position.column] = '@';
      backtrack_stack_.pop();
      if(!backtrack_stack_.empty()){
        curr_position = backtrack_stack_.top();
      }
      else{
        cout << "This maze has no solution." << endl;
        return false;
      }
    }
  }
  return false;
}

void MazeSolver::printSolution() {
  for (size_t i = 0; i < maze_rows_; i++) {
    for (size_t j = 0; j< maze_columns_; j++) {
      cout << solution_[i][j] << " ";
    }
    cout << endl;
  }
}
