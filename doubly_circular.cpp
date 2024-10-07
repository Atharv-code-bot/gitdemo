#include<iostream>
using namespace std;

typedef int BOOL;
#define TRUE 1
#define FALSE 0

typedef struct node
{
	struct node* prev;
	int data;
	struct node* next;
}NODE, * PNODE;

class DoublyCircular_LL
{
private:
	PNODE head;  //struct node*
	PNODE tail;  //struct node*

public:
	DoublyCircular_LL();
	~DoublyCircular_LL();
	BOOL InsertFirst(int);
	BOOL InsertLast(int);
	BOOL InsertAtPos(int, int);
	void Display();
	void DisplayB();
	int Count();
	int Search(int);
	BOOL DeleteFirst();
	BOOL DeleteLast();
	BOOL DeleteAtPos(int);
};
int main()
{
	DoublyCircular_LL obj;
	int ret = 0;
	obj.InsertFirst(11);
	obj.InsertFirst(21);
	obj.InsertFirst(31);
	obj.InsertFirst(41);

	obj.Display();
	cout << endl;

	ret = obj.Count();
	cout << "Total No Of Nodes are " << ret << endl;

	obj.InsertLast(101);
	obj.Display();
	cout << endl;

	obj.InsertAtPos(55, 2);
	obj.Display();
	cout << endl;

	obj.DeleteFirst();
	obj.Display();
	cout << endl;

	obj.DeleteLast();
	obj.Display();
	cout << endl;

	obj.DeleteAtPos(3);
	obj.Display();
	cout << endl;

	ret = obj.Search(55);
	if (ret == -1)
	{
		cout << "Node Not Found" << endl;
	}
	else
	{
		cout << "Node Found At Pos " << ret << endl;
	}
	obj.DisplayB();
	return 0;
}

DoublyCircular_LL::DoublyCircular_LL()
{
	head = NULL;
	tail = NULL;
}

DoublyCircular_LL::~DoublyCircular_LL()
{
	PNODE temp = NULL;
	if ((head != NULL) && (tail != NULL))
	{
		do
		{
			temp = head->next;
			delete(head);
			head = temp;
			tail->next = head;
			head->prev = tail;
		} while (head != tail);
		delete(head);
		head = tail = NULL;
	}
}
BOOL DoublyCircular_LL::InsertFirst(int value)
{

	PNODE newnode = NULL;
	newnode = new NODE;
	newnode->prev = NULL;
	newnode->data = value;
	newnode->next = NULL;
	if ((head == NULL) && (tail == NULL))
	{
		head = tail = newnode;
		head->prev = tail;
		tail->next = head;
	}
	else
	{
		newnode->next =head;
		head->prev = newnode;
		head= newnode;
		head->prev = tail;
		tail->next = head;
	}
	return TRUE;
}
BOOL DoublyCircular_LL::InsertLast(int value)
{
	PNODE newnode = NULL;
	newnode = new NODE;
	newnode->prev = NULL;
	newnode->data = value;
	newnode->next = NULL;

	if ((head == NULL) && (tail == NULL))
	{
		head = tail = newnode;
		head->prev = tail;
		tail->next = head;
	}
	else
	{
		newnode->prev = tail;
		(tail)->next = newnode;
		tail = newnode;
		head->prev = tail;
		tail->next = head;
	}
	return TRUE;
}
BOOL DoublyCircular_LL::InsertAtPos(int value, int pos)
{
	if ((pos <= 0) || (pos > (Count() + 1)))
	{
		return FALSE;
	}
	else if (pos == 1)
	{
		InsertFirst(value);
	}
	else if (pos == (Count() + 1))
	{
		InsertLast(value);
	}
	else
	{
		PNODE newnode = NULL;
		newnode = new NODE;
		newnode->prev = NULL;
		newnode->data = value;
		newnode->next = NULL;
		PNODE temp = head;
		while ((pos - 1) > 1)
		{
			temp = temp->next;
		}
		newnode->next = temp->next;
		newnode->prev = temp;
		temp->next->prev = newnode;
		temp->next = newnode;
	}
	return TRUE;
}
BOOL DoublyCircular_LL::DeleteFirst()
{
	if ((head == NULL) && (tail == NULL))
	{
		return FALSE;
	}
	else if (head == tail)
	{
		free(head);
		head = tail = NULL;
	}
	else
	{
		head = head->next;
		free((head)->prev);
		(head)->prev = tail;
		(tail)->next = head;
	}
	return TRUE;
}
BOOL DoublyCircular_LL::DeleteLast()
{
	if ((head == NULL) && (tail == NULL))
	{
		return FALSE;
	}
	else if (head == tail)
	{
		free(head);
		head = tail = NULL;
	}
	else
	{
		tail = (tail)->prev;
		free((tail)->next);
		(head)->prev = tail;
		(tail)->next = head;
	}
	return TRUE;
}
BOOL DoublyCircular_LL::DeleteAtPos(int pos)
{
	if ((pos <= 0) || (pos > Count()))
	{
		return FALSE;
	}
	else if (pos == 1)
	{
		DeleteFirst();
	}
	else if (pos == Count())
	{
		DeleteLast();
	}
	else
	{
		PNODE temp = head;
		while ((pos - 1) > 1)
		{
			temp = temp->next;
		}
		temp->next = temp->next->next;
		free(temp->next->prev);
		temp->next->prev = temp;
	}
	return TRUE;
}
void DoublyCircular_LL::Display()
{
	if ((head != NULL) && (tail != NULL))
	{
		do
		{
			cout<<head->data<<" ";
			head= head->next;
		} while (tail->next != head);
	}
}
void DoublyCircular_LL::DisplayB()
{
	if ((head != NULL) && (tail != NULL))
	{
		do
		{
			cout << tail->data << " ";
			tail = tail->prev;
		} while (head->prev != tail);
	}
}
int DoublyCircular_LL::Count()
{
	int icnt = 0;
	if ((head != NULL) && (tail != NULL))
	{
		do
		{
			icnt++;
			head = head->next;
		} while (tail->next != head);
	}
	return icnt;
}
int DoublyCircular_LL::Search(int value)
{
	int pos=1;
	PNODE temp = head;
	if ((head != NULL) && (tail != NULL))
	{
		do
		{
			if (temp->data == value)
			{
				return pos;
			}
			pos++;
			temp = temp->next;
		} while (tail->next != temp);
	}
	return -1;
}