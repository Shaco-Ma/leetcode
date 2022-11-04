#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
	给定一个由 整数 组成的 非空 数组所表示的非负整数，在该数的基础上加一。
	最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
	你可以假设除了整数 0 之外，这个整数不会以零开头。
	示例 1：
	输入：digits = [1,2,3]
	输出：[1,2,4]
	解释：输入数组表示数字 123。
	示例 2：
	输入：digits = [4,3,2,1]
	输出：[4,3,2,2]
	解释：输入数组表示数字 4321。
	示例 3：
	输入：digits = [0]
	输出：[1]
	//思路,从后往前遍历
*/

class Solution
{
public:
    vector<int> plusOne(vector<int>& digits)
	{
		vector<int> result;
		int up = 0;
		int size = digits.size()-1;
		digits.at(size)++;
		for(int i=size;i>0;i--)
		{
			if(digits.at(i) == 10)
			{
				digits.at(i) = 0;
				digits.at(i-1)++;
			}
		}
		if(digits.at(0) == 10)
		{
			result.push_back(1);
			digits.at(0) = 0;
		}
		copy(digits.begin(), digits.end(), back_inserter(result));
		return result;
    }
};

int main(void)
{
	Solution s;
	vector<int> num1 = {1, 2, 3};
	num1 = s.plusOne(num1);
	for(auto item:num1)
	{
		cout << item << "  ";
	}
	cout << endl;
	vector<int> num2 = {9, 2, 3};
	num2 = s.plusOne(num2);
	for(auto item:num2)
	{
		cout << item << "  ";
	}
	cout << endl;
	vector<int> num3 = {9, 9, 9};
	num3 = s.plusOne(num3);
	for(auto item:num3)
	{
		cout << item << "  ";
	}
	cout << endl;
	return 1;
}

