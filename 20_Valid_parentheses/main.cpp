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
	给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
	有效字符串需满足：
	左括号必须用相同类型的右括号闭合。
	左括号必须以正确的顺序闭合。
	注意空字符串可被认为是有效字符串。
	输入: "()"输出: true
	输入: "()[]{}"输出: true
	输入: "(]"输出: false
	输入: "([)]"输出: false
	输入: "{[]}"输出: true

	没看答案:1遇到匹配的就都往右移动,2,遇到不匹配的,就往右找到匹配,并往中间移动
	看了答案,用了轮训,发现到(([]){})这种就不行了,还是要换个思路:进行意义匹配,比如读到左边的那种,就压到string里面,如果是右边的,就弹出string最后一个,看是否一样
	map要用右左的形式
*/

class Solution {
public:
	map<char, char> parenthesis = {{')', '('}, {']', '['}, {'}', '{'}};
    bool isValid(string s) {
		stack<char> stack_s;
		int i = 0;
		int len =s.size();
		if(len == 0)return true;
		if(len < 2 || (len & 1))
			return false;
		while(i < len)
		{
			if(parenthesis[s[i]])
			{
				char temp = stack_s.empty()?'c':stack_s.top();
				if(parenthesis[s[i]] != temp)
					return false;
				stack_s.pop();
			}
			else
			{
				stack_s.push(s[i]);
			}
			++i;
		}

		if(stack_s.empty())
			return true;
		return false;
    }
};

int main(void)
{
	Solution f;
	cout << f.isValid("((") << endl;
	//cout << f.isValid("){") << endl;
	//cout << f.isValid("(([]){})") << endl;
	return EXIT_SUCCESS;
}

