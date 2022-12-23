#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/*
已知存在一个按非降序排列的整数数组 nums ，数组中的值不必互不相同。
在传递给函数之前，nums 在预先未知的某个下标 k（0 <= k < nums.length）上进行了 旋转 ，使数组变为 [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]（下标 从 0 开始 计数）。例如， [0,1,2,4,4,4,5,6,6,7] 在下标 5 处经旋转后可能变为 [4,5,6,6,7,0,1,2,4,4] 。
给你 旋转后 的数组 nums 和一个整数 target ，请你编写一个函数来判断给定的目标值是否存在于数组中。如果 nums 中存在这个目标值 target ，则返回 true ，否则返回 false 。
你必须尽可能减少整个操作步骤。
示例 1：
输入：nums = [2,5,6,0,0,1,2], target = 0
输出：true
示例 2：
输入：nums = [2,5,6,0,0,1,2], target = 3
输出：false
*/

class Solution {
public:
    bool search(vector<int>& nums, int target)
	{
		if(target >= nums.at(0))
		{
			//从左边开始找
			for(int i=0;i<nums.size();i++)
			{
				if(target < nums.at(i))
					return false;
				else if(nums.at(i) == target)
					return true;
			}
		}
		else
		{
			//从后往前找
			for(int i=nums.size()-1;i>=0;i--)
			{
				if(target > nums.at(i))
					return false;
				else if(target == nums.at(i))
					return true;
			}
		}
		return false;
    }
};

int main(void)
{
	vector<int> a = {2,5,6,0,0,1,2};
	Solution s;
	cout << s.search(a, 0) << endl;
	cout << s.search(a, 3) << endl;
	return 1;
}

