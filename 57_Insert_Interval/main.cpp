#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*
	给你一个 无重叠的 ，按照区间起始端点排序的区间列表。
	在列表中插入一个新的区间，你需要确保列表中的区间仍然有序且不重叠（如果有必要的话，可以合并区间）。
	示例 1：
	输入：intervals = [[1,3],[6,9]], newInterval = [2,5]
	输出：[[1,5],[6,9]]
	示例 2：
	输入：intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
	输出：[[1,2],[3,10],[12,16]]
	解释：这是因为新的区间 [4,8] 与 [3,5],[6,7],[8,10] 重叠。
	示例 3：
	输入：intervals = [], newInterval = [5,7]
	输出：[[5,7]]
	示例 4：
	输入：intervals = [[1,5]], newInterval = [2,3]
	输出：[[1,5]]
	示例 5：
	输入：intervals = [[1,5]], newInterval = [2,7]
	输出：[[1,7]]
//思路
//先插入,排序找到第一个位置,插入
*/

class Solution {
public:
	vector<vector<int>> result;
	vector<int> temp;
	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)
	{
		result.clear();
		//先插入,再排序,再合并吧
		intervals.push_back(newInterval);
		sort(intervals.begin(), intervals.end());
		int size = intervals.size();
		temp = intervals.at(0);
		for(auto i=1;i<size;i++)
		{
			if(temp.at(1)  < intervals.at(i).at(0))
			{
				//单独插入
				result.push_back(temp);
				temp = intervals.at(i);
			}
			else
			{
				//合并
				temp.at(0) = min(temp.at(0), intervals.at(i).at(0));
				temp.at(1) = max(temp.at(1), intervals.at(i).at(1));
			}
		}
		result.push_back(temp);
		return result;
    }
};

int main(void)
{
	vector<vector<int>> num = {{1,3},{6,9}};
	vector<int> insert = {2, 5};
	vector<vector<int>> num1 = {{1,2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
	vector<int> insert1 = {2, 5};
	vector<vector<int>> num2 = {};
	vector<int> insert2 = {5, 7};
	vector<vector<int>> num3 = {{1,5}};
	vector<int> insert3 = {2, 3};
	vector<vector<int>> num4 = {{1,5}};
	vector<int> insert4 = {2, 7};
	Solution s;
	vector<vector<int>> back = s.insert(num, insert);
	cout << "result:" << endl;
	for(auto itme:back)
	{
		for(auto every:itme)
		{
			cout << every << endl;
		}
		cout << endl;
	}
	back.clear();
	back = s.insert(num1, insert1);
	cout << "result:" << endl;
	for(auto itme:back)
	{
		for(auto every:itme)
		{
			cout << every << endl;
		}
		cout << endl;
	}
	back.clear();
	back = s.insert(num2, insert2);
	cout << "result:" << endl;
	for(auto itme:back)
	{
		for(auto every:itme)
		{
			cout << every << endl;
		}
		cout << endl;
	}
	back.clear();
	back = s.insert(num3, insert3);
	cout << "result:" << endl;
	for(auto itme:back)
	{
		for(auto every:itme)
		{
			cout << every << endl;
		}
		cout << endl;
	}
	back.clear();
	back = s.insert(num4, insert4);
	cout << "result:" << endl;
	for(auto itme:back)
	{
		for(auto every:itme)
		{
			cout << every << endl;
		}
		cout << endl;
	}
#if 0
	back.clear();
	back = s.merge(num5);
	cout << "result:" << endl;
	for(auto itme:back)
	{
		for(auto every:itme)
		{
			cout << every << endl;
		}
		cout << endl;
	}
#endif
	return 1;
}

