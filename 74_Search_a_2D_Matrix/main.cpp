#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/*
编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：
每行中的整数从左到右按升序排列。
每行的第一个整数大于前一行的最后一个整数。
输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
输出：true
输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
输出：false

//类似于变种二分查找?
先找到第几行是大于这个数的,那么前一行就是需要找的,再执行二分查找:先找到中间数,看是大于target,那么从(l+r)/2到r查找
//如果是小于,从l到(+r)/2找
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
	{
		int m = matrix.size();
		int n = matrix.at(0).size()-1;
		for(int i=0;i<m;i++)
		{
			if(matrix[i][n] >= target)
			{
                for(int j=0;j<=n;j++)
                {
                    if(matrix[i][j] == target)
                    {
                        return true;
                    }
                }
			}
		}

		return false;
    }
};

int main(void)
{
	vector<vector<int>> a = {{1,3,5,7}, {10,11,16,20}, {23,30,34,60}};
	vector<vector<int>> b = {{1}};
	Solution s;
	cout << s.searchMatrix(a, 3) << endl;
	cout << s.searchMatrix(a, 13) << endl;
	cout << s.searchMatrix(b, 1) << endl;
	return 1;
}

