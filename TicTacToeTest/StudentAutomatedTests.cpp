#include "pch.h"
#include "CppUnitTest.h"
#include <iostream>
#include "../TicTacToe_TestPracticum/TicTacToeBoard.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

/* Some helpful notes
 *  Player enum values are referenced by TicTacToeBoard::O or TicTacToeBoard::X or TicTacToeBoard::EMPTY
 * 
 *      Assert formats (2nd line is an example)
 * Assert::AreEqual(expected, actual, message) : Checks if two values are equal.
 *   Assert::AreEqual(5, my_function(2, 3), L"my_function should return 5 for inputs 2 and 3");
 * Assert::AreNotEqual(expected, actual, message) : Checks if two values are not equal.
 *   Assert::AreNotEqual(0, my_function(1, 0), L"my_function should not return 0 for inputs 1 and 0");
 * Assert::IsTrue(condition, message) : Checks if a condition is true.
 *   Assert::IsTrue(my_object.IsValid(), L"my_object should be valid after initialization");
 * Assert::IsFalse(condition, message) : Checks if a condition is false.
 *   Assert::IsFalse(my_object.IsEmpty(), L"my_object should not be empty after adding elements");
 */

namespace TicTacToeTest
{
	TEST_CLASS(TicTacToeStudentAutomatedTests)
	{
		TicTacToeBoard board;

	public:

		TEST_CLASS_INITIALIZE(_Setup_BoardClassTest)
		{
			// this method is run once for the TicTacToeTest class
			//    intentionally blank (other than the log message) - nothing to initialize at this time
			Logger::WriteMessage("Test class initialized\n");
		}

		TEST_METHOD_INITIALIZE(_Setup_MethodTest) {
			// this method is run prior to EVERY test case inside the class (ie this file)
			Logger::WriteMessage("Initializing Board object for additional tests.\n");
			board.resetBoard();          // reinitialize board via method, rather than creating a new board object
		}

		TEST_METHOD(HelloStudentTests) {
			Logger::WriteMessage("Running student tests on the Board object");
			Assert::IsTrue(true);
		}



		TEST_METHOD(NEXTPLAYER) {
			char prevname = board.getPlayerName();
			board.nextPlayer();

			switch (prevname) {
			case ('X'):
				Assert::AreEqual(board.getPlayerName(), 'O',L"Expected player to be switched to 'O'");
				Assert::AreNotEqual(board.getPlayerName(), 'X', L"Expected player to be switched to 'X'");
				break;
			case ('O'):
				Assert::AreEqual(board.getPlayerName(), 'X', L"Expected player to be switched to 'X'");
				Assert::AreNotEqual(board.getPlayerName(), 'O', L"Expected player to be switched to 'O'");
				break;
			}
		 }
		TEST_METHOD(WRITING_GETTING_SQUARES) {
			for (int i = 0; i< board.BOARD_NUM_ROWS ; i++) {
				for (int j = 0; j < board.BOARD_NUM_COLS; j++) {
					bool wroteToSquare = board.writeSquare(i, j, board.getPlayer());
					bool isEmpty = board.isSquareEmpty(i, j);
					char currentSquare = board.getSquareContents(i, j);
					Assert::AreEqual(currentSquare, board.getPlayerName(), L"Expected written value to be returned by getSquareContents");
					Assert::AreNotEqual(wroteToSquare, isEmpty, L"Expected square to not return as Empty after writing to it");
				}
			}
			
		}
	};
}
