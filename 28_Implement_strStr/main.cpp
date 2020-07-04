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
#include <queue>

using namespace std;
/*
实现 strStr() 函数。
给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。
示例 1:
输入: haystack = "hello", needle = "ll"
输出: 2
示例 2:
输入: haystack = "aaaaa", needle = "bba"
输出: -1
说明:
当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。
对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。
//滑动窗口,第一个相同的时候,移动两个指针对比,如果中间有不一样的,那么左边移动到不一样的那一位开始
				for(nl=1;nl<nlen;++nl)
				{
					cout << "nl = " << nl << endl;
					if(haystack[l+nl] != needle[nl])
					{
						nl = 0;
						l += nl;
						break;
					}
				}
				if(nl == nlen)
				{
					break;
				}
*/

class Solution {
public:
    int strStr(string haystack, string needle) {
		int l = 0, len = haystack.size(), nl = 0, nlen = needle.size();
		if(needle.size() == 0)
			return 0;

		while(l < len && nl < nlen)
		{
			if(haystack[l] == needle[nl])
			{
				cout << "l = " << l << " nl = " << nl <<endl;
				++nl;
			}
			else
			{
				//还是这个思路是对的,但是当时想到的是往后走,而且也想过有可能往后移动,中间会有相同的,但是没想到是79行的实例......
				//l += nl;
				l = l - nl;
				nl = 0;
			}
			++l;
		}
        
		return (nl == nlen)?(l-nl):-1;
    }
};

int main(void)
{
	//string haystack = "hello", needle = "ll";
	//string haystack = "a", needle = "a";
	//string haystack = "aaaaa", needle = "bba";
	string haystack = "mississippi", needle = "issip";
	Solution f;
	cout << f.strStr(haystack, needle) << endl;
	return EXIT_SUCCESS;
}

