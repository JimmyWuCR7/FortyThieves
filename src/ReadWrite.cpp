#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <stdexcept>

#include "../include/Board.h"

using namespace std;

Board Read(string x){
	string line;
	vector<string> list;
	int count = 0;
	ifstream myfile (x);
	if (myfile.is_open()){
		while (getline(myfile,line)){
			count++;
			list.push_back(line);
    	}
    	myfile.close();
  	}
  	Board bb(count);
  	for(int i = 0; i < list.size(); i++){
  		for(int j = 0; j < list.size(); j++){
  			char comp = list[i].at(j);
  			if(comp == '#'){
  				bb.set(i,j);
  			}
  		}
  	}
  	return bb;
}


void Write(Board x, string t){
  vector<vector<int> > fina = x.toVec();
  ofstream myfile (t);
  if (myfile.is_open()){
    for(int i = 0; i < fina.size(); i++){
      for(int j = 0; j < fina.size(); j++){
        if(fina[i][j] == 0){
          myfile << ":";
        }
        else if(fina[i][j] == 1){
          myfile << "#";
        }
      }
      myfile << "\n";
    }
    myfile.close();
  }
  else{
    cout << "cannot open file";
  }
}