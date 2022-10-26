#include <iostream>
#include <vector>
#include <climits>

using namespace std;

/*
给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
子数组 是数组中的一个连续部分。
示例 1：
输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
输出：6
解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。
示例 2：
输入：nums = [1]
输出：1
示例 3：
输入：nums = [5,4,-1,7,8]
输出：23
//思路
	找到第一个正数的起始位置x,从x开始往后+
	到达第二个正数的位置y,计算前面的和加上新的数是不是大于当前数y
	如果小于,从新计算和
	如果大于,继续加
	每次加一个数都要判断是否大于和,大于就取代,直到最后一个数
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums)
	{
		int result = nums.at(0);
		int temp = 0;
		int size = nums.size();
		for(auto i=0;i<size;i++)
		{
			//查看是否所有的和小于当前数,如果小于,从新计算,如果大于,继续加
			if(temp + nums.at(i) < nums.at(i))
			{
				temp = nums.at(i);
				//cout << "i = " << i << endl;
				//cout << " > 0 temp = " << temp << endl;
			}
			else
			{
				temp += nums.at(i);
				//cout << "temp = " << temp << endl;
			}
			if(temp > result)
			{
				result = temp;
				//cout << "result = " << result << endl;
			}
		}
		return result;
    }
};

int main(void)
{
	vector<int> num = {-2,1,-3,4,-1,2,1,-5,4};
	vector<int> num1 = {5,4,-1,7,8};
	vector<int> num2 = {-5,-10,-100, -1};
	vector<int> num3 = {-5,1};
	Solution s;
	cout << s.maxSubArray(num) << endl;
	cout << s.maxSubArray(num1) << endl;
	cout << s.maxSubArray(num2) << endl;
	cout << s.maxSubArray(num3) << endl;
	return 1;
}

