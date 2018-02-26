/*
 * Board.h
 */

#ifndef BOARD_H_
#define BOARD_H_

#include <string>
using namespace std;

class OutOfBoard: public exception {
};

class IllegalNumber: public exception {
};

class Board {
private:
	static const int ZERO = 0;
	static const int MINSIZE = 1;
	static const int MAXSIZE = 9;
	static const int BLOCKSIZE = 3;
	static const int CORRECT = 1022;
	int cell[MAXSIZE + 1][MAXSIZE + 1]{{0}};

	/*
	 * コンストラクタ
	 */
public:
	Board() {}

	/*
	 * 指定したマスに数字が置けるかを判定する
	 */
public:
	bool canPut(const int x, const int y, const int num) const {
		if (x < MINSIZE) {
			throw OutOfBoard();
		}

		if (y < MINSIZE) {
			throw OutOfBoard();
		}
		checkNumber(num);

		bool result = true;
		if (!canPutX(y, num)) {
			result = false;
		}
		if (!canPutY(x, num)) {
			result = false;
		}
		if (!canPutBlock(x, y, num)) {
			result = false;
		}
		return result;
	}

	/*
	 * 横方向で数字が置けるかを判定する
	 */
private:
	bool canPutX(const int y, const int num) const {
		for (int x = MINSIZE; x <= MAXSIZE; x++) {
			if (cell[x][y] == num) {
				return false;
			}
		}
		return true;
	}

	/*
	 * 縦方向で数字が置けるかを判定する
	 */
private:
	bool canPutY(const int x, const int num) const {
		for (int y = MINSIZE; y <= MAXSIZE; y++) {
			if (cell[x][y] == num) {
				return false;
			}
		}
		return true;
	}

	/*
	 * ブロック単位で数字が置けるかを判定する
	 */
private:
	bool canPutBlock(const int x, const int y, const int num) const {
		// 指定されたマスが含まれるブロックの左端の座標を求める
		int left;// = x / BLOCKSIZE * BLOCKSIZE + 1;
		switch (x) {
		case 1:
		case 2:
		case 3:
			left = 1;
			break;
		case 4:
		case 5:
		case 6:
			left = 4;
			break;
		case 7:
		case 8:
		case 9:
			left = 7;
			break;
		}

		// 指定されたマスが含まれるブロックの上端の座標を求める
		int top;
		switch (y) {
		case 1:
		case 2:
		case 3:
			top = 1;
			break;
		case 4:
		case 5:
		case 6:
			top = 4;
			break;
		case 7:
		case 8:
		case 9:
			top = 7;
			break;
		}

		bool result = true;
		for (int y = top; y < top + BLOCKSIZE; y++) {
			for (int x = left; x < left + BLOCKSIZE; x++) {
				if (cell[x][y] == num) {
					result = false;
				}
			}
		}
		return result;
	}

	/*
	 * 指定したマスに数字を置く
	 */
public:
	void put(const int x, const int y, const int num) {
		if (x < MINSIZE) {
			throw OutOfBoard();
		}

		if (y < MINSIZE) {
			throw OutOfBoard();
		}

		checkNumber(num);

		cell[x][y] = num;
	}

	/*
	 * 指定したマスから数字を消す
	 */
public:
	void clear(const int x, const int y) {
		if (x < MINSIZE) {
			throw OutOfBoard();
		}

		if (y < MINSIZE) {
			throw OutOfBoard();
		}

		cell[x][y] = ZERO;
	}

	/*
	 * 指定したマスの数字を調べる
	 */
public:
	int getNumber(const int x, const int y) const {
		if (x < MINSIZE) {
			throw OutOfBoard();
		}

		if (y < MINSIZE) {
			throw OutOfBoard();
		}

		return cell[x][y];
	}

	/*
	 * 数字が妥当な範囲かをチェックする
	 * 妥当でない場合は、例外が投げられる
	 */
private:
	void checkNumber(int num) const {
		if ((num < 1) || (num > 9)) {
			throw IllegalNumber();
		}
	}

	/*
	 * パズルが完成したかを確認する
	 */
public:
	bool isComplete() const {
		auto result = true;
		if (!isCompleteX()) {
			result = false;
		}
		if (!isCompleteY()) {
			result = false;
		}
		if (!isCompleteBlocks()) {
			result = false;
		}
		return result;
	}

	/*
	 * 横方向に数字がもれなく配置されているかを確認する
	 */
private:
	bool isCompleteX() const {
		auto result = true;
		for (int y = MINSIZE; y <= MAXSIZE && result; y++) {
			int answer = 0;
			for (int x = MINSIZE; x <= MAXSIZE; x++) {
				answer += (1 << cell[x][y]);
			}
			if (answer != 1022) {
				result = false;
			}
		}
		return result;
	}

	/*
	 * 縦方向に数字がもれなく配置されているかを確認する
	 */
private:
	bool isCompleteY() const {
		auto result = true;
		for (int x = MINSIZE; x <= MAXSIZE && result; x++) {
			int answer = 0;
			for (int y = MINSIZE; y <= MAXSIZE; y++) {
				answer += (1 << cell[x][y]);
			}
		}
		return result;
	}

	/*
	 * 横方向に数字がもれなく配置されているかを確認する
	 */
private:
	bool isCompleteBlocks() const {
		auto result = true;
		for (int y = MINSIZE; y <= MAXSIZE && result; y += BLOCKSIZE) {
			for (int x = MINSIZE; x <= MAXSIZE && result; x += BLOCKSIZE) {
				auto answer = 0;
				for (int yy = y; yy < y + BLOCKSIZE; yy++) {
					for (int xx = x; xx < x + BLOCKSIZE; xx++) {
						answer += (1 << cell[xx][yy]);
					}
				}
				if (answer != 1022) {
					result = false;
				}
			}
		}
		return result;
	}

	/*
	 * 盤上の状態を文字列として表現する
	 */
public:
	string toString() const {
		string ss;
		for (int y = MINSIZE; y <= MAXSIZE; y++) {
			if ((y % 3) == 1) {
				ss += "+---+---+---+\n";
			}
			for (int x = MINSIZE; x <= MAXSIZE; x++) {
				if ((x % 3) == 1) {
					ss += "|";
				}
				ss += toChar(x, y);
			}
			ss += "|\n";
		}
		ss += "+---+---+---+";
		return ss.data();
	}

	/*
	 * マスの状態を文字として表現する
	 */
private:
	char toChar(const int x, const int y) const {
		switch (cell[x][y]) {
		case 0:
			return '.';
			break;
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
			return char(cell[x][y] + '0');
			break;
		default:
			return 'x';
			break;
		}
	}
};

#endif /* BOARD_H_ */
