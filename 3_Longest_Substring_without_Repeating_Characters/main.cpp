#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

//还是要从第一个开始算,每一个新的字符都要从前面查找
class Solution {
public:
	unordered_set<char> new_s;
	int cur = 0;
    int lengthOfLongestSubstring(string s) {
		for(int i=0;i<s.size();i++)
		{
			if(i != 0)
			{
				//删除最前面的
				new_s.erase(s[i]);
			}
			//查看当前字符是否在原来的有
			while(cur < s.size() && !new_s.count(s.at(cur)))
			{
				new_s.insert(s.at(cur));
			}
		}
		return new_s.size();
    }
};

int main(void)
{
	//string s("pwwkew");
	//string s("abcabcbb");
	string s("au");
	//string s("bbbbb");
	Solution test;
	cout << test.lengthOfLongestSubstring(s) << endl;
	return 0;
}


