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
	给定一个排序数组，你需要在 原地 删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
	不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。
	示例 1:
	给定数组 nums = [1,1,2],
	函数应该返回新的长度 2, 并且原数组 nums 的前两个元素被修改为 1, 2。
	你不需要考虑数组中超出新长度后面的元素。
	示例 2:
	给定 nums = [0,0,1,1,1,2,2,3,3,4],
	函数应该返回新的长度 5, 并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4。
	你不需要考虑数组中超出新长度后面的元素。

	//从第一个开始,找到+1存在的,不存在再找+1存在的,然后删除从begin之后到找到的那个,都是前包后不包的
	但是觉得用标准库的算法会省时间吗?--->错,不知道怎么找到下一个的迭代器
	//遍历一遍,找相同的删除
	//原来可以不删除,移动位置就行了啊
*/

class Solution {
public:
	int len = 0;
    int removeDuplicates(vector<int>& nums) {
		int offset = 0;
		int nums_len = nums.size();
		if(nums_len == 0)return 0;
		while(offset < nums_len)
		{
			if(nums[len] != nums[offset])
			{
				++len;
				nums[len] = nums[offset];
			}
			++offset;
		}
		return len+1;
    }
};

int main(void)
{
	vector<int> num = {0,0,1,1,1,2,2,3,3,4};
	Solution s;
	int len = s.removeDuplicates(num);
	for(auto i=0;i<len;++i)
	{
		cout << num[i] << endl;
	}
	return EXIT_SUCCESS;
}

