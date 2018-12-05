/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};


TEST(TICTACTOEBOARDTEST, turnChangingXtoO)
{
	TicTacToeBoard abc;
	ASSERT_EQ(abc.toggleTurn(), O);
}

TEST(TICTACTOEBOARDTEST, turnChangingOtoX)
{
	TicTacToeBoard abc;
	abc.toggleTurn();
	ASSERT_EQ(abc.toggleTurn(), X);
}

TEST(TICTACTOEBOARDTEST, getPieceOutOfBoundsHighX)
{
	TicTacToeBoard abc;
	ASSERT_EQ(abc.getPiece(3,4), Invalid);
}

TEST(TICTACTOEBOARDTEST, getPieceOutOfBoundsHighY)
{
	TicTacToeBoard abc;
	ASSERT_EQ(abc.getPiece(4,3), Invalid);
}

TEST(TICTACTOEBOARDTEST, getPieceOutOfBoundsLowX)
{
	TicTacToeBoard abc;
	ASSERT_EQ(abc.getPiece(1,-1), Invalid);
}

TEST(TICTACTOEBOARDTEST, getPieceOutOfBoundsLowY)
{
	TicTacToeBoard abc;
	ASSERT_EQ(abc.getPiece(-1,1), Invalid);
}

TEST(TICTACTOEBOARDTEST, getPieceBlank)
{
	TicTacToeBoard abc;
	ASSERT_EQ(abc.getPiece(1,1), Blank);
}

TEST(TICTACTOEBOARDTEST, placePieceX)
{
	TicTacToeBoard abc;
	abc.placePiece(1,1);
	ASSERT_EQ(abc.getPiece(1,1), X);
}

TEST(TICTACTOEBOARDTEST, placePieceO)
{
	TicTacToeBoard abc;
	abc.toggleTurn();
	abc.placePiece(2,2);
	ASSERT_EQ(abc.getPiece(2,2), O);
}

TEST(TICTACTOEBOARDTEST, getWinnerVertical)
{
	TicTacToeBoard abc;
	for (int i = 0; i < BOARDSIZE; i++)
	{
		abc.placePiece(i,1);
		abc.toggleTurn();
	}
	ASSERT_EQ(abc.getWinner(), X);
}

TEST(TICTACTOEBOARDTEST, getWinnerHorizontal)
{
	TicTacToeBoard abc;
	for (int i = 0; i < BOARDSIZE; i++)
	{
		abc.placePiece(1,i);
		abc.toggleTurn();
	}
	ASSERT_EQ(abc.getWinner(), X);
}

TEST(TICTACTOEBOARDTEST, getWinnerDiagonal)
{
	TicTacToeBoard abc;
	for (int i = 0; i < BOARDSIZE; i++)
	{
		abc.placePiece(i,i);
		abc.toggleTurn();
	}
	ASSERT_EQ(abc.getWinner(), X);
}

TEST(TICTACTOEBOARDTEST, getWinnerBlank)
{
	TicTacToeBoard abc;
	
	for(int i=0; i<BOARDSIZE - 1; i++)
    	for(int j=0; j<BOARDSIZE; j++)
    	{
      		abc.placePiece(i,j);
    	}
    abc.toggleTurn();
    for (int j = 0; j<BOARDSIZE; j++)
    	abc.placePiece(2,j);
	ASSERT_EQ(abc.getWinner(), Blank);
}

TEST(TICTACTOEBOARDTEST, getWinnerNoWinner)
{
	TicTacToeBoard bc;
	ASSERT_EQ(bc.getWinner(), Invalid);
}