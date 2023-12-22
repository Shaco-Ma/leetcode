#include <iostream>

/*
   给你一个链表的头节点 head 和一个特定值 x ，请你对链表进行分隔，使得所有 小于 x 的节点都出现在 大于或等于 x 的节点之前。

   你应当 保留 两个分区中每个节点的初始相对位置。
   //只动符合的节点
   示例 1：
   输入：head = [1,4,3,2,5,2], x = 3
   输出：[1,2,2,4,3,5]

   示例 2：
   输入：head = [2,1], x = 2
   输出：[1,2]

   //第一反应就是找到尾节点,双向往前
   //出现在 大于或等于x的节点之前,应该不需要排序吧?
   //发现还是要从前面往后移动
*/

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
	void print_list(void)
	{
		ListNode *cur = this;
		while(cur)
		{
			cout << "cur->val = " << cur->val << endl;
			cur = cur->next;
		}
	}
};

class Solution {
	public:
		ListNode* partition(ListNode* head, int x) {
			ListNode *cur = head;
			ListNode *insert = new ListNode(0, head);
			ListNode *new_head = insert;
			ListNode *temp_node = nullptr;
			//先找到大于等于X的节点位置
			while(insert->next)
			{
				if(insert->next->val >= x)
				{
					break;
				}
				insert = insert->next;
			}
			cur = insert;
			//从这个节点的前一个节点开始,往后找小于X的节点
			while(cur && cur->next)
			{
				cout << "cur->next->val = " << cur->next->val << endl;
				if(cur->next->val < x)
				{
					temp_node = cur->next->next;
					//把next节点放到insert后面
					cur->next->next = insert->next;
					insert->next = cur->next;
					cur->next = temp_node;
					insert = insert->next;
					head->print_list();
					continue;
				}
				cur = cur->next;
			}
			return new_head->next;
		}
};

int main(void)
{
	Solution s;
	ListNode *back = nullptr;
	ListNode *a2 = new ListNode(2, nullptr);
	ListNode *b2 = new ListNode(5, a2);
	ListNode *b3 = new ListNode(2, b2);
	ListNode *b1 = new ListNode(0, b3);
	ListNode *b4 = new ListNode(3, b1);
	ListNode *b5 = new ListNode(4, b4);
	ListNode *b6 = new ListNode(1, b5);
	back = b6;
	cout << "old: ";
	while(back != nullptr)
	{
		cout << back->val << ", ";
		back = back->next;
	}
	cout << endl;
	back = s.partition(b6, 3);
	cout << "result: ";
	while(back != nullptr)
	{
		cout << back->val << ", ";
		back = back->next;
	}
	cout << endl;
	ListNode *f = new ListNode(1);
	ListNode *g = new ListNode(2, f);
	back = g;
	cout << "old: ";
	while(back != nullptr)
	{
		cout << back->val << ", ";
		back = back->next;
	}
	cout << endl;
	back = s.partition(g, 2);
	cout << "result: ";
	while(back != nullptr)
	{
		cout << back->val << ", ";
		back = back->next;
	}
	cout << endl;
	return 1;
}

