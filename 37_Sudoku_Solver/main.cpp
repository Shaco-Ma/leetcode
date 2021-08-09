#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <limits.h>
#include <map>
#include <set>
#include <unordered_set>
#include <utility>
#include <vector>
#include <list>
#include <stack>
#include <random>
#include <queue>

using namespace std;
/*
判断一个 9x9 的数独是否有效。只需要根据以下规则，验证已经填入的数字是否有效即可。

数字 1-9 在每一行只能出现一次。
数字 1-9 在每一列只能出现一次。
数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。
上图是一个部分填充的有效的数独。
数独部分空格内已填入了数字，空白格用 '.' 表示。
示例 1:
输入:
[
  ['5','3','.','.','7','.','.','.','.'],
  ['6','.','.','1','9','5','.','.','.'],
  ['.','9','8','.','.','.','.','6','.'],
  ['8','.','.','.','6','.','.','.','3'],
  ['4','.','.','8','.','3','.','.','1'],
  ['7','.','.','.','2','.','.','.','6'],
  ['.','6','.','.','.','.','2','8','.'],
  ['.','.','.','4','1','9','.','.','5'],
  ['.','.','.','.','8','.','.','7','9']
]
输出: true
示例 2:
输入:
[
  ['8','3','.','.','7','.','.','.','.'],
  ['6','.','.','1','9','5','.','.','.'],
  ['.','9','8','.','.','.','.','6','.'],
  ['8','.','.','.','6','.','.','.','3'],
  ['4','.','.','8','.','3','.','.','1'],
  ['7','.','.','.','2','.','.','.','6'],
  ['.','6','.','.','.','.','2','8','.'],
  ['.','.','.','4','1','9','.','.','5'],
  ['.','.','.','.','8','.','.','7','9']
]
Note:
给定的数独序列只包含数字 1-9 和字符 '.' 。
你可以假设给定的数独只有唯一解。
给定数独永远是 9x9 形式的。
*/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
		bool ret = true;
		int row, column, box;
		map<char, int> *row_all = new map<char, int>[9];
		map<char, int> *column_all = new map<char, int>[9];
		map<char, int> *box_all = new map<char, int>[9];
		for(row=0;row<9;++row)
		{
			for(column=0;column<9;++column)
			{
				if(isdigit(board[row][column]))
				{
					++row_all[row][board[row][column]];
					++column_all[column][board[row][column]];
					box = (row/3)*3 + column/3;
					++box_all[box][board[row][column]];
					if(row_all[row][board[row][column]] > 1 || column_all[column][board[row][column]] > 1 || box_all[box][board[row][column]] > 1)
					{
						ret = false;
						break;
					}
				}
			}
		}
		cout << "ROW: " << endl;
		for(auto i=0;i<9;++i)
		{
			for(auto item : row_all[i])
			{
				cout << hex << " item.first = " << hex << item.first << " item.second = " << hex << item.second << endl;
			}
			cout << endl;
		}
		cout << "Column: " << endl;
		for(auto i=0;i<9;++i)
		{
			for(auto item : column_all[i])
			{
				cout << hex << " item.first = " << hex << item.first << " item.second = " << hex << item.second << endl;
			}
			cout << endl;
		}
		cout << "Box: " << endl;
		for(auto i=0;i<9;++i)
		{
			for(auto item : box_all[i])
			{
				cout << hex << " item.first = " << hex << item.first << " item.second = " << hex << item.second << endl;
			}
			cout << endl;
		}
		delete [] row_all;
		delete [] column_all;
		delete [] box_all;
		return ret;
    }
};

int main(void)
{
	Solution f;
	//vector<vector<char> > in = {{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},
	vector<vector<char> > in = {{'8','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},
							    {'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},
								{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
	cout << "Result: " << f.isValidSudoku(in) << endl;;
	return EXIT_SUCCESS;
}

