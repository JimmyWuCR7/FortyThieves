/**
 *  \file Board.h
 *  \author Di Wu
 *  \brief A head file
 */

#ifndef A4_BOARD_H_
#define A4_BOARD_H_


#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

class Board{
	private:

		/// Value to store the Board State
		vector<vector<int> > BoardState;
	public:

		/**
    	*  \brief Construct Board
    	*  \param num The size of the board
    	*/
		Board(int num);

		/**
 		*  \brief Set the corresponding block to 1
 		*  \param a the row value
   		*  \param b the column value
 		*/
		void set(int a, int b);

		/**
 		*  \brief Work out the next stage of the input board.
 		*/
		void NextStage();

		/**
 		*  \brief Print out the visible board of the corresponding stage board.
 		*/
		void PrintBoard();

		/**
 		*  \brief Show the boardADT in the vector<vector<int>> way
 		*  \return The corresponding vector<vector<int> > value
 		*/
		vector<vector<int> > toVec();

		/**
 		*  \brief Show how many neighbour does a block has.
   		*  \param s the board stage in the vector<vector<int> > form
   		*  \param a the row value
   		*  \param b the column value
 		*  \return The number of neighbour
 		*/
		int CountNeigh(vector<vector<int> > s, int a, int b);
};


#endif