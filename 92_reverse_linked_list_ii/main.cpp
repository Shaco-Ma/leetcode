#include <iostream>

using namespace std;

/*
 给你单链表的头指针 head 和两个整数 left 和 right ，其中 left <= right 。请你反转从位置 left 到位置 right 的链表节点，返回 反转后的链表 。

 示例 1：
 输入：head = [1,2,3,4,5], left = 2, right = 4
 输出：[1,4,3,2,5]

 示例 2：
 输入：head = [5], left = 1, right = 1
 输出：[5]

 提示：
 链表中节点数目为 n
 1 <= n <= 500
 -500 <= Node.val <= 500
 1 <= left <= right <= n

 进阶： 你可以使用一趟扫描完成反转吗？
 //双指针?双指针要扫描两次啊
 娘的,理解错了,这个left 和 right 是指位置
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
		ListNode* reverseBetween(ListNode* head, int left, int right)
		{
			//先找到顺序
			//运行次数
			int count = (right - left + 1)/2;
			ListNode *l = head, *r = nullptr;
			int offset = right - left;
			while(left-- > 1)
			{
				l = l->next;
			}
			while(count--)
			{
				//找到r的位置,从l开始往后运行right- left次
				r = l;
				for(int i=0;i<offset;i++)
				{
					r = r->next;
				}
				swap(l->val, r->val);
				offset -= 2;
				l = l->next;
			}
			return head;
		}
};

int main()
{
	Solution s;
	ListNode *a = new ListNode(5);
	ListNode *a1 = new ListNode(4, a);
	ListNode *a2 = new ListNode(3, a1);
	ListNode *a3 = new ListNode(2, a2);
	ListNode *a4 = new ListNode(1, a3);
	ListNode *head = a4;
	while(head != nullptr)
	{
		cout << head->val << "  ";
		head = head->next;
	}
	cout << endl;
	head = a4;
	s.reverseBetween(head, 2, 4);
	//s.reverseBetween(head, 1, 4);
	//s.reverseBetween(head, 1, 2);
	cout << "new:" << endl;
	while(head != nullptr)
	{
		cout << head->val << "  ";
		head = head->next;
	}
	cout << endl;
	return 1;
}

