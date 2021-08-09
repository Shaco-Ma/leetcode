#include <iostream>
#include <string>
#include <algorithm>

/*
   给定一个正整数 n ，输出外观数列的第 n 项。
   「外观数列」是一个整数序列，从数字 1 开始，序列中的每一项都是对前一项的描述。
   你可以将其视作是由递归公式定义的数字字符串序列：
   countAndSay(1) = "1"
   countAndSay(n) 是对 countAndSay(n-1) 的描述，然后转换成另一个数字字符串。
   前五项如下：
   1.     1
   2.     11
   3.     21
   4.     1211
   5.     111221
   第一项是数字 1
   描述前一项，这个数是 1 即 “ 一 个 1 ”，记作 "11"
   描述前一项，这个数是 11 即 “ 二 个 1 ” ，记作 "21"
   描述前一项，这个数是 21 即 “ 一 个 2 + 一 个 1 ” ，记作 "1211"
   描述前一项，这个数是 1211 即 “ 一 个 1 + 一 个 2 + 二 个 1 ” ，记作 "111221"
   要 描述 一个数字字符串，首先要将字符串分割为 最小 数量的组，每个组都由连续的最多 相同字符 组成。
   然后对于每个组，先描述字符的数量，然后描述字符，形成一个描述组。要将描述转换为数字字符串，先将每组中的字符数量用数字替换，再将所有描述组连接起来。
   示例 1：
   输入：n = 1
   输出："1"
   解释：这是一个基本样例。
   示例 2：
   输入：n = 4
   输出："1211"
   解释：
   countAndSay(1) = "1"
   countAndSay(2) = 读 "1" = 一 个 1 = "11"
   countAndSay(3) = 读 "11" = 二 个 1 = "21"
   countAndSay(4) = 读 "21" = 一 个 2 + 一 个 1 = "12" + "11" = "1211"
   提示：
   1 <= n <= 30


   //递归往前查找,然后根据返回值,进行遍历
   比如1211,因为第一个字符和第二个不一样,所以push 1,和第一个字符,移动到第二个字符,push 1 和第二个字符,第三个字符发现和第四个一样,计数++,push 2 和"1"
   就是111221
*/

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
		string ret, out;
		int num = 1;
		if(n == 1)
		{
			return "1";
		}
		else
		{
			ret = countAndSay(n-1);
			num = 1;
			for(int i=0;i<ret.size();i++)
			{
				if(i == ret.size())
				{
					out.push_back(to_string(num)[0]);
					out.push_back(ret[i]);
				}
				else if(ret[i] == ret[i+1])
				{
					num++;
				}
				else
				{
					//不可能有大于9的数
					out.push_back(to_string(num)[0]);
					out.push_back(ret[i]);
					num = 1;
				}
			}
			return out;
		}
    }
};

int main(void)
{
	class Solution s;
	int n = 0;
	while(1)
	{
		cin >> n;
		if(n == 999)
			break;
		cout << s.countAndSay(n) << endl;
	}
}



