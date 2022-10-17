#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> result;
	vector<int> path;
	void backtracking(vector<int>& nums, vector<int> &path, vector<int> &isIn)
	{
		if(path.size() == nums.size())
		{
			result.push_back(path);
			return;
		}
		for(int i=0;i<nums.size();i++)
		{
			if(isIn.at(i) == 1)
				continue;
			isIn.at(i) = 1;
			path.push_back(nums.at(i));
			backtracking(nums, path, isIn);
			path.pop_back();
			isIn.at(i) = 0;
		}
	}
    vector<vector<int>> permute(vector<int>& nums)
	{
		vector<int> isIn(nums.size(), 0);
		backtracking(nums, path, isIn);
		return result;
    }
};

int main(void)
{
	vector<int> nums = {1, 2, 3};
	Solution s;
	vector<vector<int>> back;
	back = s.permute(nums);
	cout << "Result: " << endl;
	for(auto item:back)
	{
		for(auto i:item)
		{
			cout << i << " ";
		}
		cout << endl;
	}
}
