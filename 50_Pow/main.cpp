#include <iostream>

using namespace std;

class Solution {
public:
	double result = 1;
	double pow(double x, long long n)
	{
#if 1
		double temp = 1;
		while(n>0)
		{
			if(n&0x01)
			{
				temp *= x;
			}
			x *= x;
			n >>= 1;
		}
		return temp;
#else
		if(n == 0)
		{
			return 1;
		}
		else if((n % 2) == 1)
		{
			return pow(x, n-1) * x;
		}
		else
		{
			double temp = pow(x, n/2);
			return temp * temp;
		}
#endif
	}
    double myPow(double x, long long n)
	{
		if(n == 0)
		{
			return 1;
		}
		else if(n > 0)
		{
			result = pow(x, n);
		}
		else
		{
			result = pow(x, 0-n);
			result = 1/result;
		}
		return result;
    }
};

int main(void)
{
	Solution s;
	cout << s.myPow(2, 5) << endl;
	return 1;
}


