#include<iostream>
using namespace std;
class ListNode{
	public:
		int data;
		ListNode* link;
		ListNode(int data=0){
			this->data=data;
			this->link=nullptr;
		}
};
class LinkList{
	public:
		ListNode* head;
		LinkList(){
			head=new ListNode();
		}
		~LinkList(){
			ListNode*p=head;
			ListNode*q;
			while(p!=nullptr){
				q=p;
				p=p->link;
				delete q;
			}
		}
};
int FindLastK(LinkList* list,int k){
	LinkList* fast=list->head->link;
	LinkList* slow=list->head->link;
	for(int i=0;i<k;i++){
		if(fast==nullptr){
			return -1;
		}
		fast=fast->link;
	}
	while(fast!=nullptr){
		fast=fast->link;
		slow=slow->link;
	}
	return slow->data;
}
int main(){
	LinkList* list=new LinkList(1);
	list->head->link=new LinkList(2);
	int ans=FindLastK(list,1);
	cout<<ans<<endl;
	delete list;
	return 0;
}