#include <iostream>
#include <vector>

using namespace std;

/*
   记录一个数a的最大下标能到的地方b
   如果下一个数c的是否在b的范围内(理论上一定在的),在的话就更新最大下标能到的地方b1
   取b1和b的最大值
*/

class Solution
{
	public:
		bool canJump(vector<int>& nums)
		{
			int maxpos = nums.at(0);
			int size = nums.size();
			for(auto i=0;i<size;i++)
			{
				if(i <= maxpos)
				{
					maxpos = max(maxpos, nums.at(i) + i);
					if(maxpos >= size-1)
						return true;
				}
			}
			return false;
		}
};

int main(void)
{
	vector<int> num1 = {2,3,1,1,4};
	vector<int> num2 = {3,2,1,0,4};
	vector<int> num3 = {0};
	vector<int> num4 = {1,2,3};
	Solution s;
	cout << s.canJump(num1) << endl;
	cout << s.canJump(num2) << endl;
	cout << s.canJump(num3) << endl;
	cout << s.canJump(num4) << endl;
	return 1;
}

