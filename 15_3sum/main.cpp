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
   从左端选定一个数x,位置a
   然后以a+1作为y,最后一个数作为z
   如果y+z+a 大于0,移动yz中大的,反之移动小的,如果相等,两个一起移动
   结束之后x移动到a+1


   //没有想到先排序
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
		set<vector<int>> set_out;
		vector<int> vec_out;
		vector<vector<int>> out;
		int a=0, b=0, c=0, len = nums.size();
		if(len < 3)
		{
			return out;
		}

		sort(nums.begin(), nums.end());

		while(a<len-2)
		{
			if(nums[a] > 0)
				break;
			if(a > 0 && nums[a] == nums[a-1])
			{
				a++;
				continue;
			}
			b = a+1;
			c = len - 1;
			while(b<c)
			{
				if(nums[b] + nums[c] + nums[a] > 0)
				{
					--c;
				}
				else if(nums[b] + nums[c] + nums[a] < 0)
				{
					++b;
				}
				else
				{
					//需要的三个数字,b++,c--
					vec_out.clear();
					vec_out.push_back(nums[a]);
					vec_out.push_back(nums[b]);
					vec_out.push_back(nums[c]);
					//cout << "first: " << nums[a] << " " << nums[b] << " " << nums[c]<<endl;
					set_out.insert(vec_out);
					//对左边界数进行去重
					while(b<c && nums[b] == nums[b+1])
						++b;
					//对右边界数进行去重
					while(b<c && nums[c] == nums[c-1])
						--c;
					++b;--c;
				}
			}
			a++;
		}
		for(auto item:set_out)
		{
			out.push_back(item);
		}
		return out;
    }
};

int main(void)
{
	vector<vector<int>> result;
	vector<int> in = {-1, 0, 1, 2, -1, -4};
	Solution f;
	result = f.threeSum(in);
	for(auto item : result)
	{
		for(auto num:item)
		{
			cout << num << "\t";
		}
		cout << endl;
	}
	return EXIT_SUCCESS;
}

