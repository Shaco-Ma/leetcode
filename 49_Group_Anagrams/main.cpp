#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

/*
给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。
字母异位词 是由重新排列源单词的字母得到的一个新单词，所有源单词中的字母通常恰好只用一次。

示例 1:
	输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
	输出: [["bat"],["nat","tan"],["ate","eat","tea"]]
示例 2:
	输入: strs = [""]
	输出: [[""]]
示例 3:
	输入: strs = ["a"]
	输出: [["a"]]

思路:
	从0开始遍历数组,维护一个代表每一个元素的数组,代表这个数用过
	维护一个map,代表每一个字符串中元素出现的次数
	看了答案,先排序,用排序过的作为健值.......
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
	{
		vector<vector<string>> result;
		map<string, vector<string>> mp;
		for(auto i=0;i<strs.size();i++)
		{
			string key = strs.at(i);
			sort(key.begin(), key.end());
			mp[key].push_back(strs.at(i));
		}
		for(auto item:mp)
		{
			result.push_back(item.second);
		}
		return result;
    }
};

int main(void)
{
	vector<string> str = {"eat", "tea", "tan", "ate", "nat", "bat"};
	vector<vector<string>> back;
	Solution s;
	back = s.groupAnagrams(str);
	for(auto item:back)
	{
		for(auto estr:item)
		{
			cout << estr << " ";
		}
		cout << endl;
	}
	return 1;
}

