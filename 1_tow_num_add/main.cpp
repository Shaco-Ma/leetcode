#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> result;
    vector<int> twoSum(vector<int>& nums, int target) {
		for(int i= 0;i<nums.size();i++)
		{
			result.push_back(i);
			for(int j=i+1;j<nums.size();j++)
			{
				cout << "cur = " << nums.at(i) << " " << nums.at(j) << endl;
				if(nums.at(i) + nums.at(j) == target)
				{
					result.push_back(j);
					return result;
				}
			}
			result.pop_back();
		}
		return result;
    }
};

int main(void)
{
	//int target = 9;
	int target = -8;
	//vector<int> nums = {2,7,11,15};
	vector<int> nums = {-1,-2,-3,-4,-5};
	Solution test;
	vector<int> out = test.twoSum(nums, target);
	for(auto item:out)
	{
		cout << item<<endl;
	}
	return 0;
}

