#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

/*
给定一个候选人编号的集合 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
candidates 中的每个数字在每个组合中只能使用 一次 。
注意：解集不能包含重复的组合。 

示例 1:
输入: candidates = [10,1,2,7,6,1,5], target = 8,
输出:
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]

示例 2:
输入: candidates = [2,5,2,1,2], target = 5,
输出:
[
[1,2,2],
[5]
]
 
提示:
1 <= candidates.length <= 100
1 <= candidates[i] <= 50
1 <= target <= 30

思路：
	回溯,先从第一个元素开始,不断的用第一个元素进行尝试,到失败了,就返回前一次,用第二个元素尝试
	抄的,熟悉了解回溯
*/

using namespace std;

class Solution {
	private:
		vector<vector<int>> out;
		set<vector<int>> result;
		vector<int> path;
		int sum = 0;
		void dfs(vector<int> &candidates, int target, int sum, int idx)
		{
			cout << idx << endl;
			//add进来,尝试下一个,直到超过了,再返回,去掉
			if(sum == target)
			{
				result.insert(path);
				return;
			}
			for(int i = idx;i<candidates.size() && sum + candidates.at(i) <= target;i++)
			{
				//排序过的数据
				if(i>idx && candidates[i] == candidates[i -1])
				{
					continue;
				}
				sum += candidates.at(i);
				path.push_back(candidates.at(i));
				dfs(candidates, target, sum, i+1);
				path.pop_back();
				sum -= candidates.at(i);
			}
		};
	public:
		vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
		{
			out.clear();
			result.clear();
			path.clear();
			sum = 0;
			sort(candidates.begin(), candidates.end());
			dfs(candidates, target, sum, 0);
			out.assign(result.begin(), result.end());
			return out;
		}
};

int main(void)
{
	//vector<int> in = {10,1,2,7,6,1,5};
	vector<int> in = {
		1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1,
		1,1,1,1,1,1,1,1,1,1};
	//int target = 8;
	int target = 30;
	Solution test;
	vector<vector<int>> out = test.combinationSum2(in, target);
	for(auto item : out)
	{
		for(auto e:item)
		{
			cout << e << "	";
		}
		cout <<endl;
	}
};



