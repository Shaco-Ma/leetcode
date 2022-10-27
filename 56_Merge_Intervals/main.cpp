#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*
   以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。
   示例 1：
   输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
   输出：[[1,6],[8,10],[15,18]]
   解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
   示例 2：
   输入：intervals = [[1,4],[4,5]]
   输出：[[1,5]]
   解释：区间 [1,4] 和 [4,5] 可被视为重叠区间。
   //思路
   //查找每一个数组的第二个数是不是在下一个的数组的区间内,是的话,max第一个数组的第二个元素和第二个数组的第二个元素,再进行同样的操作
   如果不在了,就输出第一个数组,接着找下一个数组
*/

class Solution {
public:
	vector<vector<int>> result;
	vector<int> temp;
	void get(int first, int size, int check_num, vector<vector<int>>& intervals)
	{
		if(first >= size-1)
		{
			temp.push_back(check_num);
			result.push_back(temp);
			return;
		}
		if(check_num < intervals.at(first+1).at(0))
		{
			//插入
			temp.push_back(check_num);
			result.push_back(temp);
			temp.clear();
			temp.push_back(intervals.at(first+1).at(0));
			get(first+1, size, intervals.at(first+1).at(1), intervals);
		}
		else
		{
			check_num = max(check_num, intervals.at(first+1).at(1));
			get(first+1, size, check_num, intervals);
		}
	}
    vector<vector<int>> merge(vector<vector<int>>& intervals)
	{
		result.clear();
		int cur = 0;
		int size = intervals.size();
		temp.clear();
		sort(intervals.begin(), intervals.end());
		temp.push_back(intervals.at(0).at(0));
		get(0, size, intervals.at(0).at(1), intervals);
		return result;
    }
};

int main(void)
{
	vector<vector<int>> num = {{1,3},{2,6},{8,10},{15,18}};
	vector<vector<int>> num1 = {{1,7},{2,6},{8,10},{9,18}};
	vector<vector<int>> num2 = {{1,7},{4,18}};
	vector<vector<int>> num3 = {{1,7},{0,7}};
	vector<vector<int>> num4 = {{1,7},{0,9}};
	vector<vector<int>> num5 = {{1,7},{0,0}};
	Solution s;
	vector<vector<int>> back = s.merge(num);
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
	back = s.merge(num1);
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
	back = s.merge(num2);
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
	back = s.merge(num3);
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
	back = s.merge(num4);
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
	return 1;
}

