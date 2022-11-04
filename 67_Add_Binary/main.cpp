#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

/*
   给你两个二进制字符串 a 和 b ，以二进制字符串的形式返回它们的和。
   示例 1：
   输入:a = "11", b = "1"
   输出："100"
   示例 2：
   输入：a = "1010", b = "1011"
   输出："10101"
*/

class Solution
{
public:
    string addBinary(string a, string b)
	{
		string result;
		int size;
		//遍历短的,加到长的里面,然后在计算
		string less,more;
		if(a.size() < b.size())
		{
			less = a;
			more = b;
		}
		else
		{
			less = b;
			more = a;
		}
		size = less.size();
		for(int i=0;i<size;i++)
		{
			more[i+more.size()-size] += less[i] - '0';
		}
		a = more;
		size = a.size();
		//cout << "base = " << a << endl;
		for(int i=size-1;i>0;i--)
		{
			if(a.at(i) >= '2')
			{
				a.at(i-1) += a.at(i)/'2';
				a.at(i) %= '2';
				a.at(i) += '0';
			}
			result.push_back(a.at(i));
			//cout << "a.at(" << i << ") = " << a.at(i) << endl;
		}
		//cout << "a = " << a << endl;
		if(a.at(0) >= '2')
		{
			result.push_back(a.at(0)%'2' + '0');
			result.push_back(a.at(0)/'2' + '0');
		}
		else
		{
			result.push_back(a.at(0));
		}
		reverse(result.begin(), result.end());
		return result;
    }
};

int main(void)
{
	Solution s;
	string a1="1010";
	string b1="1011";
	cout << s.addBinary(a1, b1) << endl;
	string a2 ="11";
	string b2 ="1";
	cout << s.addBinary(a2, b2) << endl;
	string a3 ="1111";
	string b3 ="1111";
	cout << s.addBinary(a3, b3) << endl;
	string a4 = "1110110101";
	string b4 = "1110111011";
	cout << s.addBinary(a3, b3) << endl;
	return 1;
}

