#include <iostream>
#include <vector>

/*
给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。
注意：不能使用任何内置的 BigInteger 库或直接将输入转换为整数。
示例 1:
输入: num1 = "2", num2 = "3"
输出: "6"
示例 2:
输入: num1 = "123", num2 = "456"
输出: "56088"
//思路,选其中一个字符串,按位乘以另一个字符串,结果相加
从后往前,比如123,456
先取3*456,得到一个值a
再取2*456*遍历次数1,得到b
...
再取x*456*遍历次数n,得到z
将所有的string按数量进行每一位相加,这样可以避免出现数据溢出
//看了答案,感觉按位乘更简单高效
长度为m,n的两个数相乘,最大长度为m+n,比如99*99最大是4位数,10*10最大是3位数
定义一个这么长的数组,然后按位相乘,再进行相加,最后再按照每一位计算余数和除10数(前一位+1)
*/

using namespace std;

class Solution
{
	public:
		string multiply(string num1, string num2)
		{
			if(num1 == "0" || num2 == "0")
			{
				return "0";
			}
			int m = num1.size(), n = num2.size();
			auto ansArr = vector<unsigned int>(m+n, 0);
			for(int i=m-1;i>=0;i--)
			{
				int x = num1.at(i) - '0';
				for(int j=n-1;j>=0;j--)
				{
					int y = num2.at(j) - '0';
					//放在最后一位
					ansArr[i+j+1] += x*y;
				}
			}
			for(int i=m+n-1;i>0;i--)
			{
				ansArr[i-1] += ansArr[i] / 10;
				ansArr[i] = ansArr[i] % 10;
			}
			string ans;
			int index = ansArr[0] == 0?1:0;
			for(int i = index;i<m+n;i++)
			{
				ans.push_back(ansArr[i] + '0');
			}
			return ans;
		}
};

int main(void)
{
	string s1("4512462349278482374");
	string s2("638989058297358927589275892");
	Solution S;
	string s = S.multiply(s1, s2);
	cout << s.size() << endl;
	cout << s << endl;
}

