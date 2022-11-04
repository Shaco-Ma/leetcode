#include <iostream>
#include <vector>

using namespace std;

/*
	给你一个链表的头节点 head ，旋转链表，将链表每个节点向右移动 k 个位置。
	示例 1：
	输入：head = [1,2,3,4,5], k = 2
	输出：[4,5,1,2,3]
	示例 2：
	输入：head = [0,1,2], k = 4
	输出：[2,0,1]
	//思路
	直接从新遍历到vector里面,重建链表
*/


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
	public:
		ListNode* rotateRight(ListNode* head, int k)
		{
			int size = 0;
			vector<int> temp;
			ListNode *tail = head, *node = nullptr;
			while(tail != nullptr)
			{
				temp.push_back(tail->val);
				node = tail;
				tail = tail->next;
				delete node;
			}
			tail = nullptr;
			size = temp.size();
			if(size == 0)
                return nullptr;
			k = k%size;
			for(auto i=(size-k-1);i>=0;i--)
			{
				node = new ListNode(temp.at(i), nullptr);
				if(tail != nullptr)
				{
					node->next = tail;
					tail = node;
				}
				else
				{
					tail = node;
				}
			}
			for(auto i=size-1;i>=(size-k);i--)
			{
				node = new ListNode(temp.at(i), nullptr);
				if(tail != nullptr)
				{
					node->next = tail;
					tail = node;
				}
				else
				{
					tail = node;
				}
			}
			return tail;
		}
};

int main(void)
{
	vector<int> temp{1,2,3,4,5};
	ListNode *head = nullptr, *tail = nullptr;
	for(int i=temp.size()-1;i>=0;i--)
	{
		tail = new ListNode(temp.at(i), nullptr);
		if(head == nullptr)
		{
			head = tail;
		}
		else
		{
			tail->next = head;
			head = tail;
		}
	}
	Solution s;
	head = s.rotateRight(head, 2);
	while(head != nullptr)
	{
		cout << head->val << "  ";
		head= head->next;
	}
	cout << endl;
	return 1;
}

