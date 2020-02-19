#include <fstream>
#include <string>
#include <iomanip>
#include <iostream>
#include <vector>
#include <stdexcept>

#include "../include/Board.h"
#include "../include/ReadWrite.h"

using namespace std;

int main(){
	Board final = Read("txt/ex.txt");
	final.PrintBoard();

	final.NextStage();
	cout << "\n";
	final.PrintBoard();
	
	Write(final, "txt/ex2.txt");
  	return 0;
}