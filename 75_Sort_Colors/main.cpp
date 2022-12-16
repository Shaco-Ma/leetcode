#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/*
给定一个包含红色、白色和蓝色、共 n 个元素的数组 nums ，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。
必须在不使用库内置的 sort 函数的情况下解决这个问题。
示例 1：
输入：nums = [2,0,2,1,1,0]
输出：[0,0,1,1,2,2]
示例 2：
输入：nums = [2,0,1]
输出：[0,1,2]
//看了答案,尝试自己写一下
//一个记录0的位置,一个记录1的位置
//找到1就跟p1交换,p1++
//找到0了,就跟p0交换,p0和p1都++,如果p0<p1,也要交换p1和i
*/

class Solution {
public:
    void sortColors(vector<int>& nums)
	{
		int size = nums.size();
		int p0 = 0, p1 = 0;
		for(int i=0;i<size;i++)
		{
			if(nums[i] == 1)
			{
				swap(nums[i], nums[p1]);
				p1++;
			}
			else if(nums[i] == 0)
			{
				swap(nums[i], nums[p0]);
				if(p0 < p1)
				{
					swap(nums[i], nums[p1]);
				}
				p0++;
				p1++;
			}
		}
    }
};

int main(void)
{
	vector<int> a = {2,0,2,1,1,0};
	Solution s;
	s.sortColors(a);
	for(auto item:a)
	{
		cout << item << "  ";
	}
	cout << endl;
	vector<int> b = {2,0,1};
	s.sortColors(b);
	for(auto item:b)
	{
		cout << item << "  ";
	}
	cout << endl;
	return 1;
}

