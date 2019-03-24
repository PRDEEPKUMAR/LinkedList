#include<stdio.h>
#include<stdlib.h>
struct List
{
    int data;
    struct List *link;
};
struct List *start=NULL;
  void create(int num)
  {
    struct List *q=NULL;
    struct List *temp=(struct List*)malloc(sizeof(struct List));
    temp->data=num;
    temp->link=NULL;
    if(start==NULL)
    {
        start=temp;
    }
    else
     {
          q=start;
          while(q->link!=NULL)
          {
               q=q->link;
          }
          q->link=temp;
     }
  }
  void insertAnyPos(int pos,int num)
  {
      int i=0;
      struct List *q=start;
      struct List *temp=(struct List*)malloc(sizeof(struct List));
      temp->data=num;
      temp->link=NULL;
      if(start==NULL)
      {
        start=temp;

      }
      if(pos==1)
      {
        temp->link=start;
        start=temp;
      }
      else
      {
           for(i=1;i<pos-1;i++)
           {
               q=q->link;
          }
            temp->link=q->link;
            q->link=temp;
      }

  }
    void insertAfterPos(int pos,int num)
  {
      int i=0;
      struct List *q=start;
      struct List *temp=(struct List*)malloc(sizeof(struct List));
      temp->data=num;
      temp->link=NULL;
      if(start==NULL)
      {
        start=temp;

      }
      if(pos==1)
      {
        temp->link=start;
        start=temp;
      }
      else
      {
           for(i=1;i<pos;i++)
           {
               q=q->link;
          }
            temp->link=q->link;
            q->link=temp;
      }

  }
  void insertAtEnd(int num)
  {
      struct List *temp=(struct List*)malloc(sizeof(struct List));
      temp->data=num;
      temp->link=NULL;
      struct List *n=start;
      if(start==NULL)
      {
         start=temp;
      }
      while(n->link!=NULL)
      {
          n=n->link;
      }
      n->link=temp;

  }
    void insertAfterNode(int val,int num)
  {
      int i=0;
      struct List *q=start;
      struct List *temp=(struct List*)malloc(sizeof(struct List));
      temp->data=num;
      temp->link=NULL;
      if(start==NULL)
      {
        start=temp;

      }
      if(start->data==val)
      {
      temp->link=start;
      start=temp;
      }
      else
      {
           while(q->data!=val)
           {
               q=q->link;
           }
            temp->link=q->link;
            q->link=temp;
      }

  }
  void display()
  {
     struct List *n=start;
     while(n!=NULL)
     {
       printf("%d ->",n->data);
       n=n->link;
     }
     printf("\n");
  }
  void insertAtBeg(int num)
  {
    struct List *temp=(struct List*)malloc(sizeof(struct List));
    temp->data=num;
    temp->link=NULL;
     if(start==NULL)
     {
         start=temp;
     }
     else
     {
        temp->link=start;
        start=temp;
     }
  }
  void deleteBeg()
  {
        struct List *temp=NULL;
        if(start==NULL)
       {
           printf("\n UNDERFLOW\n");
           return ;
       }
        else
        {
            temp=start;
            start=start->link;
            free(temp);
        }

}
  void deleteEnd()
  {
        struct List *temp=NULL;
          struct List *q=start;
        if(start==NULL)
       {
           printf("\n UNDERFLOW\n");
           return ;
       }
        else
        {
            q=start;
            while(q->link->link!=NULL)
            {
                q=q->link;
            }
            temp=q->link;
            q->link=NULL;
            free(temp);
        }

}
void deleteAnyPos(int pos)
{
    int i;
    struct List *temp=NULL;
    struct List *q=start;
    if(start==NULL)
    {
            printf("\n UNDERFLOW\n");
           return ;
    }
    if(pos==1)
    {
           temp=start;
            start=start->link;
            free(temp);
    }
    else
    {
       for(i=1;i<pos-1;i++)
       {
           q=q->link;
           if(q==NULL)
           {
           printf("\nInvalid Position\n");
           return ;
           }
       }
       temp=q->link;
       q->link=q->link->link;
       free(temp);
    }
}
void deleteGivenNode(int num)
{
    int i;
    struct List *temp=NULL;
    struct List *q=start;
    if(start==NULL)
    {
            printf("\n UNDERFLOW\n");
           return ;
    }
    if(start->data==num)
    {
           temp=start;
            start=start->link;
            free(temp);
    }
    else
    {
       while(q->link->data!=num)
       {
           q=q->link;
       }
       temp=q->link;
       q->link=q->link->link;
       free(temp);
    }
}

  int main()
  {
   int i,choice,n,pos;
   for(i=0;i<10;i++)
   create(i+1);
   display();
   printf("\n Press 1 for Insert At Begining                 ");
   printf("\n Press 2 for Insert At End                      ");
   printf("\n Press 3 for Insert At Paticular Position       ");
   printf("\n Press 4 for Insert After  Paticular Position   ");
   printf("\n Press 5 for Insert After  Paticular Node       ");
   printf("\n Press 6 for Deletion At Begining               ");
   printf("\n Press 7 for Deletion At End                    ");
   printf("\n Press 8 for Deletion At Paticular Postion      ");
   printf("\n Press 9 for Deletion At Given value            ");

     printf("\n Enter Your Choice ");
     scanf("%d",&choice);
     switch(choice)
     {
      case 1:             printf("\nEnter the value");
                          scanf("%d",&n);
                          insertAtBeg(n);
                          printf("\nList After Insertion At Begining\n ");
                          display();
                          break;
      case 2:
                          printf("\nEnter the value : ");
                          scanf("%d",&n);
                          insertAtEnd(n);
                          printf("\nList After Insertion At  End :\n");
                          display();
                          break;
      case 3:
                          printf("\nEnter the Positon :");
                          scanf("%d",&pos);
                          printf("\nEnter the value :");
                          scanf("%d",&n);
                          insertAnyPos(pos,n);
                          printf("\nList After Insertion At Paticular Position :\n");
                           display();
                          break;
      case 4:
                          printf("\nEnter the Positon");
                          scanf("%d",&pos);
                          printf("\nEnter the value");
                          scanf("%d",&n);
                          insertAfterPos(pos,n);
                          printf("\nList After Insertion After Any Position :\n");
                          display();
                          break;
                          break;
      case 5:             printf("\nEnter the Value fter which new value is to Inserted :\n");
                          scanf("%d",&pos);
                          printf("\nEnter the value :");
                          scanf("%d",&n);
                          insertAfterNode(pos,n);
                          printf("\nList After Insertion After A Given Node :\n");
                          display();
                          break;
                          break;

      case 6:
                          deleteBeg();
                          printf("\nList After Deletion At Begining\n ");
                          display();
                          break;
      case 7:
                          deleteEnd();
                          printf("\nList After Deletion At End\n ");
                          display();
                          break;
      case 8:             printf("\nEnter the Pos : ");
                          scanf("%d",&n);
                          deleteAnyPos(n);
                          printf("\nList AfterDeletion At Any Pos\n ");
                          display();
                          break;
   case 9:               printf("\nEnter the  Value : ");
                         scanf("%d",&n);
                         deleteGivenNode(n);
                         printf("\nList After Deletion Atv Given value \n ");
                         display();
                         break;

     }
     return 0;
  }
