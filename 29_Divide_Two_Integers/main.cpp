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
给定两个整数，被除数 l_dividend 和除数 l_divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。
返回被除数 l_dividend 除以除数 l_divisor 得到的商。
整数除法的结果应当截去（truncate）其小数部分，例如：truncate(8.345) = 8 以及 truncate(-2.7335) = -2
示例 1:
输入: l_dividend = 10, l_divisor = 3
输出: 3
解释: 10/3 = truncate(3.33333..) = truncate(3) = 3
示例 2:
输入: l_dividend = 7, l_divisor = -3
输出: -2
解释: 7/-3 = truncate(-2.33333..) = -2
//先得到移位几次得到大于 l_dividend 的数
比如移位n次,那么对这个数进行pow(2,n),和pow(2,n-1),得到l和r
那么这个值一定在l和r之间,对这俩数进行二分查找,对比的话用的是乘法,不知道这样行不行
//从l和r之间,每次+被除数,当这次小于,下次大于的时候,这个数就是需要的数
//用long存储,最后就不会超过了
*/

class Solution {
public:
    int divide(int dividend, int divisor) {
		int nera_big = 0;
		int left_move = 0;
		long l, r;
		bool blow_zero = 0;
		long l_dividend = dividend;
		long l_divisor = divisor;
		if(l_dividend < 0 && l_divisor > 0)
		{
			l_dividend = 0 - l_dividend;
			blow_zero = 1;
		}
		else if(l_dividend > 0 && l_divisor < 0)
		{
			l_divisor = 0 - l_divisor;
			blow_zero = 1;
		}
		else if(l_divisor <0 && l_dividend < 0)
		{
			l_dividend = 0 - l_dividend;
			l_divisor = 0 - l_divisor;
		}
		//cout << "blow_zero = " << blow_zero << endl;
		if(l_divisor == 1 || l_divisor == -1)
		{
			if(blow_zero == 0)
			{
				if(l_dividend > 0)
				{
					if(l_dividend < INT_MAX)
						return l_dividend;
					else
						return INT_MAX;
				}
				else
				{
					if(l_dividend > INT_MIN)
						return 0 - l_dividend;
					else
						return INT_MAX;
				}
			}
			else
			{
				if(l_dividend > 0)
				{
					if(l_dividend < INT_MAX)
						return 0 - l_dividend;
					else
						return INT_MIN;
				}
				else
				{
					if(l_dividend > INT_MIN)
						return 0 - l_dividend;
					else
						return INT_MAX;
				}
			}
		}
		while(l_divisor<<left_move <= l_dividend)
		{
			cout << "l_divisor<<left_move = " << (l_divisor<<left_move) << endl;
			left_move++;
		}
		cout << "left_mode = " << left_move << endl;
		if(left_move < 1)
		{
			return left_move;
		}
		l = l_divisor<<(left_move - 1);
		r = l_divisor<<left_move;
		cout << "l = " << l << endl;
		cout << "r = " << r << endl;
		left_move = pow(2, left_move-1);
		cout << "left_mode = " << left_move << endl;
		while(l<r)
		{
			if(l<=l_dividend && l + l_divisor > l_dividend)
			{
				return blow_zero == 0?left_move:(0 - left_move);
			}
			else
			{
				l += l_divisor;
				++left_move;
			}
		}
		return blow_zero == 0?left_move:(0 - left_move);
    }
};

int main(void)
{
	Solution f;
	//int l_dividend = 10, l_divisor = 3;
	//int l_dividend = 7, l_divisor = 3;
	//int l_dividend = 1000, l_divisor = -3;
	//int l_dividend = -1, l_divisor = -1;
	//int l_dividend = 2, l_divisor = 2;
	//int l_dividend = -2147483648, l_divisor = 1;
	//int l_dividend = 2147483647, l_divisor = 2;
	int l_dividend = -2147483648, l_divisor = -3;
	cout << f.divide(l_dividend, l_divisor) << endl;;
	return EXIT_SUCCESS;
}

