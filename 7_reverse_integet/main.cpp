#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <limits.h>

using namespace std;

class Solution {
public:
    int reverse(int x) {
		int rev = 0;
		while(x != 0)
		{
			//取最后一位
			int pop = x%10;
			x /= 10;
			//越界问题
			if(rev > INT_MAX/10 || (rev == INT_MAX/10 && pop > INT_MAX%10))
				return 0;
			if(rev < INT_MIN/10 || (rev == INT_MIN/10 && pop < INT_MIN%10))
				return 0;
			rev = rev*10 + pop;
		}

		return rev;
    }
};

int main(void)
{
	Solution f;
	cout << INT_MAX%10 << endl;
	cout << INT_MIN%10 << endl;
	cout << dec << f.reverse(-2147483648) << endl;
	return EXIT_SUCCESS;
}

