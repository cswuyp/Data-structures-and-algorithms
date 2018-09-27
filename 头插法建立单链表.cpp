/*头插法建立单链表*/
LinkList CreatList(LinkList &L)
{
	//从表尾到表头逆向建立单链表L，每次均在头结点之后插入元素
	LNode *s;
	int x;
	L=(LinkList)malloc(sizeof(LNode));//创建头结点
	L->next=NULL;
	scanf("%d",&x);
	while(x!=9999)
	{
		s=(LNode*)malloc(sizeof(LNode));
		s->data=x;
		s->next=L->next;
		L->next=s;
		scanf("%d",&x);
	}
	return L;
}