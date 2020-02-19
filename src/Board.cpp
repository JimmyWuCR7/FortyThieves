#include "../include/Board.h"

#include <stdexcept>
#include <iostream>
#include <vector>

using namespace std;

Board::Board(int num){
	vector<vector<int> > s;
	for(int i = 0; i < num; i++){
      vector<int> temp;
      for(int j = 0; j < num; j++){
         temp.push_back(0);
      }
      s.push_back(temp);
   }
   this->BoardState = s;
}

void Board::set(int a, int b){
	this->BoardState[a][b] = 1;
}

void Board::PrintBoard(){
	for(int i = 0; i < this->BoardState.size(); i++){
		for(int j = 0; j < this->BoardState[i].size(); j++){
			if(this->BoardState[i][j] == 0){
				cout << ": ";
			}
			else if(this->BoardState[i][j] == 1){
				cout << "# ";
			}
		}
		cout << endl;
	}
}

void Board::NextStage(){
	vector<vector<int> > finall, first;
	finall = this->BoardState;
	first = this->BoardState;
	for(int i = 0; i < first.size(); i++){
		for(int j = 0; j < first[i].size(); j++){
			if(first[i][j] == 0){
				if(CountNeigh(first,i,j) == 3){
					finall[i][j] = 1;
				}
			}
			else if(first[i][j] == 1){
				if(!(CountNeigh(first,i,j) == 2 || CountNeigh(first,i,j) == 3)){
					finall[i][j] = 0;
				}
			}
		}
	}
	this->BoardState = finall;
}

int Board::CountNeigh(vector<vector<int> > s, int a, int b){
	int count = 0;
	for(int i = a - 1; i <= a + 1;  i++){
		for(int j = b - 1; j <= b + 1; j++){
			if((s.size() > i && i >= 0) && (0 <= j && j < s.size())){
				if(!(i == a && j == b)){
					if(s[i][j] == 1){
						count++;
					}
				}
			}
		}
	}
	return count;
}

vector<vector<int> > Board::toVec(){
	return this->BoardState;
}