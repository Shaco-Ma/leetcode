#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

/*
   给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。
   k 是一个正整数，它的值小于或等于链表的长度。
   如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
   输入：head = [1,2,3,4,5], k = 2
   输出：[2,1,4,3,5]

   输入：head = [1,2,3,4,5], k = 3
   输出：[3,2,1,4,5]

   输入：head = [1,2,3,4,5], k = 1
   输出：[1,2,3,4,5]

   输入：head = [1], k = 1
   输出：[1]
   进阶：
   你可以设计一个只使用常数额外空间的算法来解决此问题吗？
   你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。

   //看了答案,感觉用栈方式比较好,比如读取k个值放到vector里面,然后反向读出
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
    ListNode* reverseKGroup(ListNode* head, int k) {
		vector<ListNode *> stack;
		int i = 0;
		ListNode *NewHead = nullptr, *NextHead = nullptr, *temphead = nullptr, *cur_head = nullptr;
		if(k == 1)
		{
			return head;
		}
		else
		{
			while(head != NULL)
			{
				cur_head = head;
				//cout << "cur_head.val = " << cur_head->val << ", cur_head addr = " << cur_head << endl;
				for(i=0;i<k;i++)
				{
					stack.push_back(head);
					head = head->next;
					if(head == nullptr)
					{
						break;
					}
				}
				if(stack.size() != k)
				{
					if(temphead == nullptr)
					{
						temphead = cur_head;
					}
					else
					{
						NewHead->next = cur_head;
					}
					break;
				}
				else
				{
					//创建新的节点
					for(i=k-1;i>=0;i--)
					{
						if(temphead == NULL)
						{
							temphead = stack.at(i);
							NewHead = temphead;
						}
						else
						{
							NewHead->next = stack.at(i);
							NewHead->next->next = nullptr;
							NewHead = NewHead->next;
						}
					}
				}
				stack.clear();
			}
			return temphead;
		}
    }
};

int main(int argv, char *argc[])
{
	class Solution s;
	ListNode *head, *list = nullptr, *temp = nullptr;
	for(int i =0;i<10;i++)
	{
		temp = new ListNode(i);
		//cout << "temp.val = " << temp->val << ", temp addr = " << temp << endl;
		if(list == nullptr)
		{
			list = temp;
			head = list;
		}
		else
		{
			list->next = temp;
			list = list->next;
		}
	}
	list = head;
	while(head != nullptr)
	{
		cout << "head.val = " << head->val << ", head addr = " << head << endl;
		head = head->next;
	}
	cout << endl;
	cout << endl;
	head = s.reverseKGroup(list, 11);
	while(head != nullptr)
	{
		cout << "head.val = " << head->val << ", head addr = " << head << endl;
		head = head->next;
	}
	return 1;
}

