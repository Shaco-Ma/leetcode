#include <iostream>
#include <vector>

using namespace std;

/*
	给定一个包含非负整数的 m x n 网格 grid ，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
	说明：每次只能向下或者向右移动一步。
	示例 1：
	输入：grid = [[1,3,1],[1,5,1],[4,2,1]]
	输出：7
	解释：因为路径 1→ 3→ 1→ 1→ 1 的总和最小。
	示例 2：
	输入：grid = [[1,2,3],[4,5,6]]
	输出：12
	思路
	倒叙查询,左边有上面,那个小用那个
	如果到达边界,直接遍历边界这一行(列)
	//错了,应该是计算所有的路径和,然后输出
*/

class Solution
{
public:
    int minPathSum(vector<vector<int>>& grid)
	{
		int m = grid.size();
		int n = 0;
		if(m > 0)
		{
			n = grid.at(0).size();
		}
		vector<vector<int>> dp(m, vector<int>(n, 0));
		dp[0][0] = grid[0][0];
		//先计算横竖列的值,最外圈
		for(int i=1;i<m;i++)
		{
			dp[i][0] = grid[i][0] + dp[i-1][0];
		}
		for(int i=1;i<n;i++)
		{
			dp[0][i] = grid[0][i] + dp[0][i-1];
		}
		//计算每个点的值
		for(int i=1;i<m;i++)
		{
			for(int j=1;j<n;j++)
			{
				dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
			}
		}

		return dp[m-1][n-1];
    }
};

int main(void)
{
	Solution s;
	vector<vector<int>> grid1({{1,3,1}, {1,5,1}, {4,2,1}});
	cout << s.minPathSum(grid1) << endl;;
	return 1;
}

