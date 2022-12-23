#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/*
给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。
单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
示例 1：
输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
输出：true
示例 2：
输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
输出：true
示例 3：
输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
输出：false
//先找到第一个字母所在的地方,然后上下左右查找
//维护一个相同的数组,保存那些被用过
//要注意边界
*/
class Solution {
public:
	int find_word(int i, int j, int m, int n, vector<vector<char>> &board, string &word, int s_cur, vector<vector<int>> &had_use)
	{
		int newi, newj;
		int ret = 0;
		//先看当前一样不一样
		if(board[i][j] != word[s_cur])
		{
			return 0;
		}
		else if(s_cur == word.size() - 1)
			return 1;
		had_use[i][j] = 1;
		//往左查找
		//cout << "i = " << i << ", j = " << j << ", s_cur = " << s_cur << endl;
		if(j>=1 && had_use[i][j-1] == 0)
		{
			ret = find_word(i, j-1, m, n, board, word, s_cur+1, had_use);
		}
		//右边查找
		if(ret == 0 && j+1<n && had_use[i][j+1] == 0)
		{
			ret = find_word(i, j+1, m, n, board, word, s_cur+1, had_use);
		}
		if(ret == 0 && i>=1 && had_use[i-1][j] == 0)
		{
			ret = find_word(i-1, j, m, n, board, word, s_cur+1, had_use);
		}
		if(ret == 0 && i+1<m && had_use[i+1][j] == 0)
		{
			ret = find_word(i+1, j, m, n, board, word, s_cur+1, had_use);
		}
		had_use[i][j] = 0;
		return ret;
	}
    bool exist(vector<vector<char>>& board, string word)
	{
		int ret = 0;
		int m = board.size();
		int n = board.at(0).size();
		vector<vector<int>> check(m, vector<int>(n, 0));
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(board[i][j] == word.at(0))
				{
					//clear_vector(check);
					//cout << "i = " << i << ", j = " << j << endl;
					ret = find_word(i, j, m, n, board, word, 0, check);
					if(ret)
					{
						return ret;
					}
				}
			}
		}
		return ret;
    }
};

int main(void)
{
	Solution s;
	vector<vector<char>> A = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
	vector<vector<char>> B = {{'C', 'A', 'A'}, {'A', 'A', 'A'}, {'B', 'C', 'D'}};
	vector<vector<char>> C = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'E', 'S'}, {'A', 'D', 'E', 'E'}};
	vector<vector<char>> D = {{'A'}};
	vector<vector<char>> E = {{'A', 'A', 'A', 'A', 'A', 'A'}, {'A', 'A', 'A', 'A', 'A', 'A'},
		{'A', 'A', 'A', 'A', 'A', 'A'}, {'A', 'A', 'A', 'A', 'A', 'A'}, {'A', 'A', 'A', 'A', 'A', 'A'}, {'A', 'A', 'A', 'A', 'A', 'A'}};
	string a("ABCCED");
	string b("SEE");
	string c("ABCB");
	string d("AAB");
	string e("ABCESEEEFS");
	string f("A");
	string g("AAAAAAAAAAAAAAB");
	//cout << s.exist(C, e) << endl;
	//cout << s.exist(A, a) << endl;
	//cout << s.exist(A, b) << endl;
	//cout << s.exist(A, c) << endl;
	//cout << s.exist(B, d) << endl;
	//cout << s.exist(D, f) << endl;
	cout << s.exist(E, g) << endl;
	return 1;
}

