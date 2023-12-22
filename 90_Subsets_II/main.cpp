#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

/*
   给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的子集（幂集）。
   解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。

   示例 1：
   输入：nums = [1,2,2]
   输出：[[],[1],[1,2],[1,2,2],[2],[2,2]]

   示例 2：
   输入：nums = [0]
   输出：[[],[0]]

   提示：
   1 <= nums.length <= 10
   -10 <= nums[i] <= 10
   //从1个元素开始,插入一个,等于1查找是否有,没有插入,再取消这个数
*/

class Solution {
	public:
		void getSubSet(vector<int> &target, vector<int> nums, int len, int index, vector<vector<int>> &result)
		{
			int size = target.size();
			if(size >= len)
			{
				for(auto item:target)
				{
					cout << item << "  ";
				}
				cout << endl;
				if(find(result.begin(), result.end(), target) == result.end())
				{
					result.push_back(target);
				}
				return;
			}
			for(int i=index;i<nums.size();i++)
			{
				target.push_back(nums[i]);
				getSubSet(target, nums, len, i+1, result);
				target.pop_back();
			}
		}
		vector<vector<int>> subsetsWithDup(vector<int>& nums)
		{
			vector<vector<int>> result;
			vector<int> target;
			target.clear();
			result.push_back(target);
			int size = nums.size();
			sort(nums.begin(), nums.end());
			for(int i=1;i<=size;i++)
			{
				target.clear();
				getSubSet(target, nums, i, 0, result);
			}
			return result;
		}
};

int main(void)
{
	Solution s;
	//vector<int> a = {1, 2, 2};
	//vector<int> a = {4, 1, 0};
	vector<int> a = {4, 4, 4, 1, 4};
	vector<vector<int>> ret;
	ret = s.subsetsWithDup(a);
	for(auto item:ret)
	{
		for(auto every:item)
		{
			cout << every << "  ";
		}
		cout << endl;
	}
	return 1;
}


