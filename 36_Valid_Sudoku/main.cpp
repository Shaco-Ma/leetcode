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
输出: false
解释: 除了第一行的第一个数字从 5 改为 8 以外，空格内其他数字均与 示例1 相同。
     但由于位于左上角的 3x3 宫内有两个 8 存在, 因此这个数独是无效的。
说明:
一个有效的数独（部分已被填充）不一定是可解的。
只需要根据以上规则，验证已经填入的数字是否有效即可。
给定数独序列只包含数字 1-9 和字符 '.' 。
给定数独永远是 9x9 形式的。

//只需要判断一下,当前填入的数字是否有效就行了
//先判断行,是否有重复的;
//在判断列,是否有重复的;
//在每次都3X3的判断,是否有重复的-->粗实线,即左上角开始行3列3,然后是从行的第3个字节开始到第5个字节结束
//isdigit()
//一次遍历,存放在map里面,之前只想到了所有的存map,没想到分开存到不同的map里面,关键点在于怎么计算3X3的区域码
//如果row==0的时候,就放在行map里面,=1的时候,放在1里面,看每个是否超了
//列同样这样保存
//如果row < 3,那么就是第一行,3X3的表达为row/3 + column /3
//如果row > 3 < 6,证明跨越了3个空间,所以3X3表达式为row/3*3 + column/3
//以此类推,根据行数来判断是第几行的,根据列数来表示是这一行的第几个
//典型的那空间换时间
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

