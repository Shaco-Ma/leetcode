#include <iostream>

using namespace std;

/*
给你一个非负整数 x ，计算并返回 x 的 算术平方根 。
由于返回类型是整数，结果只保留 整数部分 ，小数部分将被 舍去 。
注意：不允许使用任何内置指数函数和算符，例如 pow(x, 0.5) 或者 x ** 0.5 。
示例 1：
输入：x = 4
输出：2
示例 2：
输入：x = 8
输出：2
解释：8 的算术平方根是 2.82842..., 由于返回类型是整数，小数部分将被舍去。
//查了下平方根的方法,还挺多的,最简单的就是二分查找
*/

class Solution {
public:
	int get(long long l, long long r, int target)
	{
		if(l+1==r)
			return l;
		if(((l+r)/2)*((l+r)/2) < target)
		{
			return get((l+r)/2, r, target);
		}
		else if(((l+r)/2)*((l+r)/2) > target)
		{
			return get(l, (l+r)/2, target);
		}
		else
		{
			return (l+r)/2;
		}
	}
    int mySqrt(int x)
	{
		int l=0,r=0;
		if(x==0)
			return 0;
		return get(0, x, x);
    }
};

int main(void)
{
	Solution s;
	cout << s.mySqrt(4) << endl;
	cout << s.mySqrt(8) << endl;
	cout << s.mySqrt(10) << endl;
}

