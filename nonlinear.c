#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
struct node
{
    int data;
    struct node *link;
};
struct node *root = NULL,*top = NULL,*front = NULL,*rear = NULL;
int len;
void append()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &temp->data);
    temp->link = NULL;
    if (root == NULL)
    {
        root = temp;
    }
    else
    {
        struct node *p;
        p = root;
        while (p->link != NULL)
        {
            p = p->link;
        }
        p->link = temp;
    }
}
int length(int n)
{
    int count = 0;
    struct node *p;
    if (n == 0)
    	p = root;
   	else if(n == 1)
   		p = top;
	else if(n==2)
		p = front;
    while (p != NULL)
    {
        count++;
        p = p->link;
    }
    return count;
}
void display(int n )
{
    struct node *temp;
    if(n == 0){
    temp = root;
    }
    else if(n == 1){
    	temp = top;
    }
    else if(n==2)
    {
    	temp = front;
    }
    while (temp != NULL)
    {
        printf("%d-->", temp->data);
        temp  = temp->link;
    }
    printf("\n\n");
}
void addatbeg()
{
	struct node *temp;
	temp = ( struct node *)malloc(sizeof(struct node));
 	printf("Enter the data: ");
    scanf("%d", &temp->data);
    temp->link = NULL;
 	if(root == NULL)
 	{
	 	root = temp;
	 }
	 else{
 		
		temp->link = root;
		root = temp;
 	}
	
}
void addafter()
{
	int loc,i=1;
	struct node *p;
	printf("Enter the location after which you want to add node:");
	scanf("%d",&loc);
	while(1)
		if(loc > length(0))
		{
			
			printf("Please enter the valid location....!!!! :");
			scanf("%d",&loc);
		}
		else
		{
			p =root;
			while(i < loc)
			{
				p= p->link;
				i++;
			}
			break;
		}
	struct node *temp;
	temp = ( struct node *)malloc(sizeof(struct node));
 	printf("\nEnter the data: ");
    scanf("%d", &temp->data);
    temp->link = NULL;
    temp->link = p->link;
    p->link = temp;

}

void deletenode()
{
	struct node *temp;
	int loc;
	printf("Enter the location  to delete node:");
	scanf("%d",&loc);
	if(loc > length(0))
	{
		
		printf("Please enter the valid location....!!!! \n");
		
	}
	else if(loc == 1){
		
		temp = root;
		root = temp->link;
		temp->link = NULL;
		free(temp);
		
	}
	else{
		int i=1;
		struct node *q,*p = root;
		while(i < loc-1){
			p = p->link;
			i++;
		}
		q = p->link;
		p->link = q->link;
		q->link = NULL;
		free(q);
		
	}
}
void linklist()
{
	int ch;
    while (1)
    {
        printf("Single Link List \n\n");
        printf("1.) Append \n");
        printf("2.) Length of LinkList \n");
        printf("3.) Display the Linklist \n");
        printf("4.) Add the node at the beginning \n");
        printf("5.) Add the node after specified location \n");
        printf("6.) Delete the node \n");
        printf("7:) Quit \n\n");
        printf("Choose your option:");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1 :
            append();
            break;
        case 2:
            len = length(0);
            printf("Lenght of Link List is : %d \n\n", len);
            break;
        case 3:
            display(0);
            break;
        case 4:
			addatbeg();
        	break;
        case 5:
        	addafter();
        	break;
       	case 6:
       		deletenode();
       		break;
		case 7:
            exit(1);

        default:
            printf("Enter valid number \n\n");
            break;
        }
    }
}
void push()
{
	struct node *temp;
	temp = ( struct node *)malloc(sizeof(struct node));
 	printf("Enter the data: ");
    scanf("%d", &temp->data);
    temp->link = NULL;
    if (top == NULL)
    	top = temp;
   	else{
	   	struct node *np=top;
	   	top = temp;
	   	temp->link = np;
  	}
    
}
void pop(){
	if(top == NULL)
	{
		printf("Error:Underflow!!!!!!! \n\n");
	}
	else{
		
		struct node *temp;
		temp = top;
		top = top->link;
		free(temp);
	}
}
void stack()
{
	int ch;
    while (1)
    {
        printf("!!!!!!!Stack!!!!!!!! \n\n");
        printf("1.) Push \n");
        printf("2.) Length of the stack \n");
        printf("3.) Display the stack \n");
        printf("4.) Pop \n");
        printf("5.) Exit \n");
        printf("Choose your option:");
        scanf("%d",&ch);
        
        switch (ch)
        {
        case 1 :
            push();
            break;
        case 2:
            len = length(1);
            printf("Lenght of Link List is : %d \n\n", len);
            break;
        case 3:
            display(1);
            break;
        case 4:
        	pop();
        	break;
 		case 5:
            exit(1);

        default:
            printf("Enter valid number \n\n");
            break;
        }
    }
}
void insert(){
	struct node *temp;
	temp = ( struct node *)malloc(sizeof(struct node));
 	printf("Enter the data: ");
    scanf("%d", &temp->data);
    temp->link = NULL;
    if(front == NULL)
    {
    	front = temp;
    	rear = front;
    }
    else
    {
    	rear->link = temp; //we don't need extra pointer because
		rear = temp;	//pointer attached to rear has null in link
    }					//while in stack top elemnt link contain address
				//so we need extra node in stack push but not in queue
//the node of front contain the pointer
//front->data1[add.ofdata2]->data2[add.ofdata3]---->datan[null]<--rear
}
void delete_queue()
{
	if(front == NULL)
	{
		printf("\nError:Underflow!!!!! \n\n");
	}
	else
	{
		struct node *temp = NULL ;
		temp = front;
		front =front-> link;
	//	printf("%d",front->data);
		temp->link = NULL;
		free(temp);
	}
}

void queue()
{
	int ch;
    while (1)
    {
        printf("!!!!!!!Queue!!!!!!!! \n\n");
        printf("1.) Insert(Rear) \n");
        printf("2.) Length of the Queue \n");
        printf("3.) Display the Queue \n");
        printf("4.) Delete(Front) \n");
        printf("5.) Exit \n");
        printf("Choose your option:");
        scanf("%d",&ch);
        
        switch (ch)
        {
        case 1 :
            insert();
            break;
        case 2:
            len = length(2);
            printf("\nLenght of the Queue is : %d \n\n", len);
            break;
        case 3:
            display(2);
            break;
        case 4:
        	delete_queue();
        	break;
 		case 5:
            exit(1);

        default:
            printf("Enter valid number \n\n");
            break;
        }
    }	
}
int main()
{   
   // clrscr();
   	int ch;
	printf("1.) Linklist \n");	
	printf("2.) Stack \n");
	printf("3.) Queue \n");
	printf("4:) Exit \n");
	printf("Choose your option:");
	scanf("%d",&ch);
	switch(ch){
    	case 1:
			linklist();
   			break;
	    case 2:
			stack();
			break;
		case 3:
			queue();
			break;
		case 4:
			exit(1);
			break;
  		default:
    		printf("Enter valid number \n\n");
      	break;
	}
    return 0;
}
