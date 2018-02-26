/*
 * Board_test.cpp
 */
#include <gtest/gtest.h>

#include "Board.h"
using namespace std;

TEST(BoardTest, test) {
    string expected =
        "+---+---+---+\n"
        "|147|258|369|\n"
        "|258|369|147|\n"
        "|369|147|258|\n"
        "+---+---+---+\n"
        "|471|582|693|\n"
        "|582|693|471|\n"
        "|693|471|582|\n"
        "+---+---+---+\n"
        "|714|825|936|\n"
        "|825|936|714|\n"
        "|936|714|825|\n"
        "+---+---+---+";
    Board board;
    board.put(1, 1, 1); board.put(2, 1, 4); board.put(3, 1, 7);
    board.put(4, 1, 2); board.put(5, 1, 5); board.put(6, 1, 8);
    board.put(7, 1, 3); board.put(8, 1, 6); board.put(9, 1, 9);

    board.put(1, 2, 2); board.put(2, 2, 5); board.put(3, 2, 8);
    board.put(4, 2, 3); board.put(5, 2, 6); board.put(6, 2, 9);
    board.put(7, 2, 1); board.put(8, 2, 4); board.put(9, 2, 7);

    board.put(1, 3, 3); board.put(2, 3, 6); board.put(3, 3, 9);
    board.put(4, 3, 1); board.put(5, 3, 4); board.put(6, 3, 7);
    board.put(7, 3, 2); board.put(8, 3, 5); board.put(9, 3, 8);

    board.put(1, 4, 4); board.put(2, 4, 7); board.put(3, 4, 1);
    board.put(4, 4, 5); board.put(5, 4, 8); board.put(6, 4, 2);
    board.put(7, 4, 6); board.put(8, 4, 9); board.put(9, 4, 3);

    board.put(1, 5, 5); board.put(2, 5, 8); board.put(3, 5, 2);
    board.put(4, 5, 6); board.put(5, 5, 9); board.put(6, 5, 3);
    board.put(7, 5, 4); board.put(8, 5, 7); board.put(9, 5, 1);

    board.put(1, 6, 6); board.put(2, 6, 9); board.put(3, 6, 3);
    board.put(4, 6, 4); board.put(5, 6, 7); board.put(6, 6, 1);
    board.put(7, 6, 5); board.put(8, 6, 8); board.put(9, 6, 2);

    board.put(1, 7, 7); board.put(2, 7, 1); board.put(3, 7, 4);
    board.put(4, 7, 8); board.put(5, 7, 2); board.put(6, 7, 5);
    board.put(7, 7, 9); board.put(8, 7, 3); board.put(9, 7, 6);

    board.put(1, 8, 8); board.put(2, 8, 2); board.put(3, 8, 5);
    board.put(4, 8, 9); board.put(5, 8, 3); board.put(6, 8, 6);
    board.put(7, 8, 7); board.put(8, 8, 1); board.put(9, 8, 4);

    board.put(1, 9, 9); board.put(2, 9, 3); board.put(3, 9, 6);
    board.put(4, 9, 7); board.put(5, 9, 1); board.put(6, 9, 4);
    board.put(7, 9, 8); board.put(8, 9, 2); board.put(9, 9, 5);

    ASSERT_EQ(expected, board.toString());
    ASSERT_TRUE(board.isComplete());
}


TEST(BoardTest, testCreate) {
	string expected =
	        "+---+---+---+\n"
	        "|...|...|...|\n"
	        "|...|...|...|\n"
	        "|...|...|...|\n"
	        "+---+---+---+\n"
	        "|...|...|...|\n"
	        "|...|...|...|\n"
	        "|...|...|...|\n"
	        "+---+---+---+\n"
	        "|...|...|...|\n"
	        "|...|...|...|\n"
	        "|...|...|...|\n"
	        "+---+---+---+";
	Board board;
	ASSERT_EQ(expected, board.toString());
}

TEST(BoardTest, testCanPut) {
	Board board;
	ASSERT_TRUE(board.canPut(1, 1, 1));
}

TEST(BoardTest, testCanPutX) {
	Board board;
		ASSERT_TRUE(board.canPut(1, 1, 1));
		board.put(1, 1, 1);
		ASSERT_EQ(1, board.getNumber(1, 1));
		std::string expected =
	        "+---+---+---+\n"
	        "|1..|...|...|\n"
	        "|...|...|...|\n"
	        "|...|...|...|\n"
	        "+---+---+---+\n"
	        "|...|...|...|\n"
	        "|...|...|...|\n"
	        "|...|...|...|\n"
	        "+---+---+---+\n"
	        "|...|...|...|\n"
	        "|...|...|...|\n"
	        "|...|...|...|\n"
	        "+---+---+---+";
		ASSERT_EQ(expected, board.toString());

	    ASSERT_TRUE(board.canPut(2, 1, 2)) << "同じ列にダブっていない数字は置ける";

	    board.put(2, 1, 2);
	    ASSERT_EQ(2, board.getNumber(2, 1));

	    expected =
	        "+---+---+---+\n"
	        "|12.|...|...|\n"
	        "|...|...|...|\n"
	        "|...|...|...|\n"
	        "+---+---+---+\n"
	        "|...|...|...|\n"
	        "|...|...|...|\n"
	        "|...|...|...|\n"
	        "+---+---+---+\n"
	        "|...|...|...|\n"
	        "|...|...|...|\n"
	        "|...|...|...|\n"
	        "+---+---+---+";
	    ASSERT_EQ(expected, board.toString());

	    ASSERT_FALSE(board.canPut(4, 1, 2)) << "同じ行に同じ数は置けない";

	    board.clear(2, 1);
	    ASSERT_TRUE(board.canPut(4, 1, 2)) << "同じ数をクリアすれば置ける";
}

