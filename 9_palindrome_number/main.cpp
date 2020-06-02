#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <limits.h>

using namespace std;

/*
   翻转num试试?貌似会有越界的问题
   直接对比位,要找到中间位
*/

class Solution {
public:
    bool isPalindrome(int x) {
		bool ret = true;
		int bits = 0, old_bits = 0;
		int rev = x;
		if(x < 0)
		{
			return false;
		}
		else if(x == 0)
			return ret;
		while(x != 0)
		{
			x /= 10;
			bits++;
		}
		//cout << "bits = " << bits << endl;
		old_bits = bits;
		bits /= 2;
		x = rev;
		while(bits >= 0)
		{
			rev = x/pow(10, (old_bits - 1));
			//cout << "rev = " << rev << endl;
			//cout << "x%10 = " << x%10 << endl;
			if(rev == x%10)
			{
				ret = true;
				x -= rev*pow(10, (old_bits - 1));
				x /= 10;
			}
			else
			{
				ret = false;
				break;
			}
			old_bits -= 2;
			bits--;
		}

		return ret;
    }
};

int main(void)
{
	Solution f;
	cout << f.isPalindrome(1234554321) << endl;;
	return EXIT_SUCCESS;
}

