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
   //查找最长公共前缀!
   从头开始对比,第一个不一样就返回空
   第一个相同,比较第二个,往后推,直到其中任何一个不一样退出
   最坏情况:n个长度为m的相同字符串
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
		string out;
		int len = 0;
		if(strs.size() == 0)
			return out;
		if(strs.size() == 1)
		{
			return strs[0];
		}
		while(len < strs[0].size())
		{
			out.push_back(strs[0].at(len));
			for(auto i=1;i!=strs.size();++i)
			{
				if(len >= strs[i].size() || (out[len] != strs[i].at(len)))
				{
					if(!out.empty())
						out.pop_back();
					return out;
				}
			}
			++len;
		}

		return out;
    }
};

int main(void)
{
	vector<string> s = {"aa","a"};
	Solution f;
	cout << f.longestCommonPrefix(s) << endl;
}

