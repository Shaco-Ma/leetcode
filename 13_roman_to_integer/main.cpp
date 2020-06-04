#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <limits.h>
#include <map>
#include <set>
#include <utility>

using namespace std;

/*
   遍历?map?
   遇到M就+1000
   遇到C和D,要看下一位是不是X或者L,再看下下一位是不是X或者L,这样把百位的全找出来了,然后根据字串找这个值
   遇到X和L,找下一位和下下一位是不是I或者V,找到不是这俩的,根据字串找值
   遇到I,直接找到尾部
*/

class Solution {
public:
	//查找每一位数字从哪里开始,总共几个
	pair<int, int> get_string(string in, int start_num, set<char> s_in, int s_len)
	{
		pair<int, int> ret(start_num, 0);
		for(auto i=start_num;i!=s_len;++i)
		{
			if(s_in.count(in[i]))
			{
				ret.second++;
			}
			else
			{
				break;
			}
		}
		return ret;
	}
    int romanToInt(string s) {
		//第一个是第几位,第二个是数量
		pair<int, int> out;
		const vector<set<char>> t = {{'M'}, {'C', 'D', 'M'}, {'X', 'L', 'C'}, {'I', 'V', 'X'}};
		const vector<map<string, int>> all = {{{"M", 1000}, {"MM", 2000}, {"MMM", 3000}},
											  {{"C", 100}, {"CC", 200}, {"CCC", 300}, {"CD", 400}, {"D", 500}, {"DC", 600}, {"DCC", 700}, {"DCCC", 800}, {"CM", 900}}, 
											  {{"X", 10},  {"XX", 20},  {"XXX", 30},  {"XL", 40},  {"L", 50},  {"LX", 60},  {"LXX", 70},  {"LXXX", 80},  {"XC", 90}}, 
											  {{"I", 1}, {"II", 2}, {"III", 3}, {"IV", 4}, {"V", 5}, {"VI", 6}, {"VII", 7}, {"VIII", 8}, {"IX", 9}}};
		int num = 0;
		int len = s.size();
		string get_bit;
		int start = 0;
		map<string, int> temp;

		for(auto i=0;i!=t.size();++i)
		{
			out.first = 0;
			out.second = 0;
			get_bit.clear();
			//cout << "start = " << start << endl;
			out = get_string(s, start, t[i], len);
			cout << start << "  "<<out.second << endl;
			for(auto j=0;j!=out.second;++j)
			{
				get_bit.push_back(s[j+start]);
			}
			cout << get_bit << endl;
			//num += (all[i])[get_bit];
			temp = all[i];
			num += temp[get_bit];
			start += out.second;
		}

		return num;
    }
};

int main(int argv, char * argc[])
{
	if(argv >= 2)
	{
		Solution f;
		cout << f.romanToInt(argc[1]) << endl;
	}
	else
	{
		cout << "No Input!" << endl;
	}
	return EXIT_SUCCESS;
}

