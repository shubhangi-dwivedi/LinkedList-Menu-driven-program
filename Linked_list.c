//Linked List program in C language
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

struct node *temp;

struct node *insert(struct node *head)
{
	struct node *nn=malloc(sizeof(struct node));
	printf("enter new node data : ");
	scanf("%d",&(nn->data));
	nn->next=NULL;
	if(head==NULL)
	{
		head=nn;
		temp=head;
	}
	else
	{
		temp->next=nn;
		temp=nn;
	}
	return head;
}

void display(struct node *head)
{
	struct node *ptr;
	ptr=head;
	while(ptr!=NULL)
	{
		printf("\n Element in Linked list are :\n%d",ptr->data);
		ptr=ptr->next;
	}
}

void reverseLL_recursion(struct node *head)
{
    if(!head)
        return;

    else
    {
        reverseLL_recursion(head->next);
        printf("%d\n",head->data);
    }
}

void reverseLL(struct node *head)
{
        struct node *prev=NULL;
        struct node *newnext=NULL;

        if(!head)
        {
            return;
        }

        else
        {
            while(head!=NULL)
            {
                newnext=head->next;
                head->next=prev;
                prev=head;
                head=newnext;
            }
            head=prev;
        }
        struct node *ptr;
        ptr=head;
        while(ptr!=NULL)
        {
            printf("%d\n",ptr->data);
            ptr=ptr->next;
        }
        printf("\n");
        return;
}

struct node *delfromBeg(struct node *head)
{
	struct node *delnode;
	delnode=head;
	head=head->next;
	free(delnode);
	printf("First Node deleted");
	return head;
}

int main()
{
	struct node *head=NULL;
	int ch;
	do
	{
		printf("Enter your choice :\n1.insert\n2.display\n3.delete node from Beginning\n4.Reverse using recursion\n5.Reverse without recursion\n6.exit \n");
		scanf("%d",&ch);
		printf("\n");
		switch(ch)
		{
			case 1:
				head=insert(head);
				break;
			case 2:
				display(head);
				break;
			case 3:
				head=delfromBeg(head);
				break;
            case 4:
                reverseLL_recursion(head);
                break;
            case 5:
                reverseLL(head);
		}
	}while(ch!=6);
	printf("\nEXIT");
	return 0;
}
