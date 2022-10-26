#include <iostream>
#include <vector>

using namespace std;
/*
	给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。
	你可以按 任何顺序 返回答案。
	示例 1：
	输入：n = 4, k = 2
	输出：
	[
		[2,4],
		[3,4],
		[2,3],
		[1,2],
		[1,3],
		[1,4],
	]
	示例 2：
	输入：n = 1, k = 1
	输出：[[1]]
	//回溯算法
	尝试某个数,用完之后再去掉某个数,下一个循环从当前数的下一个开始,大小等于k的时候,return?
*/

class Solution {
public:
	vector<vector<int>> result;
	void dfs(int n, int first, int k, vector<int> &temp)
	{
#if 1
		if(temp.size() - (n-first+1) < k)
		{
			return;
		}
		if(temp.size() == k)
		{
			result.push_back(temp);
			return;
		}
		if(first == n + 1)
		{
			return;
		}
		temp.push_back(first);
		dfs(n, first+1, k, temp);
		temp.pop_back();
		dfs(n, first+1, k, temp);
#else
		if(temp.size() == k)
		{
			result.push_back(temp);
			return;
		}
		for(auto i=first;i<=n;i++)
		{
			temp.push_back(i);
			dfs(n, i+1, k, temp);
			temp.pop_back();
		}
#endif
	}
    vector<vector<int>> combine(int n, int k)
	{
		vector<int> temp;
		result.clear();
		temp.clear();
		dfs(n, 1, k, temp);
		return result;
    }
};

int main(void)
{
	Solution s;
	//vector<vector<int>> back = s.combine(4, 2);
	//vector<vector<int>> back = s.combine(1, 1);
	vector<vector<int>> back = s.combine(500, 50);
	for(auto item:back)
	{
		for(auto e:item)
		{
			cout << e << "  ";
		}
		cout << endl;
	}
	return 0;
}

