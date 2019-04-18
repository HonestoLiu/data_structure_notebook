/*
����һ��������ת��������������ı�ͷ
*/

//����1���ݹ���� 
ListNode* ReverseList_1(ListNode* pHead) { 
	if(pHead==NULL||pHead->next==NULL)
		return pHead;
	ListNode* new_head = ReverseList_1(pHead->next);	//������ͷָ�� 
	pHead->next->next =  pHead;
	pHead->next = NULL;
	return new_head; 
}

// ����2�����Ϊ2-��n-1���Ĳ��ϲ��뵽���0�ĺ��棬�����0������β
// {5->3->4->2->1}
ListNode* ReverseList_2(ListNode* pHead) { 
	if(pHead==NULL||pHead->next==NULL)
		return pHead;
	ListNode* p = pHead->next->next;	//ָ��4 
	ListNode* p_tmp;
	ListNode* q = pHead->next;	//ָ��3 
	 
	while(p){	//p���� �����ν�4 2 1����5���� 
		p_tmp = p->next;
		p->next = pHead->next;
		pHead->next = p;
		p = p_tmp;
	} 
	//{5->1->2->4->3} ,��5������β 
	ListNode* new_head = pHead->next;
	pHead->next = NULL;
	q->next = pHead;
	return new_head;
} 

//����3�� 
// {5->3->4->2->1}
ListNode* ReverseList_3(ListNode* pHead) { 
	if(pHead==NULL||pHead->next==NULL)
		return pHead;
	ListNode* resHead = pHead->next;
	pHead->next = NULL; 	//{pHead=5->NULL}+{resHead=3->...->1->NULL}
	ListNode* q;
	while(resHead){	//ʣ���������� 
		q = resHead->next;
		resHead->next = pHead;
		pHead = resHead;
		resHead = q;
	} 
	return pHead;
} 
