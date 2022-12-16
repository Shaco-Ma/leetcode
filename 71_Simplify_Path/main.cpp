#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
给你一个字符串 path ，表示指向某一文件或目录的 Unix 风格 绝对路径 （以 '/' 开头），请你将其转化为更加简洁的规范路径。
在 Unix 风格的文件系统中，一个点（.）表示当前目录本身；此外，两个点 （..） 表示将目录切换到上一级（指向父目录）；两者都可以是复杂相对路径的组成部分。任意多个连续的斜杠（即，'//'）都被视为单个斜杠 '/' 。 对于此问题，任何其他格式的点（例如，'...'）均被视为文件/目录名称。
请注意，返回的 规范路径 必须遵循下述格式：
始终以斜杠 '/' 开头。
两个目录名之间必须只有一个斜杠 '/' 。
最后一个目录名（如果存在）不能 以 '/' 结尾。
此外，路径仅包含从根目录到目标文件或目录的路径上的目录（即，不含 '.' 或 '..'）。
返回简化后得到的 规范路径 。
示例 1：
输入：path = "/home/"
输出："/home"
解释：注意，最后一个目录名后面没有斜杠。
示例 2：
输入：path = "/../"
输出："/"
解释：从根目录向上一级是不可行的，因为根目录是你可以到达的最高级。
示例 3：
输入：path = "/home//foo/"
输出："/home/foo"
解释：在规范路径中，多个连续斜杠需要用一个斜杠替换。
示例 4：
输入：path = "/a/./b/../../c/"
输出："/c"
//从前往后遍历,每个字母都保存到string里面,遇到/就结束保存,/不存储
//如果当前的字符串是.就抛弃,如果是..就从数组pop最后一个,其他的都push到数组
*/

class Solution {
public:
    string simplifyPath(string path)
	{
		string every;
		vector<string> all;
		all.clear();
		int len = path.size();
		every.clear();
		for(int i=0;i<len;i++)
		{
			if(path.at(i) == '/')
			{
				//判断every是什么
				if(every.size() == 0)
					continue;
				//cout << "every = " << every << endl;
				if(every == ".")
				{
					every.clear();
				}
				else if(every == "..")
				{
					if(all.size() > 0)
						all.pop_back();
					every.clear();
				}
				else
				{
					all.push_back(every);
					every.clear();
				}
				continue;
			}
			every.push_back(path.at(i));
		}
		if(every.size() > 0)
		{
			if(every == "..")
			{
				if(all.size() > 0)
					all.pop_back();
			}
			else if(every != ".")
			{
				all.push_back(every);
			}
		}
		every.clear();
		for(auto item:all)
		{
			every.push_back('/');
			copy(item.begin(), item.end(), back_inserter(every));
		}
		if(every.size() == 0)
			every.push_back('/');
		return every;
    }
};

int main(void)
{
	Solution s;
	cout << "result:" << s.simplifyPath("/home/") << endl;
	cout << "result:" << s.simplifyPath("/../") << endl;
	cout << "result:" << s.simplifyPath("/home//foo/") << endl;
	cout << "result:" << s.simplifyPath("/a/./b/../../c/") << endl;
	cout << "result:" << s.simplifyPath("/a//b////c/d//././/..") << endl;
	return 1;
}

