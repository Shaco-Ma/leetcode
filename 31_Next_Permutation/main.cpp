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
实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。
如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。
必须原地修改，只允许使用额外常数空间。
以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
//下一个更大,那就简单了啊,从尾部开始比较啊
最后一个数last, 和最后倒数第二个数pre比较,pre < last,pre就往前移动一位,直到第0位,移动到第n位
//然后把n位之后的,反转就行了:为什么反转,因为last往前,没有比新的last小的了, pre < last, 并且前面的都比last大
//↑,不对,应该是找到第0位还没找到,就last往前找
如果找到第0位还是比last大的,那么就反转整个vector

//错了,答案↓ 
//从后往前找,找到一个下降的两位,low,和high,再从high开始,找到一个比low大的数,交换,再排序剩下的
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
		int l = nums.size() - 2, r;
		if(nums.size() <= 1)
			return;
		while(l >= 0 && nums[l] >= nums[l+1])
		{
			--l;
		}
		if(l>=0)
		{
			r = nums.size() - 1;
			while(r > l && nums[r] <= nums[l])
			{
				--r;
			}
			swap(nums[r], nums[l]);
		}
		//对后面的数字进行排序
		reverse(nums.begin() + l + 1, nums.end());
    }
};

int main(void)
{
	Solution f;
	//vector<int> nums = {1, 3, 2};
	vector<int> nums = {1, 2, 3};
	cout << "Old: ";
	for(auto item:nums)
	{
		cout << item;
	}
	cout << endl;
	f.nextPermutation(nums);
	cout << "New: ";
	for(auto item:nums)
	{
		cout << item;
	}
	cout << endl;
	return EXIT_SUCCESS;
}

