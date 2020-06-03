#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <limits.h>

using namespace std;
/*
   看了眼答案,双指针,一个从头,一个从尾,往中间移动
   数组最左端和最右端那个小移动哪一个
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
		int l = 0, r= height.size() - 1;
		int ret = 0;
		while(l < r)
		{
			ret = max(ret, min(height[l],height[r])*(r-l));
			(height[l] > height[r])?(r-=1):(l+=1);
			cout << "ret = " << ret << endl;
			cout << "l = " << l << " r = " << r << endl;
		}

		return ret;
    }
};

int main(void)
{
	vector<int> v_i = {1,8,6,2,5,4,8,3,7};
	Solution f;
	cout << f.maxArea(v_i) << endl;
}

