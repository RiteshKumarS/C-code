/*
*   Author Ritesh
*   LL loop detection and loop point
*   problem ->    1->2->3->4-5->2
*   output will be loop detected
*
*/


#include<stdio.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#define empty NULL
struct node
{
    int i;
    struct node *next;
};

struct node * createList(struct node *head,int item,int nodeNumber)
{
    struct node *tempHead;
    int count = 0;
    tempHead = head;
    if(head==NULL)
    {
        struct node *node = (struct node *)malloc(sizeof(struct node));
        node->i = item;
        if(nodeNumber==0)
        {
            node->next = NULL;
            head = node;
        }
        else
        {
            while(count != nodeNumber)
            {

                head = head->next;
                count++;
            }

            node->next = head;
        }

        return head;
    }
    else
    {
    	printf("came here");
        while(head->next != NULL)
        {

            head = head->next;
        }

        struct node *node = (struct node *)malloc(sizeof(struct node));
        node->i = item;
        head->next  = node;
        if(nodeNumber==0)
        {

            node->next = NULL;
        }
        else
        {
            head = tempHead;
            while(count != nodeNumber)
            {

                head = head->next;
                count++;
            }

            node->next = head;
        }
    }
    return tempHead;
}

void displayList(struct node *head)
{
    printf("\n++++++++++++++Linked List till now +++++++++++++++++++	\n\n");
    while(head != NULL)
    {
    	if(head->next != NULL)
        	printf("%d->",head->i);
        else
        	printf("%d",head->i);
        head = head->next;
    }
    printf("\n");
    return;
}

//return 0 if no loop or 1 otherwise 
int detectLoop(struct node *head)
{
	struct node *tempHead,*fastP,*slowP;
	int loopDetacted = 0;
	fastP = slowP = tempHead = head;
	while(fastP&&slowP)
	{
		if(!fastP)
		{
			return 1;
		}
		fastP = fastP->next;
		if(!fastP)
		{
			return 1;
		}
		fastP = fastP->next;
		slowP = slowP->next;
		if(fastP == slowP)
		{
			printf("coming here");

			return 0;
		}
	}

	return 1;

}
void main()
{
    struct node *list,*head=NULL;
    int item=-1,nodenum,loop=1;
    printf("***Enter item to list and provide nodenumber 1 if this node next field will not be empty otherwise 0**\n \
           ***To Continue with insertion press 1 other wise press 2***\n>");
    scanf("%d %d",&item,&nodenum);

    while(loop==1)
    {
        if(item != -1)
        {
            head = createList(head,item,nodenum);

        }
        else{
        	printf("\nPlease enter item and nodenumber\n>");
            scanf("%d %d",&item,&nodenum);
            head = createList(head,item,nodenum);
        }

        printf("\nContinue with the insertion then press 1 otherwise 0\n>");
        scanf("%d",&loop);
        item = -1;
    }
    // Detection of loop ---
    !detectLoop(head)? printf("\nLoop is detected\n") : printf("\nloop is not detected\n");
    if(detectLoop(head))
    	displayList(head);
    return;
}

