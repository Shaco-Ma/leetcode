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
   一次遍历每个元素,那个小,那个往后移动,相等都移动,直到两个都是空的
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
#if 1
		//递归
		if(l1 == nullptr)
		{
			return l2;
		}
		else if(l2 == nullptr)
		{
			return l1;
		}
		if(l1->val < l2->val)
		{
			l1->next = mergeTwoLists(l1->next, l2);
			return l1;
		}
		else
		{
			l2->next = mergeTwoLists(l1, l2->next);
			return l2;
		}
#else
		//可以优化的地方,任何一个为空,那么就把这个非空的给到结尾
		ListNode *head = nullptr, *next = nullptr, *ret = nullptr;
		while(l1 != nullptr || l2 != nullptr)
		{
			if(l1 != nullptr && l2 != nullptr)
			{
				if(l1->val < l2->val)
				{
					next = l1;
					l1 = l1->next;
				}
				else
				{
					next = l2;
					l2 = l2->next;
				}
			}
			else if(l1 == nullptr)
			{
				next = l2;
				l2 = l2->next;
			}
			else
			{
				next = l1;
				l1 = l1->next;
			}
			//cout << "next->val = " << next->val << endl;
			if(head == nullptr)
			{
				head = next;
				ret = head;
			}
			else
			{
				head->next = next;
				head = head->next;
			}
		}
		head = ret;
		/*cout << "head: ";
		while(head != nullptr)
		{
			cout << head->val << "	";
			head = head->next;
		}
		cout << endl;*/

		return ret;
#endif
    }
};

int main(void)
{
	Solution f;
	ListNode *test = nullptr, *test1 = nullptr;
	test = new ListNode(4);
	test = new ListNode(2, test);
	test = new ListNode(1, test);
	test1 = new ListNode(3);
	test1 = new ListNode(3, test1);
	test1 = new ListNode(1, test1);
	test = f.mergeTwoLists(test, test1);
	test1= test;
	while(test != nullptr)
	{
		cout << test->val << endl;
		test = test->next;
	}
	/*test = test1;
	while(test != nullptr)
	{
		test1 = test;
		test = test->next;
		delete test1;
	}*/
	return EXIT_SUCCESS;
}

