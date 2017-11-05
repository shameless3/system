#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 20
struct grade{
    char name[MAX];
    char IDnumber[MAX];
    char sex;
    int chinese;
    int math;
    int english;
    float average;
    struct grade*pnext;
};

static struct grade student,*head,*p,*q,*tail,*r,*s;

static int order,number=0;

void Pre(void);

int PrintMenu(void);

void Add(void);

void Print(void);

void Delete(void);

void Save(void);

void Reorder(void);

void Average(void);

int main()
{
    tail=(struct grade*)malloc(sizeof(struct grade));
    head=(struct grade*)malloc(sizeof(struct grade));
    head->pnext=tail;
    tail=head;
    Pre();
    PrintMenu();

    return 0;
}

void Pre(void)
{
    FILE *fin;
    fin=fopen("systemfile.txt","r");
    int i=1;
    fscanf(fin,"%d",&number);
    p=head;
    while(i<=number&&fin!=NULL)
    {
        q=(struct grade*)malloc(sizeof(struct grade));
        p->pnext=q;
        p=p->pnext;
        fscanf(fin,"%s %s %c %d %d %d ",p->name,p->IDnumber,&(p->sex),&(p->chinese),&(p->math),&(p->english));
        i++;
    }
    fclose(fin);
    tail=p;
    p=(struct grade*)malloc(sizeof(struct grade));
    tail->pnext=p;
    tail->pnext=NULL;
}

int PrintMenu(void)
{
    system("clear");
    printf("welcome to the student management system");
    printf("here are the orders you can give\n");
    printf("enter 1: add information\n");
    printf("enter 2: print information\n");
    printf("enter 3: delete information\n");
    printf("enter 4: reorder information\n");
    printf("enter 5: get average\n");
    printf("enter 6: save and quit\n");
    scanf("%d",&order);getchar();
    if(order == 1)
         Add();
    if(order == 2)
         Print();
    if(order == 3)
         Delete();
    if(order == 4)
         Reorder();
    if(order == 5)
         Average();
    if(order == 6)
    {
        Save();
        return 0;
    }
    getchar();
}

void Add(void)
{

        p=(struct grade*)malloc(sizeof(struct grade));
        tail->pnext=p;
        p=tail->pnext;
        printf("now please enter the student's name\n");
        scanf("%s",p->name);getchar();
        printf("now please enter the student's IDnumber\n");
        scanf("%s",p->IDnumber);getchar();
        printf("now please enter the sex,'w'for woman,'m'for man\n");
        scanf("%c",&(p->sex));
        printf("now enter the student's chinese grades\n");
        scanf("%d",&(p->chinese));
        printf("now enter the student's math grades\n");
        scanf("%d",&(p->math));
        printf("now enter the student's english grades\n");
        scanf("%d",&(p->english));
        printf("well done!\n");
        number++;
        tail=p;

        printf("enter 1 to continue\n");
        printf("enter 2 to go back to menu\n");
        scanf("%d",&order);
        getchar();
        while(order!=1&&order!=2)
        {
            printf("wrong enter,please enter again\n");
            scanf("%d",&order);
            getchar();
        }
        if(order==1)
            Add();
        else if (order == 2)
        {
            p=(struct grade*)malloc(sizeof(struct grade));
            tail->pnext=p;
            tail->pnext=NULL;
            PrintMenu();
        }

}

void Print(void)
{
        printf("here are the student's information that you have entered\n");
        printf("name\t\tIDnumber\tsex\t\tchinese\t\tmath\t\tenglish\t\taverage\n");
        p=head->pnext;
        while(p!=NULL&&number!=0)
        {
            printf("%-15s %-15s %-15c %-15d %-15d %-15d %-15.2f\n",(p->name),(p->IDnumber),(p->sex),(p->chinese),(p->math),(p->english),(p->average));
            p=p->pnext;
        }
        printf("enter 1 to go back to menu\n");
        scanf("%d",&order);
        while(order!=1)
        {
            printf("wrong enter,please enter again\n");
            scanf("%d",&order);
        }
        PrintMenu();
}

void Delete(void)
{
    int i,j=0;
    char ID[MAX];
    printf("please enter the student's IDnumber that you want to delete\n");
    scanf("%s",ID);
    q=head;
    p=head->pnext;
    while (p!=NULL)
    {
        if((strcmp(ID,p->IDnumber)==0))
        {
            j=1;
            break;
        }
        q=p;
        p=p->pnext;
    }
    if(j==1)
    {
        q->pnext=p->pnext;
        if(p==tail)
            tail=q;
        free(p);
        printf("done!\ngo back to menu");
        number--;
        getchar();
        getchar();
        PrintMenu();
    }
    else
    {
        printf("not found!go back to menu\n");
        getchar();
        getchar();
        PrintMenu();
    }
}

