/**
 *  \file Board.h
 *  \author Di Wu
 *  \brief A head file
 */

#ifndef A4_READWRITE_H_
#define A4_READWRITE_H_

#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <stdexcept>

#include "../include/Board.h"

using namespace std;

/**
*  \brief Read a txt file
*  \param x The name of the file.
*  \return A Board value with the corresponding board in the reading file.
*/
Board Read(string x);

/**
*  \brief Write the corresponding board state into a file
*  \param x The board that need to be writtened.
*  \param t The name of the output file.
*/
void Write(Board x, string t);

#endif