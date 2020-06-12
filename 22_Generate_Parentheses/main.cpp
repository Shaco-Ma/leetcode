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
*/

class Solution {
public:
	map<char, int> parnum = {{'(', 1}, {')', -1}};
	stack<char> lpar;
	stack<char> rpar;
	vector<string> out;
	int sum;
	bool flag;
	vector<string> backtest(int n)
	{
		return out;
	}
    vector<string> generateParenthesis(int n) {
		lpar.push('(');
		lpar.push('(');
		lpar.push('(');
		rpar.push(')');
		rpar.push(')');
		rpar.push(')');

		return backtest(n);
    }
};

int main(void)
{
	Solution f;
	return EXIT_SUCCESS;
}

