#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <limits.h>

using namespace std;

/*
	某一位为4,9的时候,根据当前位进行判断:
	I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
	X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
	C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900
*/

class Solution {
public:
    string intToRoman(int num) {
		const vector<string> thousand = {"", "M", "MM", "MMM"};
		const vector<string> hundred  = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
		const vector<string> ten      = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
		const vector<string> unit     = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
		int bit;
		string s;
		//对1000位处理
		s += thousand[num/1000];
		//对100位处理
		s += hundred[num%1000/100];
		//对10位处理
		s += ten[num%100/10];
		//对1位处理
		s += unit[num%10];
        
		return s;
    }
};

int main(int argv, char * argc[])
{
	if(argv >= 2)
	{
		Solution f;
		int num = stoi(argc[1]);
		if(num < 1 || num > 3999)
		{
			cout << "The Num is " << num << endl;
			return EXIT_FAILURE;
		}
		cout << f.intToRoman(num) << endl;
	}
	else
	{
		cout << "No Input!" << endl;
	}
	return EXIT_SUCCESS;
}

