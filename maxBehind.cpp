#include<iostream>
using namespace std;
class ListNode{
	public:
		int val;
		ListNode* next;
		ListNode(int val){
			this->val=val;
			this->next=nullptr;
		}
};
ListNode* maxBehind(ListNode* head){
	ListNode*next;
	ListNode* p=head;
	ListNode* q;
	ListNode* pre=nullptr;
	while(p->next!=nullptr){
		q=p->next;
		if(p->val>q->val){
			next=q->next;
			q->next=p;
			p->next=next;
			if(pre==nullptr){
				head=q;
			}else{
				pre->next=q;
			}
		}else{
			p=p->next;
		}
	}
	return head;
}
void printList(ListNode* head){
	ListNode* p=head;
	while(p!=nullptr){
		cout<<p->val<<" ";
		p=p->next;
	}
	cout<<endl;
}
int main(){
	ListNode* head=new ListNode(3);
	head->next=new ListNode(1);
	head=maxBehind(head);
	printList(head);
	return 0;
}