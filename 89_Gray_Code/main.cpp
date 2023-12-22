#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cmath>

/*
   n 位格雷码序列 是一个由 2n 个整数组成的序列，其中：
   每个整数都在范围 [0, 2n - 1] 内（含 0 和 2n - 1）
   第一个整数是 0
   一个整数在序列中出现 不超过一次
   每对 相邻 整数的二进制表示 恰好一位不同 ，且
   第一个 和 最后一个 整数的二进制表示 恰好一位不同
   给你一个整数 n ，返回任一有效的 n 位格雷码序列 。

   示例 1：
   输入：n = 2
   输出：[0,1,3,2]
   解释：
   [0,1,3,2] 的二进制表示是 [00,01,11,10] 。
   - 00 和 01 有一位不同
   - 01 和 11 有一位不同
   - 11 和 10 有一位不同
   - 10 和 00 有一位不同
   [0,2,3,1] 也是一个有效的格雷码序列，其二进制表示是 [00,10,11,01] 。
   - 00 和 10 有一位不同
   - 10 和 11 有一位不同
   - 11 和 01 有一位不同
   - 01 和 00 有一位不同

   示例 2：
   输入：n = 1
   输出：[0,1]

   提示：

   1 <= n <= 16
   //格雷码生成方式,先改变最右边的数据,然后再改变右起第一个为1的位元的左边位元
   用一个例子来说明：
   假设产生3位元的格雷码，原始值位 000
   第一步：改变最右边的位元值： 001
   第二步：改变右起第一个为1的位元的左边位元： 011
   第三步：改变最右边的位元值： 010
   第四步：改变右起第一个为1的位元的左边位元： 110
   第五步：改变最右边的位元值： 111
   第六步：改变右起第一个为1的位元的左边位元： 101
   第七步：改变最右边的位元值： 100

*/

using namespace std;

class Solution {
	public:
		//最大是16,bit五位就够了
#if 1
		void get_vector(vector<int> &target, int n, int cur_num)
		{
			if(target.size() >= pow(2, n))
			{
				return;
			}
			bitset<15> bit_num(cur_num);
			for(int j=0;j<pow(2,n) - 1;j++)
			{
				if(j&1)
				{
					for(int i=0;i<n-1;i++)
					{
						if(bit_num[i] == 1)
						{
							bit_num[i+1].flip();
							break;
						}
					}
				}
				else
				{
					bit_num[0].flip();
				}
				cur_num = bit_num.to_ulong();
				target.push_back(cur_num);
			}
		}
		vector<int> grayCode(int n)
		{
			vector<int> result;
			result.push_back(0);
			get_vector(result, n, 0);
			return result;
		}
#else
		void get_vector(vector<int> &target, int n, int cur_num)
		{
			if(target.size() >= pow(2, n))
			{
				return;
			}
			bitset<16> num(cur_num);
			for(int i=0;i<n;i++)
			{
				//改变这一位,然后查看有没有在数组里面,没有的话插入,继续循环
				num.flip(i);
				if(num.to_ulong() < pow(2, n) && find(target.begin(), target.end(), num.to_ulong()) == target.end())
				{
					target.push_back(num.to_ulong());
					get_vector(target, n, num.to_ulong());
					if(target.size() >= pow(2, n))
					{
						break;
					}
					else
					{
						target.pop_back();
					}
				}
				num.flip(i);
			}
		}
		vector<int> grayCode(int n)
		{
			vector<int> result;
			result.push_back(0);
			get_vector(result, n, 0);
			return result;
		}
#endif
};

int main(void)
{
	vector<int> result;
	Solution s;
	result = s.grayCode(2);
	for(auto item:result)
	{
		cout << item << "  ";
	}
	cout << endl;
	//result = s.grayCode(3);
	//for(auto item:result)
	//{
	//	cout << item << "  ";
	//}
	//cout << endl;
	//result = s.grayCode(4);
	//for(auto item:result)
	//{
	//	cout << item << "  ";
	//}
	//cout << endl;
	//result = s.grayCode(5);
	//for(auto item:result)
	//{
	//	cout << item << "  ";
	//}
	//cout << endl;
	result = s.grayCode(6);
	for(auto item:result)
	{
		cout << item << "  ";
	}
	cout << endl;
	result = s.grayCode(16);
	for(auto item:result)
	{
		cout << item << "  ";
	}
	cout << endl;
}


