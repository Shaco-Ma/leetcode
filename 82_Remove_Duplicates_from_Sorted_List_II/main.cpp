#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>

using namespace std;

/*
给定一个已排序的链表的头 head ， 删除原始链表中所有重复数字的节点，只留下不同的数字 。返回 已排序的链表 。
示例 1：
输入：head = [1,2,3,3,4,4,5]
输出：[1,2,5]
示例 2：
输入：head = [1,1,1,2,3]
输出：[2,3]
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head)
	{
		ListNode *dump = new ListNode(0, head);
		ListNode *cur = head;
		ListNode *next = nullptr;
		if(cur != nullptr)
		{
			next = cur->next;
		}
		ListNode *pre = dump;
		while(cur != nullptr && next != nullptr)
		{
			cout << "pre = " << pre->val << ", cur = " << cur->val << ", " << next->val << endl;
			if(cur->val == next->val)
			{
				next = next->next;
			}
			else
			{
				if(cur->next != next)
				{
					pre->next = next;
				}
				else
				{
					pre = cur;
				}
				cur = next;
				next = next->next;
			}
			ListNode *back = dump->next;
			while(back != nullptr)
			{
				cout << back->val << ", ";
				back = back->next;
			}
			cout << endl;
		}
		return dump->next;
    }
};

int main(void)
{
	Solution s;
	ListNode *back = nullptr;
	ListNode *a2 = new ListNode(1);
	ListNode *b2 = new ListNode(1, a2);
	back = s.deleteDuplicates(b2);
	cout << "result: ";
	while(back != nullptr)
	{
		cout << back->val << ", ";
		back = back->next;
	}
	cout << endl;
	ListNode *a = new ListNode(5);
	ListNode *b = new ListNode(4, a);
	ListNode *c = new ListNode(4, b);
	ListNode *d = new ListNode(3, c);
	ListNode *e = new ListNode(3, d);
	ListNode *f = new ListNode(2, e);
	ListNode *g = new ListNode(1, f);
	back = s.deleteDuplicates(g);
	cout << "result: ";
	while(back != nullptr)
	{
		cout << back->val << ", ";
		back = back->next;
	}
	cout << endl;
	ListNode *a1 = new ListNode(3);
	ListNode *b1 = new ListNode(2, a1);
	ListNode *c1 = new ListNode(1, b1);
	ListNode *d1 = new ListNode(1, c1);
	ListNode *e1 = new ListNode(1, d1);
	back = s.deleteDuplicates(e1);
	cout << "result: ";
	while(back != nullptr)
	{
		cout << back->val << ", ";
		back = back->next;
	}
	cout << endl;
	return 1;
}

