#include <iostream>
#include <vector>
#include <algorithm>

/*
给你一个未排序的整数数组 nums ，请你找出其中没有出现的最小的正整数。
请你实现时间复杂度为 O(n) 并且只使用常数级别额外空间的解决方案。

示例 1：
输入：nums = [1,2,0]
输出：3

示例 2：
输入：nums = [3,4,-1,1]
输出：2

示例 3：
输入：nums = [7,8,9,11,12]
输出：1

提示：
1 <= nums.length <= 5 * 105
-231 <= nums[i] <= 231 - 1
思路：
	只有置换能看懂,把下标作为正确的位置,进行置换
	只有属于这个数组大小的才进行置换,小于1和负数,大于数组的值不置换
	比如下标为i的数值x,那么x应该在下标为x-1的位置,如果x==下标为x-1的值,就跳过
	置换结束,只需要看哪一个下标的数不等于i+1,就返回i+1
*/

using namespace std;

class Solution {
	public:
		int firstMissingPositive(vector<int>& nums) {
			int n = nums.size();
			for(int i=0;i<n;i++)
			{
				while(nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1])
				{
					swap(nums[nums[i] - 1], nums[i]);
				}
			}
			for(int i=0;i<n;i++)
			{
				if(nums[i] != i+1)
				{
					return i+1;
				}
			}
			return n+1;
		}
};

int main(void)
{
	Solution test;
	vector<int> num = {3,4,-1,1};
	cout << "need = " << test.firstMissingPositive(num) << endl;
};



