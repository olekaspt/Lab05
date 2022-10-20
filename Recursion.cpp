#include "Recursion.h"
#include <stack>
#include <stdbool.h>
#include<iostream>
#include<sstream>
#include<string>

using namespace std;

// 3! = 3 * 2 * 1
// 4! = 4 * 3 * 2 * 1


int FactorialByRecursion::CalculateFactorial(int num) 
{

	int answer = 1;

	// TODO
	
	return answer;

}


int FactorialByStack::CalculateFactorial(int num) {

	int answer = 1;

	// TODO

	return answer;
}

bool ChessBoard::Solve(ChessBoard chessBoard, int col) {

	if (col >= 8) {
		cout << chessBoard.ToString() <<endl;
		return true;
	}


	for (int i = 0; i < 8; ++i) {

		if (CheckSafeQueens(chessBoard, i, col)) 
		{
			chessBoard.m_board[i][col] = 1;

			if (Solve(chessBoard, col + 1) == true)
			{
				return true;
			}

			chessBoard.m_board[i][col] = 0;

		}
	}
	return false;
}




bool ChessBoard::CheckSafeQueens(ChessBoard chessBoard, int row, int col) 
{
	// TODO this is fake implementation that just shows off some logic to 
	// get a board made.  First change this implementation to work, and the work on the 
	// stack portion

	bool retVal = false;
	static int count = 1;
	static int modCount = 3;
	int tmp = count % modCount;
	count++;
	
	if(tmp != 0)
	{
		retVal = true;
	}
	else
	{
		
		retVal = false;

	}
    return retVal;

}


string ChessBoard::ToString() {

	string answer = "";
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			int temp = m_board[i][j];
			stringstream ss;
			ss << temp;
			string str = ss.str();
			answer = answer + str;
		}
		answer = answer + "\n";
	}
	return answer;
}

extern std::string CallSimpleExceptionMethod(int i)
{    
    // TODO:
    // Note this is starter code that is not safe.  
    // As Simple exceptin method will throw an exception
    // which will not be handled, and we will also leak resources.
    // Make this method safer and handle all possible exceptions 
    // And also return a string of the exception recieved
    // The tests will tell you what to string to return.


	std::string retVal;
	MyFakeClass* resourceThatNeedsToBeCleanedup = nullptr;

	resourceThatNeedsToBeCleanedup = new MyFakeClass();
	SimpleExceptionMethod(i);

	delete resourceThatNeedsToBeCleanedup;

	return retVal;
}

// NOTE this function should not be editted.
extern void SimpleExceptionMethod(int i)
{
	int retVal = 0;

	if (i == 1)
	{
		throw MyException1();
	}
	else if (i == 2)
	{
		throw MyException2();

	}
	else if (i == 3)
	{
        // TODO uncomment line below, as you need to have all three exceptions working here
		//throw MyException3();
	}
	else
	{
		retVal = 20;
	}

	return;

}



char const* MyBaseException::what() const throw() {
	return "MyBaseException";
}
char const* MyException1::what() const throw() {
	return "MyException1";
}
char const* MyException2::what() const throw() {
	return "MyException2";
}
// TODO make a MyException3::what
