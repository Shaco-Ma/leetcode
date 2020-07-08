#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <limits.h>
#include <map>
#include <set>
#include <unordered_set>
#include <utility>
#include <vector>
#include <list>
#include <stack>
#include <random>
#include <queue>

using namespace std;
/*
给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
你的算法时间复杂度必须是 O(log n) 级别。
如果数组中不存在目标值，返回 [-1, -1]。
示例 1:
输入: nums = [5,7,7,8,8,10], target = 8
输出: [3,4]
示例 2:
输入: nums = [5,7,7,8,8,10], target = 6
输出: [-1,-1]
//感觉像是标准的二分查找,然后再左右查找相邻的
//答案的办法是这样的,先找到最左边的,再找最右边界
*/

class Solution {
public:
	//找到边界,如果left = 1,那么找小于等于target的,就是mid一直往左移,找到target,开始l往右移动,直到l = r
	//如果left= 0,那么就找第一个大于target的,直到l = r
	int get_index(vector<int>& nums, int target, bool left)
	{
		int l = 0, len = nums.size(), r = len;
		while(l < r)
		{
			auto mid = (l+r)/2;
			cout << "mid = " << mid << " l = " << l << " r " << r << endl;
			if(nums[mid] < target)
			{
				l = mid + 1;
			}
			else if(nums[mid] > target)
			{
				r = mid;
			}
			else
			{
				if(left)
					r = mid;
				else
				{
					//如果相等,而且l和r不相等,那么mid至少是等于r的,那么这个时候,要往右找到第一个不等于这个值的
					l = mid + 1;
				}
			}
		}

		return l;
	}
    vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> ret;
		int num = get_index(nums, target, true);
		if(num >= nums.size() || nums[num] != target)
		{
			ret.push_back(-1);
			ret.push_back(-1);
			return ret;
		}
		cout << "num = " << num << endl;
		ret.push_back(num);
		num = get_index(nums, target, false);
		cout << "num = " << num << endl;
		ret.push_back(num - 1);

		return ret;
    }
};

int main(void)
{
	Solution f;
	//int target = 8;
	//vector<int> nums = {5,7,7,8,8,10};
	int target = 1;
	vector<int> nums = {1};
	vector<int> ret = f.searchRange(nums, target);
	for(auto item:ret)
	{
		cout << item << endl;
	}
	return EXIT_SUCCESS;
}

