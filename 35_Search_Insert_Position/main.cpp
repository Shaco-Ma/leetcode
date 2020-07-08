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
给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
你可以假设数组中无重复元素。
示例 1:
输入: [1,3,5,6], 5
输出: 2
示例 2:
输入: [1,3,5,6], 2
输出: 1
示例 3:
输入: [1,3,5,6], 7
输出: 4
示例 4:
输入: [1,3,5,6], 0
输出: 0

可以直接轮训,可以二分查找最接近的?
//查找到l和r相差1,根据l和r之间是否有相同的进行判断是,或者不是
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
		int l = 0, r = nums.size() - 1;
		int ret = 0;
		while(l < r)
		{
			auto mid = (l+r)/2;
			//if(l == r-1) break;
			if(nums[mid] == target) return mid;
			if(nums[mid] < target)
			{
				l = mid + 1;
			}
			else
			{
				//尽量把l和r收缩为一个
				r = mid;
			}
		}
		if(r < 0) return 0;
		if(nums[l] < target)
			return r+1;
		else
			return r;
    }
};

int main(void)
{
	Solution f;
	int target = 5;
	//target = 2;
	target = 0;
	vector<int> nums = {1, 3, 5, 6};
	//vector<int> nums = {1, 3};
	cout << "target = " << target << endl;
	cout << "Vector: ";
	for(auto item : nums)
	{
		cout << "	" << item;
	}
	cout << endl;
	cout << f.searchInsert(nums, target) << endl;
	return EXIT_SUCCESS;
}

