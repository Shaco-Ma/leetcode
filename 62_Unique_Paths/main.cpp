#include <iostream>
#include <vector>

using namespace std;

/*
	一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。
	机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。
	问总共有多少条不同的路径？
	示例 1：
	输入：m = 3, n = 7
	输出：28
	示例 2：
	输入：m = 3, n = 2
	输出：3
	解释：
	从左上角开始，总共有 3 条路径可以到达右下角。
	1. 向右 -> 向下 -> 向下
	2. 向下 -> 向下 -> 向右
	3. 向下 -> 向右 -> 向下
	示例 3：
	输入：m = 7, n = 3
	输出：28
	示例 4：
	输入：m = 3, n = 3
	输出：6
	//思路
	妥妥的动态规划啊
	结果还是写成了回溯
	要想知道最后一布是多少,就需要知道前一步是多少,结束条件是m==0或者n==0
	//每一步都有两种方法,m移动或者n移动
	剪枝优化暂时还想不出来
*/

class Solution
{
public:
    int uniquePaths(int m, int n)
	{
		vector<vector<int>> f(m, vector<int>(n,0));
		for(int i=0;i<m;i++)
		{
			f[i][0] = 1;
		}
		for(int i=0;i<n;i++)
		{
			f[0][i] = 1;
		}
		for(int i=1;i<m;i++)
		{
			for(int j=1;j<n;j++)
			{
				f[i][j] = f[i-1][j] +f[i][j-1];
			}
		}
		return f[m-1][n-1];
    }
};

int main(void)
{
	Solution s;
	cout << s.uniquePaths(3, 2) << endl;
	cout << s.uniquePaths(3, 7) << endl;
	cout << s.uniquePaths(3, 3) << endl;
	cout << s.uniquePaths(51, 9) << endl;
	return 1;
}

