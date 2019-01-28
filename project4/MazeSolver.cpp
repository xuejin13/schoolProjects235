// Xuejin Gao
// Tiziana Ligorio
// CSCI 235
// Project 4


#include <fstream>
#include <string>
#include <cstdio>
#include "MazeSolver.h"

using namespace std;

MazeSolver::MazeSolver(std::string input_file){
	ifstream input_stream;

	input_stream.open(input_file);
	if(input_stream.fail()){
		cerr << "Cannot read from " << input_file << endl;
		exit(1);
	}

	string character;	
	input_stream >> character;
	maze_rows_ = stoi(character);
	input_stream >> character;
	maze_columns_ = stoi(character);

	// cout << "rows:" << maze_rows_ << endl;
	// cout << "cols:" << maze_columns_ << endl;
	initializeMaze(maze_rows_, maze_columns_);
	fillMaze(input_stream);
	initializeSolution();

	maze_ready = true;

	input_stream.close();
}

MazeSolver::~MazeSolver(){
	if(maze_ready){
		delete maze_;
		maze_ = nullptr;
		delete solution_;
		solution_ = nullptr;
	}
}

bool MazeSolver::mazeIsReady(){
	return maze_ready;
}

bool MazeSolver::solveMaze(){
	Position current = backtrack_stack_.top();
	// cout << "hello" << endl;
	while(!backtrack_stack_.empty()){
		if(maze_[current.row][current.column] == '$'){
			cout << "Found the exit!!!" << endl;
			return true;
		}
		else if(extendPath(current)){
			solution_[current.row][current.column] = '>';
			current = backtrack_stack_.top();
		}
		else{
			maze_[current.row][current.column] = 'X';
			solution_[current.row][current.column] = '@';
			backtrack_stack_.pop();
			if(!backtrack_stack_.empty())
				current = backtrack_stack_.top();
			else{
				cout << "This maze has no solution." << endl;
				return false;
			}
		}
	}
	return false;
}

void MazeSolver::printSolution(){
	cout << "The solution to this maze is: " << endl;
	for(int i = 0; i < maze_rows_; i++){
		for(int j = 0; j < maze_columns_; j++){
			cout << solution_[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void MazeSolver::initializeMaze(int rows, int columns){
	maze_ = new char*[rows];
	for(int i = 0; i < rows; i++)
		maze_[i] = new char[columns];
}

void MazeSolver::fillMaze(std::ifstream& input_stream){
	for(int r = 0; r < maze_rows_; r++)
		for(int c = 0; c < maze_columns_; c++){
			char character;
			input_stream >> character;
			maze_[r][c] = character;
		}
}

void MazeSolver::initializeSolution(){
	Position pos;
	pos.row = 0;
	pos.column = 0;
	backtrack_stack_.push(pos);
	solution_ = new char*[maze_rows_];
	for(int i = 0; i < maze_rows_; i++)
		solution_[i] = new char[maze_columns_];
	copyMazetoSolution();
}

void MazeSolver::copyMazetoSolution(){
	for(int i = 0; i < maze_rows_; i++)
		for(int j = 0; j < maze_columns_; j++)
			solution_[i][j] = maze_[i][j];
}

bool MazeSolver::extendPath(Position current_position){
	bool extended = false;
	if(isExtensible(current_position, SOUTH)){
		backtrack_stack_.push(getNewPosition(current_position, SOUTH));
		extended = true;
	}
	if(isExtensible(current_position, EAST)){
		backtrack_stack_.push(getNewPosition(current_position, EAST));
		extended = true;
	}
	return extended;
}

Position MazeSolver::getNewPosition(Position old_position, direction dir){
	Position pos;
	pos.row = 0;
	pos.column = 0;
	if(dir == SOUTH){
		pos.row = old_position.row + 1;
		pos.column = old_position.column;
	}
	else if(dir == EAST){
		pos.row = old_position.row;
		pos.column = old_position.column + 1;
	}
	return pos;
}

bool MazeSolver::isExtensible(Position current_position, direction dir){
	//checking for outofbounds
	if((dir == SOUTH && current_position.row + 1 >= maze_rows_) 
		|| (dir == EAST && current_position.column + 1 >= maze_columns_))
		return false;

	if(dir == SOUTH && 
		(maze_[current_position.row + 1][current_position.column] == '_' ||
		maze_[current_position.row + 1][current_position.column] == '$')
		)
		return true;
	else if(dir == EAST && 
		(maze_[current_position.row][current_position.column + 1] == '_' ||
		maze_[current_position.row][current_position.column + 1] == '$')
		)
		return true;

	return false;
}

//comment
//comment
//comment
//comment
//comment
//comment
//comment




