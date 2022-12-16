#include <iostream>
#include <vector>

using namespace std;

/*
给定一个 m x n 的矩阵，如果一个元素为 0 ，则将其所在行和列的所有元素都设为 0 。请使用 原地 算法。
示例 1：
输入：matrix = [[1,1,1],[1,0,1],[1,1,1]]
输出：[[1,0,1],[0,0,0],[1,0,1]]
示例 2：
输入：matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
输出：[[0,0,0,0],[0,4,5,0],[0,3,1,0]]

//全局遍历?

*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix)
	{
		vector<pair<int, int>> zero;
		int m = matrix.size();
		int n = matrix.at(0).size();
		for(int i=0;i<m*n;i++)
		{
			//行
			int x = i/n;
			//列
			int y = i%n;
			if(matrix[x][y] == 0)
			{
				zero.push_back(make_pair(x, y));
			}
		}
		for(auto item:zero)
		{
			int x = item.first;
			int y = item.second;
			for(int i=0;i<n;i++)
			{
				matrix[x][i] = 0;
			}
			for(int i=0;i<m;i++)
			{
				matrix[i][y] = 0;
			}
		}
    }
};

int main(void)
{
	vector<vector<int>> a = {{1,1,1}, {1, 0, 1}, {1,1,1}};
	vector<vector<int>> b = {{0,1,2,0}, {3,4,5,2}, {1,3,1,5}};
	Solution s;
	s.setZeroes(a);
	for(auto x:a)
	{
		for(auto y:x)
		{
			cout << y << "  ";
		}
		cout << endl;
	}
	cout << endl;
	s.setZeroes(b);
	for(auto x:b)
	{
		for(auto y:x)
		{
			cout << y << "  ";
		}
		cout << endl;
	}
	return 1;
}
