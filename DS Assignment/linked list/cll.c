#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *link;
};
struct node *create_list(struct node *last);
void display(struct node * last);
struct node *addtoempty(struct node * last, int data);
struct node *addatend(struct node * last, int data);
struct node *addatbeg(struct node * last, int data);
struct node *addafter(struct node * last, int data, int item);
struct node *addbefore(struct node * last , int data, int item);
struct node *del(struct node *last, int data);

struct node *split1(struct node *last){
    struct node *p,*last1=NULL,*last2=NULL;
    int i=0;
    if(last==NULL)
    {
        printf("Emply list \n");
        return last;
    }
    p=last->link;
    
    do
    {
        printf("hello");
        if(i%2==0){
            if(last1==NULL)
                last1=addtoempty(last1,p->info);
            else
                last1=addatend(last1,p->info);
            
        }
        else{
            if(last2==NULL)
                last2=addtoempty(last2,p->info);
            else
                last2=addatend(last2,p->info);
        }
        p=p->link;
        i++;
    }while(p!=last->link);
    printf("\n");
    printf("Original list\n");
    display(last);    
    printf("List1 is:\n");
    display(last1);
    printf("List2 is:\n");
    display(last2);
    int m=1;
    printf("which list you want to return\n0.ListOG\n1.List1\n2.List2\n");
    scanf("%d",&m);
    switch(m){
        case 1:
            return last1;
        case 2:
            return last2;
        default:
            return last;
    }
}


struct node *create_list(struct node *last)
{
    int i,n,data;
    printf("Enter no. of nodes\n");
    scanf("%d",&n);
    last=NULL;
    if(n==0)
    {
        return last;
    }
    printf("Enter element:\n");
    scanf("%d",&data);
    last=addtoempty(last,data);
    for(i=2;i<=n;i++)
    {
        printf("Enter element:\n");
        scanf("%d",&data);
        last=addatend(last,data);
    }
    return last;
}

void display(struct node *last)
{
    struct node *p;
    if(last==NULL)
    {
        printf("Emply list \n");
        return;
    }
    p=last->link;
    //printf("List is:\n");
    do
    {
        printf("%d ",p->info);
        p=p->link;
    }while(p!=last->link);
    printf("\n");
}

struct node *addtoempty(struct node *last,int data)
{
    struct node *tmp;
    tmp=(struct node*)malloc(sizeof(struct node));
    tmp->info=data;
    last=tmp;
    last->link=last;
    return last;
}

struct node *addatend(struct node *last,int data)
{
    struct node *tmp;
    tmp=(struct node*)malloc(sizeof(struct node));
    tmp->info=data;
    tmp->link=last->link;
    last->link=tmp;
    last=tmp;
    return last;
}

struct node *addatbeg(struct node *last,int data)
{
    struct node *tmp;
    tmp=(struct node*)malloc(sizeof(struct node));
    tmp->info=data;
    tmp->link=last->link;
    last->link=tmp;
    return last;
}

struct node *addafter(struct node *last,int data,int item)
{
    struct node *p,*tmp;
    p=last->link;
    do
    {
        if(p->info==item)
        {
            struct node *tmp;
            tmp=(struct node*)malloc(sizeof(struct node));
            tmp->info=data;
            tmp->link=p->link;
            p->link=tmp;
            if(p==last)
            {
                last=tmp;
            }
            return last;
        }
        p=p->link;
    }while(p!=last->link);
    printf("Item not found\n");
    return last;
}

struct node *addbefore(struct node *last, int data, int item)
{
    struct node *p,*tmp;
    if(last==NULL)
    {
        printf("Empty list\n");
        return last;
    }
    if(last->link->info==item )
    {
        tmp=(struct node*) malloc(sizeof(struct node));
        tmp->info=data;
        tmp->link= last->link;
        last->link=tmp;
        return last;
    }
    p=last->link;
    do
    {
        if(p->link->info==item)
        {
            tmp=(struct node*) malloc(sizeof(struct node));
            tmp->info=data;
            tmp->link= p->link;
            p->link=tmp;
            return last;
        }
        p=p->link;
    }while(p->link!=last->link) ;
    printf("Item not found\n");
    return last;
}
struct node *del(struct node *last, int data)
{
    struct node *tmp, *p;
    if(last==NULL)
    {
        printf("List is empty\n");
        return last;
    }
    if(last->link==last && last->info==data)
    {
        tmp=last;
        last=NULL;
        free(tmp);
        return last;
    }
    if(last->link->info==data)
    {
        tmp=last->link;
        last->link= tmp->link;
        free(tmp);
        return last;
    }
    p=last->link;
    while (p->link!= last)
    {
    if(p->link->info==data) {
    tmp=p->link;
    p->link=tmp->link;
    free(tmp);
    return last;
    }
    p=p->link;
    }
    if(last->info==data)
    {
        tmp=last;
        p->link=last->link;
        last=p;
        free(tmp);
        return last;
    }
    printf("Element %d not found\n",data);
    return last;
}
int main()
{
    struct node * last =NULL;
    int choice, data, item;
    while(1)
    {
        printf("1.Create List\n");
        printf("2.Display\n");
        printf("3.Add to empty list\n");
        printf("4.Add at beginning\n");
        printf("5.Add at end\n");
        printf("6.Add after\n");
        printf("7.Add before\n");
        printf("8.Delete\n");
        printf("9.Split\n");
        printf("10.Quit\n");
        printf("Enter your choice : ");
        scanf("%d" ,&choice);
        switch(choice)
        {
            case 1 :
                last=create_list(last);
                break;
            case 2 :
                display(last);
                break;
            case 3 :
                printf("Enter element: ");
                scanf("%d",&data);
                last=addtoempty(last,data);
                break;
            case 4 :
                printf("Enter element: ");
                scanf("%d",&data);
                last=addatbeg(last,data);
                break;
            case 5 :
                printf("Enter element: ");
                scanf("%d",&data);
                last=addatend(last,data);
                break;
            case 6 :
                printf("Enter element: ");
                scanf("%d",&data);
                printf("Enter the element after which to be inserted : ");
                scanf("%d",&item);
                last=addafter(last,data,item);
                break;
            case 7 :
                printf("Enter element: ");
                scanf("%d",&data);
                printf("Enter the element before which to be inserted : ");
                scanf("%d",&item);
                last=addbefore(last,data,item);
                break;
            case 8:
                printf("Entetr the Element to be delete\n");
                scanf("%d",&data);
                last=del(last,data);
                break;
            case 9:
                printf("Splited list\n");
                last=split1(last);
                break;
            case 10:
                exit(1);
            default :
                printf("Invalid \n");
        }
    }
    return 0;
}
