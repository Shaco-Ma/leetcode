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
#include <list>
#include <stack>
#include <random>

using namespace std;

/*
	数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
	输入：n = 3
	输出：[
       "((()))",
       "(()())",
       "(())()",
       "()(())",
       "()()()"
     ]
	 有效的,有一个左的,要有一个右的,这俩中间可以有无数个有效的
	 //( 代表1,)代表 -1?
	 从左往右的过程中,总值必须大于等于0,如果小于,就返回上一层?
	 //看了答案才知道怎么处理:大致的思路是对的,但是对于用sum的话不方便计算有多少个括号
*/

class Solution {
public:
	void backtest(vector<string> &in, string &s, int n, int l, int r)
	{
		if(s.size() == n*2)
		{
			in.push_back(s);
			return;
		}
		else
		{
			if(l < n)
			{
				s.push_back('(');
				backtest(in, s, n, l+1, r);
				s.pop_back();
			}
			if(r < l)
			{
				s.push_back(')');
				backtest(in, s, n, l, r+1);
				s.pop_back();
			}
		}
	}
    vector<string> generateParenthesis(int n) {
		vector<string> out;
		string temp;
		int l = 0 ,r = 0;
		backtest(out, temp, n, l, r);

		return out;
    }
};

int main(void)
{
	Solution f;
	vector<string> out = f.generateParenthesis(3);
	for(auto item:out)
	{
		cout << item << endl;
	}
	return EXIT_SUCCESS;
}

