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

using namespace std;

/*
	给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。

	给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
示例:
	输入："23"
	输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
	{2, "abc"}
	{3, "def"}
	{4, "ghi"}
	{5, "jkl"}
	{6, "mno"}
	{7, "pqrs"}
	{8, "tuv"}
	{9, "wxyz"}
	//看了答案,从第0个开始,依次往后遍历
*/

class Solution {
private:
	const map<char, string> num_to_char = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
	vector <string> ret;
	string temp;
	void backtrack(string in, string next)
	{
		if(next.size() == 0)
		{
			ret.push_back(in);
			//temp.pop_back();
		}
		else
		{
			//cout << "next[0]" << next[0] << endl;
			for(auto i=0;i<(num_to_char.at(next[0])).size();++i)
			{
				temp.push_back(num_to_char.at(next[0]).at(i));
				//cout << "temp: " << temp << endl;
				backtrack(temp, &next[1]);
				temp.pop_back();
			}
		}
	}
public:
    vector<string> letterCombinations(string digits) {
		if(digits.size() == 0)
			return ret;
		backtrack("", digits);
		return ret;
    }
};

int main(void)
{
	Solution f;
	vector<string> ret = f.letterCombinations("234");
	for(auto item:ret)
	{
		cout << item << endl;
	}
	return EXIT_SUCCESS;
}

