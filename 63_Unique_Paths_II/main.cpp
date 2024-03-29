#include <iostream>
#include <vector>

using namespace std;

/*
	一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。
	机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish”）。
	现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？
	网格中的障碍物和空位置分别用 1 和 0 来表示。
	示例 1：
	输入：obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
	输出：2
	解释：3x3 网格的正中间有一个障碍物。
	从左上角到右下角一共有 2 条不同的路径：
	1. 向右 -> 向右 -> 向下 -> 向下
	2. 向下 -> 向下 -> 向右 -> 向右
	示例 2：
	输入：obstacleGrid = [[0,1],[0,0]]
	输出：1
	//一样的方法,只是获取到m,n然后查询 obstacleGrid 是否为1
*/

class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
	{
		int m = obstacleGrid.size();
		int n = 0;
		if(m > 0)
			n = obstacleGrid.at(0).size();
		vector<vector<int>> f(m, vector<int>(n,0));
		for(int i=0;i<m;i++)
		{
			if(obstacleGrid[i][0] != 1)
				f[i][0] = 1;
			else
				break;
		}
		for(int i=0;i<n;i++)
		{
			if(obstacleGrid[0][i] != 1)
				f[0][i] = 1;
			else
				break;
		}
		for(int i=1;i<m;i++)
		{
			for(int j=1;j<n;j++)
			{
				if(obstacleGrid[i][j] == 1)
				{
					f[i][j] = 0;
				}
				else
				{
					f[i][j] = f[i-1][j] +f[i][j-1];
				}
			}
		}
		return f[m-1][n-1];
    }
};

int main(void)
{
	Solution s;
	vector<vector<int>> obstacleGrid = {{0,0,0},{0,1,0},{0,0,0}};
	cout << s.uniquePathsWithObstacles(obstacleGrid) << endl;
	obstacleGrid.clear();
	obstacleGrid = {{0,1},{0,0}};
	cout << s.uniquePathsWithObstacles(obstacleGrid) << endl;
	obstacleGrid.clear();
	obstacleGrid = {{1,0}};
	cout << s.uniquePathsWithObstacles(obstacleGrid) << endl;
	return 1;
}