TEST(BoardTest, testCanPutY) {
    Board board;
    board.put(1, 1, 1);
    ASSERT_TRUE(board.canPut(1, 2, 2)) << "同じ列にダブっていない数字は置ける";

    board.put(1, 2, 2);
    ASSERT_EQ(2, board.getNumber(1, 2));

    string expected =
        "+---+---+---+\n"
        "|1..|...|...|\n"
        "|2..|...|...|\n"
        "|...|...|...|\n"
        "+---+---+---+\n"
        "|...|...|...|\n"
        "|...|...|...|\n"
        "|...|...|...|\n"
        "+---+---+---+\n"
        "|...|...|...|\n"
        "|...|...|...|\n"
        "|...|...|...|\n"
        "+---+---+---+";
    ASSERT_EQ(expected, board.toString());

    ASSERT_FALSE(board.canPut(1, 4, 2)) << "同じ列に同じ数は置けない";
}

TEST(BoardTest, testCanPutBlock) {
    Board board;
    board.put(4, 7, 1);
    ASSERT_TRUE(board.canPut(5, 8, 2));

    board.put(5, 8, 2);
    string expected =
        "+---+---+---+\n"
        "|...|...|...|\n"
        "|...|...|...|\n"
        "|...|...|...|\n"
        "+---+---+---+\n"
        "|...|...|...|\n"
        "|...|...|...|\n"
        "|...|...|...|\n"
        "+---+---+---+\n"
        "|...|1..|...|\n"
        "|...|.2.|...|\n"
        "|...|...|...|\n"
        "+---+---+---+";
    ASSERT_EQ(expected, board.toString());

    ASSERT_FALSE(board.canPut(6, 9, 2)) << "同じブロックに同じ数は置けない";

    ASSERT_TRUE(board.canPut(7, 9, 2)) << "違うブロックには同じ数は置ける";
}
TEST(BoardTest, testExceptionPositionCanPut) {
    Board board;
    ASSERT_NO_THROW(board.canPut(1, 1, 1));
    ASSERT_THROW(board.canPut(0, 1, 1), OutOfBoard);
    ASSERT_THROW(board.canPut(1, 0, 1), OutOfBoard);
    ASSERT_THROW(board.canPut(10, 1, 1), OutOfBoard);
    ASSERT_THROW(board.canPut(1, 10, 1), OutOfBoard);
}

TEST(BoardTest, testExceptionPositionCan) {
    Board board;
    ASSERT_NO_THROW(board.put(1, 1, 1));
    ASSERT_THROW(board.put(0, 1, 1), OutOfBoard);
    ASSERT_THROW(board.put(1, 0, 1), OutOfBoard);
    ASSERT_THROW(board.put(10, 1, 1), OutOfBoard);
    ASSERT_THROW(board.put(1, 10, 1), OutOfBoard);
}

TEST(BoardTest, testExceptionPositionClear) {
    Board board;
    ASSERT_NO_THROW(board.clear(1, 1));
    ASSERT_THROW(board.clear(0, 1), OutOfBoard);
	ASSERT_THROW(board.clear(1, 0), OutOfBoard);
	ASSERT_THROW(board.clear(10, 1), OutOfBoard);
	ASSERT_THROW(board.clear(1, 10), OutOfBoard);

}

TEST(BoardTest, testExceptionNumberCanPut) {
    Board board;
    ASSERT_NO_THROW(board.canPut(9, 9, 9));
    ASSERT_THROW(board.canPut(9, 9, 0), IllegalNumber);
    ASSERT_THROW(board.canPut(9, 9, 10), IllegalNumber);
}

