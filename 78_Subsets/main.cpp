#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/*给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。
解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。
示例 1：
输入：nums = [1,2,3]
输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
示例 2：
输入：nums = [0]
输出：[[],[0]]
回溯?
每个数都有选中和不选中两种可能,按照顺序进行选中?
*/

class Solution {
public:
	vector<vector<int>> result;
	vector<int> target;
	void dfs(vector<int>& nums, int cur)
	{
		if(cur == nums.size())
		{
			result.push_back(target);
			return;
		}
		target.push_back(nums.at(cur));
		dfs(nums, cur+1);
		target.pop_back();
		dfs(nums, cur+1);
	}
    vector<vector<int>> subsets(vector<int>& nums)
	{
		result.clear();
		target.clear();
		dfs(nums, 0);
		return result;
    }
};

int main(void)
{
	Solution s;
	vector<int> a = {1,2,3};
	vector<int> b = {0};
	vector<vector<int>> back;
	back = s.subsets(a);
	cout << "start" << endl;
	for(auto item:back)
	{
		for(auto every:item)
		{
			cout << every << "  ";
		}
		cout << endl;
	}
	cout << "end" << endl;
	back.clear();
	back = s.subsets(b);
	cout << "start" << endl;
	for(auto item:back)
	{
		for(auto every:item)
		{
			cout << every << ", ";
		}
		cout << endl;
	}
	cout << "end" << endl;
	back.clear();
	return 1;
}