void Reorder(void)
{
    int m,n;
    printf("here are the orders you can give\n");
    printf("enter 1: reorder by chinese\n");
    printf("enter 2: reorder by math\n");
    printf("enter 3: reorder by english\n");
    printf("enter 4: reorder by average\n");
    scanf("%d",&order);getchar();
    if(order==1)
    {
        for(p=head->pnext;(p->pnext)!=NULL;p=p->pnext)
        {
            for(r=head->pnext,q=r->pnext;q!=NULL;r=r->pnext,q=q->pnext)
            {
                if((r->chinese)<(q->chinese))
                {
                    char a[MAX];
                    char b;
                    int c;
                    float d;
                    strcpy(a,r->name);
                    strcpy(r->name,q->name);
                    strcpy(q->name,a);

                    strcpy(a,r->IDnumber);
                    strcpy(r->IDnumber,q->IDnumber);
                    strcpy(q->IDnumber,a);

                    b=r->sex;
                    r->sex=q->sex;
                    q->sex=b;

                    c=r->chinese;
                    r->chinese=q->chinese;
                    q->chinese=c;

                    c=r->math;
                    r->math=q->math;
                    q->math=c;

                    c=r->english;
                    r->english=q->english;
                    q->english=c;

                    d=r->average;
                    r->average=q->average;
                    q->average=d;
                }
            }
        }
        printf("done!\ngo back to menu\n");
        getchar();
        PrintMenu();
    }

    if(order==2)
    {
        for(p=head->pnext;(p->pnext)!=NULL;p=p->pnext)
        {
            for(r=head->pnext,q=r->pnext;q!=NULL;r=r->pnext,q=q->pnext)
            {
                if((r->math)<(q->math))
                {
                    char a[MAX];
                    char b;
                    int c;
                    float d;
                    strcpy(a,r->name);
                    strcpy(r->name,q->name);
                    strcpy(q->name,a);

                    strcpy(a,r->IDnumber);
                    strcpy(r->IDnumber,q->IDnumber);
                    strcpy(q->IDnumber,a);

                    b=r->sex;
                    r->sex=q->sex;
                    q->sex=b;

                    c=r->chinese;
                    r->chinese=q->chinese;
                    q->chinese=c;

                    c=r->math;
                    r->math=q->math;
                    q->math=c;

                    c=r->english;
                    r->english=q->english;
                    q->english=c;

                    d=r->average;
                    r->average=q->average;
                    q->average=d;
                }
            }
        }
        printf("done!\ngo back to menu\n");
        getchar();
        PrintMenu();
    }

    if(order==3)
    {
        for(p=head->pnext;(p->pnext)!=NULL;p=p->pnext)
        {
            for(r=head->pnext,q=r->pnext;q!=NULL;r=r->pnext,q=q->pnext)
            {
                if((r->english)<(q->english))
                {
                    char a[MAX];
                    char b;
                    int c;
                    float d;
                    strcpy(a,r->name);
                    strcpy(r->name,q->name);
                    strcpy(q->name,a);

                    strcpy(a,r->IDnumber);
                    strcpy(r->IDnumber,q->IDnumber);
                    strcpy(q->IDnumber,a);

                    b=r->sex;
                    r->sex=q->sex;
                    q->sex=b;

                    c=r->chinese;
                    r->chinese=q->chinese;
                    q->chinese=c;

                    c=r->math;
                    r->math=q->math;
                    q->math=c;

                    c=r->english;
                    r->english=q->english;
                    q->english=c;

                    d=r->average;
                    r->average=q->average;
                    q->average=d;
                }
            }
        }
        printf("done!\ngo back to menu\n");
        getchar();
        PrintMenu();
    }

    if(order==4)
    {
        for(p=head->pnext;(p->pnext)!=NULL;p=p->pnext)
        {
            for(r=head->pnext,q=r->pnext;q!=NULL;r=r->pnext,q=q->pnext)
            {
                if((r->average)<(q->average))
                {
                    char a[MAX];
                    char b;
                    int c;
                    float d;
                    strcpy(a,r->name);
                    strcpy(r->name,q->name);
                    strcpy(q->name,a);

                    strcpy(a,r->IDnumber);
                    strcpy(r->IDnumber,q->IDnumber);
                    strcpy(q->IDnumber,a);

                    b=r->sex;
                    r->sex=q->sex;
                    q->sex=b;

                    c=r->chinese;
                    r->chinese=q->chinese;
                    q->chinese=c;

                    c=r->math;
                    r->math=q->math;
                    q->math=c;

                    c=r->english;
                    r->english=q->english;
                    q->english=c;

                    d=r->average;
                    r->average=q->average;
                    q->average=d;
                }
            }
        }
        printf("done!\ngo back to menu\n");
        getchar();
        PrintMenu();
    }

    else
    {
        printf("wrong enter!\ngo back to menu\n");
        getchar();
        PrintMenu();
    }
}

void Average(void)
{
    for(r=head->pnext;r!=NULL;r=r->pnext)
    {
        r->average=(r->chinese+r->math+r->english)/3.0;
    }
    printf("done\n");
    printf("go back to menu\n");
    getchar();
    PrintMenu();
}

void Save(void)
{
    FILE *fout;
    p=head->pnext;
    fout=fopen("systemfile.txt","w");
    fprintf(fout,"%d ",number);
    while(p!=NULL)
    {
        fprintf(fout,"%s %s %c %d %d %d ",p->name,p->IDnumber,p->sex,p->chinese,p->math,p->english);
        p=p->pnext;
    }
    fclose(fout);
}