TEST(BoardTest, testExceptionNumberPut) {
    Board board;
    ASSERT_NO_THROW(board.put(9, 9, 9));
    ASSERT_THROW(board.put(9, 9, 0), IllegalNumber);
    ASSERT_THROW(board.put(9, 9, 10), IllegalNumber);
}
TEST(BoardTest, testIsComplete) {
    string expected =
        "+---+---+---+\n"
        "|147|258|369|\n"
        "|258|369|147|\n"
        "|369|147|258|\n"
        "+---+---+---+\n"
        "|471|582|693|\n"
        "|582|693|471|\n"
        "|693|471|582|\n"
        "+---+---+---+\n"
        "|714|825|936|\n"
        "|825|936|714|\n"
        "|936|714|825|\n"
        "+---+---+---+";
    Board board;
    board.put(1, 1, 1); board.put(2, 1, 4); board.put(3, 1, 7);
    board.put(4, 1, 2); board.put(5, 1, 5); board.put(6, 1, 8);
    board.put(7, 1, 3); board.put(8, 1, 6); board.put(9, 1, 9);

    board.put(1, 2, 2); board.put(2, 2, 5); board.put(3, 2, 8);
    board.put(4, 2, 3); board.put(5, 2, 6); board.put(6, 2, 9);
    board.put(7, 2, 1); board.put(8, 2, 4); board.put(9, 2, 7);

    board.put(1, 3, 3); board.put(2, 3, 6); board.put(3, 3, 9);
    board.put(4, 3, 1); board.put(5, 3, 4); board.put(6, 3, 7);
    board.put(7, 3, 2); board.put(8, 3, 5); board.put(9, 3, 8);

    board.put(1, 4, 4); board.put(2, 4, 7); board.put(3, 4, 1);
    board.put(4, 4, 5); board.put(5, 4, 8); board.put(6, 4, 2);
    board.put(7, 4, 6); board.put(8, 4, 9); board.put(9, 4, 3);

    board.put(1, 5, 5); board.put(2, 5, 8); board.put(3, 5, 2);
    board.put(4, 5, 6); board.put(5, 5, 9); board.put(6, 5, 3);
    board.put(7, 5, 4); board.put(8, 5, 7); board.put(9, 5, 1);

    board.put(1, 6, 6); board.put(2, 6, 9); board.put(3, 6, 3);
    board.put(4, 6, 4); board.put(5, 6, 7); board.put(6, 6, 1);
    board.put(7, 6, 5); board.put(8, 6, 8); board.put(9, 6, 2);

    board.put(1, 7, 7); board.put(2, 7, 1); board.put(3, 7, 4);
    board.put(4, 7, 8); board.put(5, 7, 2); board.put(6, 7, 5);
    board.put(7, 7, 9); board.put(8, 7, 3); board.put(9, 7, 6);

    board.put(1, 8, 8); board.put(2, 8, 2); board.put(3, 8, 5);
    board.put(4, 8, 9); board.put(5, 8, 3); board.put(6, 8, 6);
    board.put(7, 8, 7); board.put(8, 8, 1); board.put(9, 8, 4);

    board.put(1, 9, 9); board.put(2, 9, 3); board.put(3, 9, 6);
    board.put(4, 9, 7); board.put(5, 9, 1); board.put(6, 9, 4);
    board.put(7, 9, 8); board.put(8, 9, 2); board.put(9, 9, 5);

    ASSERT_EQ(expected, board.toString());
    ASSERT_TRUE(board.isComplete());

    expected =
        "+---+---+---+\n"
        "|147|258|369|\n"
        "|258|369|147|\n"
        "|369|147|258|\n"
        "+---+---+---+\n"
        "|471|582|693|\n"
        "|582|693|471|\n"
        "|693|471|582|\n"
        "+---+---+---+\n"
        "|714|825|936|\n"
        "|825|936|714|\n"
        "|936|714|852|\n"
        "+---+---+---+";
    board.put(8, 9, 5);
    board.put(9, 9, 2);
    ASSERT_EQ(expected, board.toString());
    ASSERT_FALSE(board.isComplete()) << "縦がそろっていなければ完成しない";

    expected =
        "+---+---+---+\n"
        "|147|258|369|\n"
        "|258|369|147|\n"
        "|369|147|258|\n"
        "+---+---+---+\n"
        "|471|582|693|\n"
        "|582|693|471|\n"
        "|693|471|582|\n"
        "+---+---+---+\n"
        "|714|825|936|\n"
        "|825|936|715|\n"
        "|936|714|824|\n"
        "+---+---+---+";
    board.put(8, 9, 2);
    board.put(9, 8, 5);
    board.put(9, 9, 4);
    ASSERT_EQ(expected, board.toString());
    ASSERT_FALSE(board.isComplete()) << "横がそろっていなければ完成しない";

    expected =
        "+---+---+---+\n"
        "|147|258|369|\n"
        "|258|369|147|\n"
        "|369|147|258|\n"
        "+---+---+---+\n"
        "|471|582|693|\n"
        "|582|693|471|\n"
        "|693|471|582|\n"
        "+---+---+---+\n"
        "|714|825|936|\n"
        "|825|936|715|\n"
        "|936|714|82.|\n"
        "+---+---+---+";
    board.clear(9, 9);
    ASSERT_EQ(expected, board.toString());
    ASSERT_FALSE(board.isComplete()) << "一つでも未設定のところがあれば完成しない";
}

