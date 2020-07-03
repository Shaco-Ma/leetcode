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
给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。
不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。
元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
示例 1:
给定 nums = [3,2,2,3], val = 3,
函数应该返回新的长度 2, 并且 nums 中的前两个元素均为 2。
△ 你不需要考虑数组中超出新长度后面的元素。
示例 2:
给定 nums = [0,1,2,2,3,0,4,2], val = 2,
函数应该返回新的长度 5, 并且 nums 中的前五个元素为 0, 1, 3, 0, 4。
注意这五个元素可为任意顺序。
你不需要考虑数组中超出新长度后面的元素。
说明:
为什么返回数值是整数，但输出的答案是数组呢?
请注意，输入数组是以「引用」方式传递的，这意味着在函数里修改输入数组对于调用者是可见的。
你可以想象内部操作如下:
// nums 是以“引用”方式传递的。也就是说，不对实参作任何拷贝
int len = removeElement(nums, val);
// 在函数里修改输入数组对于调用者是可见的。
// 根据你的函数返回的长度, 它会打印出数组中 该长度范围内 的所有元素。
for (int i = 0; i < len; i++) {
    print(nums[i]);
}
//双指针,尾部等于val,往前移动到不等于的地方,记录pos,如果r指针不等于val,那么开始移动左指针,如果等于val,那么交换两个指针的值,然后r指针等于val,继续...
//当l == r的时候,就知道结束了,长度为r-1,不对
//快慢指针的运用,要熟悉一下
*/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
		int slow = 0;
		int fast = 0, len = nums.size();
		for(fast=0;fast<len;++fast)
		{
			if(nums[fast] != val)
			{
				nums[slow] = nums[fast];
				++slow;
			}
		}
		return slow;
    }
};


int main(void)
{
	//vector<int> num = {0,1,2,2,3,0,4,2};
	vector<int> num = {3,2,2,3};
	//vector<int> num = {3};
	int val = 2;
	//int val = 3;
	Solution s;
	int len = s.removeElement(num, val);
	for(auto i=0;i<len;++i)
	{
		cout << num[i] << endl;
	}
	cout << "OLD!!!"<<endl;
	for(auto i=0;i<num.size();++i)
	{
		cout << num[i] << endl;
	}
	return EXIT_SUCCESS;
}

