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

using namespace std;

/*
	给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。
	示例：
	输入：nums = [-1,2,1,-4], target = 1
	输出：2
	解释：与 target 最接近的和是 2 (-1 + 2 + 1 = 2) 。
	提示：
	3 <= nums.length <= 10^3
	-10^3 <= nums[i] <= 10^3
	-10^4 <= target <= 10^4
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
		int ret = -100000, sum;
		int base = 0;
		int l = 0, r = 0;
		int len = nums.size();
		sort(nums.begin(), nums.end());

		while(base < len - 2)
		{
			l = base + 1;
			r = len - 1;
			//cout << "====  " << nums[base] << endl;
			while(l<r)
			{
				int l_value, r_value;
				sum = nums[base] + nums[l] + nums[r];
				//判断要不要更新ret
				l_value = (sum > target)?(sum - target):(target - sum);
				r_value = (ret > target)?(ret - target):(target - ret);
				if(l_value < r_value)
				{
					ret = sum;
				}
				//cout << sum << endl;
				if(sum == target)
				{
					return sum;
				}
				if(sum > target)
				{
					--r;
				}
				else
				{
					++l;
				}
			}
			++base;
		}

		return ret;
    }
};

int main(void)
{
	vector<int> in = {-1,2,1,-4};
	Solution f;
	cout << f.threeSumClosest(in, 1) << endl;
	return EXIT_SUCCESS;
}

