#include <iostream>
#include <string>
#include <cstring>

using namespace std;

/*
   一条包含字母 A-Z 的消息通过以下映射进行了 编码 ：
   'A' -> "1"
   'B' -> "2"
   ...
   'Z' -> "26"
   要 解码 已编码的消息，所有数字必须基于上述映射的方法，反向映射回字母（可能有多种方法）。例如，"11106" 可以映射为：
   "AAJF" ，将消息分组为 (1 1 10 6)
   "KJF" ，将消息分组为 (11 10 6)
   注意，消息不能分组为  (1 11 06) ，因为 "06" 不能映射为 "F" ，这是由于 "6" 和 "06" 在映射中并不等价。
   给你一个只含数字的 非空 字符串 s ，请计算并返回 解码 方法的 总数 。
   题目数据保证答案肯定是一个 32 位 的整数。

   示例 1：
   输入：s = "12"
   输出：2
   解释：它可以解码为 "AB"（1 2）或者 "L"（12）。

   示例 2：
   输入：s = "226"
   输出：3
   解释：它可以解码为 "BZ" (2 26), "VF" (22 6), 或者 "BBF" (2 2 6) 。

   示例 3：
   输入：s = "06"
   输出：0
   解释："06" 无法映射到 "F" ，因为存在前导零（"6" 和 "06" 并不等价）。

   提示：
   1 <= s.length <= 100
   s 只包含数字，并且可能包含前导零。
   //想错了,应该用动态规划,每次都看下一个的时候前面有多少方法
*/

#if 1
class Solution {
	public:
		int numDecodings(string s)
		{
			int n = s.size();
			int funcs[n + 1];
			memset(funcs, 0, sizeof(funcs));
			funcs[0] = 1;
			for(int i=1;i<=n;i++)
			{
				if(s[i-1] != '0')
				{
					funcs[i] += funcs[i-1];
				}
				//再尝试取2个数
				if((i > 1) && s[i-2] != '0' && ((s[i-2]- '0')*10 + (s[i-1] - '0') <= 26))
				{
					funcs[i] += funcs[i-2];
				}
			}
			return funcs[n];
		}
};
#else
class Solution {
	public:
		void get_decode(string s, int index, int *result)
		{
			int num = 0;
			int size = s.size();
			if(s[index] == '0')
			{
				cout << endl;
				cout << "Wrong!" << endl;
				return;
			}
			if(index >= size)
			{
				cout << endl;
				cout << "Right!" << endl;
				(*result)++;
				return;
			}
			//先取一个数
			if(s[index] <= '9' && s[index] > '0')
			{
				get_decode(s, index+1, result);
			}
			//再尝试取2个数
			if((index < size - 1) && ((s[index] == '2' && s[index+1] >= '0' && s[index+1] <= '6') || (s[index] == '1' && s[index+1] >= '0' && s[index+1] <= '9')))
			{
				get_decode(s, index+2, result);
			}
		}
		int numDecodings(string s)
		{
			int result = 0;
			if(s[0] == '0')
				return 0;
			get_decode(s, 0, &result);
			return result;
		}
};
#endif

int main(void)
{
	Solution s;
	int ret = s.numDecodings("12");
	cout << "12 is " << ret << endl;
	ret = s.numDecodings("226");
	cout << "226 is " << ret << endl;
	ret = s.numDecodings("06");
	cout << "06 is " << ret << endl;
	ret = s.numDecodings("10");
	cout << "10 is " << ret << endl;
	ret = s.numDecodings("2611055971756562");
	cout << "2611055971756562 is " << ret << endl;
	ret = s.numDecodings("11111111111");
	cout << "111111111111111111111111111111111111111111111 is " << ret << endl;
	return 1;
}


