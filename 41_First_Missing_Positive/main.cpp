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
	看了答案,再哈希,哈希表,定义一个数,从1开始,定义一个vector,长度为nums长度,全部格式化为0
	从数组内取数,当>0的时候,查找数组对应的下标是不是0,是的话将这个数置1,如果下标值=target,那么从但前下标往后找到第一个为0的数
	此下标为最终的所需的值
*/

using namespace std;

class Solution {
	private:
		int result = 1;
		vector<int> target;
		vector<int>::iterator cur;
	public:
		int firstMissingPositive(vector<int>& nums) {
			target.resize(nums.size(), 0);
			cur = target.begin();
			for(int i=0;i<nums.size();i++)
			{
				target.at(nums.at(i)) = 1;
				if(i == result)
				{
					//找到第一个不为0的数
					auto item = find(cur, target.end(), 0);
					cur = item;
					result = cur - target.begin();
					cout << result << endl;
				}
			}
			return result;
		}
};

int main(void)
{
	Solution test;
	vector<int> num = {3,4,-1,1};
	cout << "need = " << test.firstMissingPositive(num) << endl;
};



