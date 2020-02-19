#include "../include/Board.h"
#include "../catch/catch.h"

#include <stdexcept>
#include <iostream>
#include <vector>

using namespace std;

TEST_CASE( "General tests for Board" , "[Board]" ){
	Board x(5);
	x.set(1,1);

	SECTION("Test for set"){
		vector<vector<int> > a = x.toVec();
		REQUIRE(a[1][1] == 1);
	}

	SECTION("Test for CountNeigh 1"){
		vector<vector<int> > a = x.toVec();
		int count = x.CountNeigh(a,1,1);
		REQUIRE(count == 0);
	}


	SECTION("Test for CountNeigh 2"){
		x.set(1,0);
		x.set(1,2);
		vector<vector<int> > a = x.toVec();
		int count = x.CountNeigh(a,1,1);
		REQUIRE(count == 2);
	}

	SECTION("Test for NextStage"){
		x.set(1,0);
		x.set(1,2);
		x.NextStage();
		vector<vector<int> > a = x.toVec();
		bool t = (a[0][1] == 1) && (a[1][1] == 1) && (a[2][1] == 1);
		REQUIRE(t);
	}

}