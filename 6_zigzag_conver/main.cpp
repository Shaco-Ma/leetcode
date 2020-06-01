#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

/*
按行存储
需要一个set,存储当前已经读取过得字符,如果该字符读取过,那么就读取的字符+1
//第n行的第m个数,从字符串里面读取第
				r
PAYPALISHIRING	3

P   A   H   N
A P L S I I G
Y   I   R

PAYPALISHIRING	4

P     I    N
A   L S  I G
Y A   H R
P     I
第1行,第1个数是0
第1行,第2个数是(2r-2)*m,当超过字符串长度之后结束
第2行,第一个数是1,因为第0个字符已经使用
第2行,第2个数是n, (2r-2)*(m/2)+r, (2r-2)*(m/2)+n

除了第1行和最后一行
其他行都是(2r-2)*(m/2)+n, (2r-2)*(m/2)+r, (2r-2)*(m/2)+n, (2r-2)*(m/2)+r,以此类推

*/

class Solution {
public:
    string convert(string s, int numRows) {
		int set_num = 0;
		int get_num;
		int all_rows = 0;
		int rows_offset = 0;
		new_s.clear();
		while(1)
		{
			get_num = ((numRows-1)<<1)*rows_offset;
			if(get_num >= s.size())
				break;
			new_s.push_back(s.at(get_num));
			rows_offset++;
		}
		all_rows++;
		while(all_rows < (numRows-1))
		{
			rows_offset = 0;
			while(1)
			{
				if((rows_offset & 1) != 0)
				{
					get_num = ((numRows-1)<<1)*(rows_offset>>1) + ((numRows-1)<<1) - all_rows;
				}
				else
				{
					get_num = ((numRows-1)<<1)*(rows_offset>>1) + all_rows;
				}
				if(get_num >= s.size())
					break;
				new_s.push_back(s.at(get_num));
				rows_offset++;
			}
			all_rows++;
		}
		rows_offset = 0;
		while(1)
		{
			get_num = ((numRows-1)<<1)*rows_offset + numRows - 1;
			if(get_num >= s.size())
				break;
			new_s.push_back(s.at(get_num));
			rows_offset++;
		}
		return new_s;
    }
private:
	string new_s;
};

int main(void)
{
	string s_in("PAYPALISHIRING");
	cout << s_in.size() << endl;
	int n = 3;
	Solution s_z_con;
	cout << s_z_con.convert(s_in, n) << endl;
	return EXIT_SUCCESS;
}
