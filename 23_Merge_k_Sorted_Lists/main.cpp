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
#include <stack>
#include <random>
#include <queue>

using namespace std;

//#define USE_SET

typedef enum
{
	AAA,
	AAAA,
	AAAAA,
	AAAAAA,
	AAAAAAA,
}TEST_NUME;

#if defined USE_SET
class ListNode{
	public:
	bool operator < (const ListNode &rhs) const {
		cout <<"111"<<endl;
		return val < rhs.val;
	}
	friend bool operator < (const ListNode & lhs, const ListNode &rhs) {
		cout <<"222"<<endl;
		return lhs.val < rhs.val;
	}
	int val;
	ListNode *next;
	ListNode():val(0), next(nullptr){}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};
#else
struct ListNode {
	int val;
	ListNode *next;
	ListNode():val(0), next(nullptr){}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
	bool operator < (const ListNode &rhs) const {
		cout << "333" << endl;
		return val > rhs.val;
	}
};
#endif

/*
	合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。
	示例:
	输入:
	[
	  1->4->5,
	  1->3->4,
	  2->6
	]
	输出: 1->1->2->3->4->4->5->6
	//先按照从数量从小到大排列?
	//每次取第一个合并链表?
	//做一个map,记录每一个相同的最后一个
	//然后继续查找下一列
	2->6
	1->3->5
	1->3->4
	先找2,1,1,组成列表1->1->2
	map 1, 是第二个1,
	map 2, 是2对应的地方
	记录当前最大是2
	再找6,3,3,跟1->1->2对比,map 6为空,所以链表变成1->1->2->6
	map 1, 是第二个1,
	map 2, 是2对应的地方
	map 6, 是6对应的
	当前最大是6
	然后map3是空的,那么就跟最大的比较,map3<map6,那么map2(因为是链表中的最后一个)指向map3,map3指向map6,
	再有一个3,map3不为空,那么更新map3为新的map3,同时把之前map3指向的next换成新的map3,新的map3指向map6
	//当发现某一个链表为空的时候,遍历的起始链表位置+1
	//因为是链表没办法找长度,所以记录当vector的某一个head为空的时候,continue

	//感觉答案给的很有意思啊,定义一个 priority_queue,其实很多有序容器都可以吧,我在想 mulitset 行不
	只要是有序容器,可以删除第一个的,应该是都可以的,但是multiset,重载了 < 但是貌似不行
*/

#if defined USE_SET
class Solution {
	public:
	multiset<ListNode *> q;
    ListNode* mergeKLists(vector<ListNode*>& lists) {
		ListNode head, *tail = &head;
		for(auto node: lists) {
			//把头结点放到 优先级queue里面
			if (node) q.insert(node);
		}
		while(!q.empty())
		{
			//每次读取第一个指针,并且erase第一个
			auto f = *q.begin();
			cout << f->val << endl;
			tail->next = f;
			tail = tail->next;
			q.erase(q.begin());
			if(f->next)
			{
				q.insert(f->next);
			}
		}
		return head.next;
	}
};
#else
class Solution {
public:
	struct Status {
        int val;
        ListNode *ptr;
        bool operator < (const Status &rhs) const {
            return val > rhs.val;
        }
    };
    priority_queue <Status> q;
	static bool compare_lists(ListNode *l, ListNode *r)
	{
		return l->val > r->val;
	}
    ListNode* mergeKLists(vector<ListNode*>& lists) {
		ListNode head, *tail = &head;
		for(auto node: lists) {
			//把头结点放到 优先级queue里面
			if (node) q.push({node->val, node});
		}
		while(!q.empty())
		{
			//每次取最小的,大小排序根据 status 的 operator < 比较,这里面只有三个,每次都从弹出的那个取下一个
			auto f = q.top();
			q.pop();
			tail->next = f.ptr;
			tail = tail->next;
			if(f.ptr->next)
			{
				q.push({f.ptr->next->val, f.ptr->next});
			}
		}
		return head.next;
    }
};
#endif

int main(void)
{
	vector<ListNode *> list;
	ListNode *test = nullptr;
	test = new ListNode(5);
	test = new ListNode(4, test);
	test = new ListNode(1, test);
	list.push_back(test);
	test = nullptr;
	test = new ListNode(4);
	test = new ListNode(3, test);
	test = new ListNode(1, test);
	list.push_back(test);
	test = nullptr;
	test = new ListNode(6);
	test = new ListNode(2, test);
	list.push_back(test);
	Solution f;
	test = f.mergeKLists(list);
	ListNode *temp = test;
	while(test != nullptr)
	{
		cout << "Result:" << test->val << endl;
		test = test->next;
	}
	cout << "This is delete" << endl;
	test = temp;
	while(test != nullptr)
	{
		cout << "test: " << test->val << endl;
		temp = test;
		test = test->next;
		cout << temp->val << endl;
		delete temp;
	}
	return EXIT_SUCCESS;
}

