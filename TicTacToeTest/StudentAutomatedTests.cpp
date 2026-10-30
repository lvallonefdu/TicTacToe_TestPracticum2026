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

		TEST_METHOD(TestWinCase) {
			board.writeSquare(0, 0, TicTacToeBoard::X);
			board.writeSquare(0, 1, TicTacToeBoard::X);
			board.writeSquare(0, 2, TicTacToeBoard::X);

			Assert::IsTrue(board.isWinner(TicTacToeBoard::X));
		}

		TEST_METHOD(TestDrawCase) {
			board.writeSquare(0, 0, TicTacToeBoard::O);
			board.writeSquare(0, 1, TicTacToeBoard::X);
			board.writeSquare(0, 2, TicTacToeBoard::O);
			board.writeSquare(1, 0, TicTacToeBoard::X);
			board.writeSquare(1, 1, TicTacToeBoard::O);
			board.writeSquare(1, 2, TicTacToeBoard::X);
			board.writeSquare(2, 0, TicTacToeBoard::X);
			board.writeSquare(2, 1, TicTacToeBoard::O);
			board.writeSquare(2, 2, TicTacToeBoard::X);
			Assert::IsTrue(board.isDraw(),L"Expected a draw but the board is not recognized as a draw");
		}

		TEST_METHOD(TestLooseCase) {
			board.writeSquare(0, 0, TicTacToeBoard::X);
			board.writeSquare(0, 1, TicTacToeBoard::X);
			board.writeSquare(0, 2, TicTacToeBoard::X);

			Assert::IsFalse(board.isWinner(TicTacToeBoard::O));
		}
		
	};
}
