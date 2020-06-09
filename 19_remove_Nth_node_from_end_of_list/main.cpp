#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <limits.h>
#include <map>
#include <set>
#include <unordered_set>
#include <utility>
#include <vector>
#include <list>

using namespace std;

/*
	给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
	示例：
	给定一个链表: 1->2->3->4->5, 和 n = 2.
	当删除了倒数第二个节点后，链表变为 1->2->3->5.

	首先想到的就是由倒数转为正的:
	比如删除倒数第一个,长度为5,5-1=4,那么删除从正数,第4个(从0开始)-->但是不知道总长度
	遍历一遍放到map里面,然后下一个指针也知道了
*/

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
		map<int, ListNode*> map_list;
		int num = 0;
		ListNode *cur = head;
		while(cur != NULL)
		{
			map_list[num] = cur;
			++num;
			cur = cur->next;
		}
		num = num - n;
		if(num > 0)
		{
			map_list[num-1]->next = (map_list[num+1] == nullptr)?(nullptr):(map_list[num+1]);
			delete map_list[num];
		}
		else
		{
			//头
			head = (map_list[num+1] == nullptr)?(nullptr):(map_list[num+1]);
		}

		return head;
    }
};

int main(void)
{
	Solution f;
	ListNode *test = NULL, *pre = NULL, *temp;
	for(auto i = 0;i<5;i++)
	{
		temp = new ListNode(i+1);
		if(pre != NULL)
		{
			pre->next = temp;
			pre = temp;
		}
		if(test == NULL)
		{
			test = temp;
			pre = test;
		}
	}
	f.removeNthFromEnd(test, 2);
	temp = test;
	while(temp != NULL)
	{
		cout << "temp: " << temp->val << endl;
		temp = temp->next;
	}
	temp = test;
	while(temp != NULL)
	{
		test = temp->next;
		delete temp;
		temp = test;
	}
	return EXIT_SUCCESS;
}

