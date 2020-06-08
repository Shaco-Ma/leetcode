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
	给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。
	注意：
	答案中不可以包含重复的四元组。

	原来真的是拆成3个数想加......
	忘记了去重,要加上
*/

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		int a, b, c, d;
		int len;
		vector<vector<int>> out;
		vector<int> temp;
		sort(nums.begin(), nums.end());
		if(nums.size() < 4)
			return out;
		len = nums.size();
		a = 0;
		while(a<(len-3))
		{
			b = a + 1;
			//cout << "ab:" << a << " " << b << endl;
			if(nums[a] + nums[b] + nums[b+1] + nums[b+2] > target)
			{
				//cout << nums[a] << " " << nums[b] << " " << nums[c] << " " << nums[d] << " " << endl;
				break;
			}
			if(a > 0 && nums[a] == nums[a-1])
			{
				++a;
				continue;
			}
			while(b<(len-2))
			{
				c = b + 1;
				d = len - 1;
				//cout << "____abcd: " << a << " " << b << " " << c << " " << d << " " << endl;
				if(nums[a] + nums[b] + nums[c] + nums[c+1] > target)
				{
					//cout << "____" << nums[a] << " " << nums[b] << " " << nums[c] << " " << nums[d] << " " << endl;
					break;
				}
				if(b > a + 1 && nums[b] == nums[b-1])
				{
					++b;
					continue;
				}
				while(c<d)
				{
					int sum = nums[a] + nums[b] + nums[c] + nums[d];
					//cout << "sum = " << sum << " target = " << target << endl;
					//cout << "abcd: " << a << " " << b << " " << c << " " << d << " " << endl;
					if(sum > target)
					{
						--d;
					}
					else if(sum < target)
					{
						++c;
					}
					else
					{
						temp.clear();
						temp.push_back(nums[a]);
						temp.push_back(nums[b]);
						temp.push_back(nums[c]);
						temp.push_back(nums[d]);
						out.push_back(temp);
						//要在成功之后去重
						while(c<d && nums[c] == nums[c+1])
							++c;
						while(c<d && nums[d] == nums[d-1])
							--d;
						--d;++c;
					}
				}
				++b;
			}
			++a;
		}

		return out;
	}
};

int main(void)
{
	vector<int> in = {-1,2,2,-5,0,-1,4};
	//				-5, -1, -1, 0, 2, 2, 4
	Solution f;
	vector<vector<int>> ret = f.fourSum(in, 3);
	sort(in.begin(), in.end());
	for(auto item : in)
	{
		cout << item << "  ";
	}
	cout << endl;
	for(auto item : ret)
	{
		for(auto num:item)
		{
			cout << num << "\t";
		}
		cout << endl;
	}
	return EXIT_SUCCESS;
}

