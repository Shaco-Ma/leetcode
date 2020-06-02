#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <limits.h>

using namespace std;

/*
   按位取?
   //第一个非0数据一定+,-或者数字,之后就应该是连续的数字组合
*/

class Solution {
public:
    int myAtoi(string str) {
		unsigned char flag = 0;
		long int num = 0;
		int len = 0, temp_num = 0;
		string bit_s;
		int get_len = 0;
		while(len < str.size())
		{
			bit_s = str.at(len);
			//cout << "bit_s: " << bit_s << endl;
			if(*bit_s.c_str() != ' ')
			{
				if(get_len == 0)
				{
					if(*bit_s.c_str() != '-' && *bit_s.c_str() != '+' && !(*bit_s.c_str() >= '0' && *bit_s.c_str() <= '9'))
						return 0;
					if(*bit_s.c_str() == '-')
					{
						flag = 1;
					}
					else if(*bit_s.c_str() == '+')
					{
						flag = 2;
					}
					else if(*bit_s.c_str() >= '0' && *bit_s.c_str() <= '9')
					{
						flag = 2;
						temp_num = stoi(bit_s);
						if(flag == 1)
						{
							temp_num = 0 - temp_num;
						}
						num = num*10 + temp_num;
					}
				}
				else
				{
					if(!(*bit_s.c_str() >= '0' && *bit_s.c_str() <= '9'))
					{
						return num;
					}
					else
					{
						temp_num = stoi(bit_s);
						if(flag == 1)
						{
							temp_num = 0 - temp_num;
						}
						if(num > INT_MAX/10 || (num == INT_MAX/10 && temp_num > INT_MAX%10))
							return INT_MAX;
						if(num < INT_MIN/10 || (num == INT_MIN/10 && temp_num < INT_MIN%10))
							return INT_MIN;
						num = num*10 + temp_num;
						//cout << num << endl;
					}
				}
				get_len++;
			}
			else
			{
				if(get_len != 0)
					break;
			}
			len++;
		}
		/*if(num > INT_MAX)
			return INT_MAX;
		if(num < INT_MIN)
			return INT_MIN;*/
		return num;
    }
};

int main(void)
{
	Solution f;
	cout << f.myAtoi("20000000000000000000") << endl;

	return EXIT_SUCCESS;
}

