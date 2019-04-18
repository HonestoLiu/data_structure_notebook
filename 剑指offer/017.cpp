/*
输入一个链表，反转链表后，输出新链表的表头
*/

//方法1：递归调用 
ListNode* ReverseList_1(ListNode* pHead) { 
	if(pHead==NULL||pHead->next==NULL)
		return pHead;
	ListNode* new_head = ReverseList_1(pHead->next);	//子链的头指针 
	pHead->next->next =  pHead;
	pHead->next = NULL;
	return new_head; 
}

// 方法2：编号为2-（n-1）的不断插入到编号0的后面，最后编号0插入链尾
// {5->3->4->2->1}
ListNode* ReverseList_2(ListNode* pHead) { 
	if(pHead==NULL||pHead->next==NULL)
		return pHead;
	ListNode* p = pHead->next->next;	//指向4 
	ListNode* p_tmp;
	ListNode* q = pHead->next;	//指向3 
	 
	while(p){	//p不空 ，依次将4 2 1插入5后面 
		p_tmp = p->next;
		p->next = pHead->next;
		pHead->next = p;
		p = p_tmp;
	} 
	//{5->1->2->4->3} ,将5插入链尾 
	ListNode* new_head = pHead->next;
	pHead->next = NULL;
	q->next = pHead;
	return new_head;
} 

//方法3： 
// {5->3->4->2->1}
ListNode* ReverseList_3(ListNode* pHead) { 
	if(pHead==NULL||pHead->next==NULL)
		return pHead;
	ListNode* resHead = pHead->next;
	pHead->next = NULL; 	//{pHead=5->NULL}+{resHead=3->...->1->NULL}
	ListNode* q;
	while(resHead){	//剩余子链不空 
		q = resHead->next;
		resHead->next = pHead;
		pHead = resHead;
		resHead = q;
	} 
	return pHead;
} 
