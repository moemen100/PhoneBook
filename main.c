#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    char Last_Name[30];
    char First_Name[30];
    char Address[50];
    char City [10];
    char Number[15];
} Phone;
Phone A[100];
char last_name[30];
char first_name[30];
void Load();
void Save();
void Query();
void Delete();
void Modify();
void Add();
void Print();
FILE *p ;
int C=0;
void main()
{
    system("color 1d");
    printf("Press any key to continue..\n");
    getch();
    Load();
    system("cls");
    Menu();
}
Menu()
{
    printf("\t\t**********WELCOME TO PHONEBOOK*************");
    printf("\n\n\t\t\t\t MENU\n\n");
    printf("1- Add new contact. \n2- Print all contacts. \n3- Modify a contact. \n4- Search for a contact.\n5- Delete a contact.\n6- Save. \n7- Exit.\n");
    switch(getch())
    {
    case '1':
        system("cls");
        Add();
        break ;
    case '2':
        system("cls");
        Print();
        break ;
    case '3':
        system("cls");
        Modify();
        break ;
    case '4':
        system("cls");
        Query();
        break ;
    case '5':
        system("cls");
        Delete();
        break ;
    case'6':
        system("cls");
        Save();
        break ;
    case'7':
        system("cls");
        printf("Thanks for using Phonebook.\n");
        printf("Press any key to continue..");
        getch();
        exit(0);
        break;
    default :
        printf("Incorrect entry, please try again.\n");
        printf("Press any key to continue..");
        getch();
        system("cls");
        Menu();
    }
}
int Stop=0;
void Load()
{
    if(Stop==0)
    {
        p=fopen("phonebook.txt","r");
        if(p==0)
        {
            printf("File not found.");
        }
        else
        {while(!feof(p)){
            fscanf(p,"%s %s %s %s %s",A[C].First_Name,A[C].Last_Name,A[C].Address,A[C].City,A[C].Number);
            C++;
        }}
        fclose(p);
        Stop=1;
        printf("File loaded successfully.\n");
        printf("Presss any key to go to main menu.\n");
        getch();
        system("cls");
        Menu();
    }
    else
        printf("You've aready loaded the file.");
    printf("Presss any key to return to main menu.\n");
    getch();
    system("cls");
    Menu();
}
void Add()
{
    printf("First name : ");
    scanf("%s",A[C].First_Name);
    printf("Last name : ");
    scanf("%s",A[C].Last_Name);
    printf("Address : ");
    scanf("%s",A[C].Address);
    printf("City : ");
    scanf("%s",A[C].City);
    printf("Number : ");
    scanf("%s",A[C].Number);
    C++;
    printf("Contact Added successfully.\n");
    printf("Presss any key to return to main menu.\n");
    getch();
    system("cls");
    Menu();
}
void Save()
{
    int j=0;
    p=fopen("phonebook.txt","w");
    for(j=0; j<C; j++)
    {
        fprintf(p,"%s %s %s %s %s\n",A[j].First_Name,A[j].Last_Name,A[j].Address,A[j].City,A[j].Number);
    }
    fclose(p);
    printf("Contacts saved successfully.\n");
    printf("Presss any key to return to main menu.\n");
    getch();
    system("cls");
    Menu();
}
void Modify()
{

    int i,v=0;
    int a[100];
    printf("Enter last name :");
    scanf("%s",last_name);
    for(i=0; i<=C; i++)
    {
        if(strcmp(last_name,A[i].Last_Name)==0)
        {
            v++;
            a[v]=i;
            printf("\n%d.First name: %s Last Name:%s Address:%s City:%s Number:%s\n",v,A[i].First_Name,A[i].Last_Name,A[i].Address,A[i].City,A[i].Number);
        }
    }
    if(v==0)
        printf("No contacts found.\n") ;
    else
    {
        printf("\n");
        printf("Choose a contact to modify : ");
        scanf("%d",&v);
        printf("\n");
        printf("First name : ");
        scanf("%s",A[a[v]].First_Name);
        printf("Last name : ");
        scanf("%s",A[a[v]].Last_Name);
        printf("Address : ");
        scanf("%s",A[a[v]].Address);
        printf("City : ");
        scanf("%s",A[a[v]].City);
        printf("Number : ");
        scanf("%s",A[a[v]].Number);
        printf("\n");
        printf("Contact modified successfully.\n");
    }
    printf("Press any key to return to main menu.\n");
    getch();
    system("cls");
    Menu();
}
void Delete()
{
    int i,v=0;
    int a[100];
    printf("Last name : ");
    scanf("%s",last_name);
            printf("\n");
    for(i=0; i<=C; i++)
    {
        if(strcmp(last_name,A[i].Last_Name)==0)
        {
            v++;
            a[v]=i;
            printf("\n%d.)First name:%s Last name:%s Address:%s City:%s Number:%s\n",v,A[i].First_Name,A[i].Last_Name,A[i].Address,A[i].City,A[i].Number);
        }
    }
    if(v==0)
        printf("No contacts found.\n") ;
    else
    {

        printf("Choose a contact to delete : \n");
        scanf("%d",&v);
        printf("\n");
        strcpy(A[a[v]].First_Name,A[C-1].First_Name);
        strcpy(A[a[v]].Last_Name,A[C-1].Last_Name);
        strcpy(A[a[v]].Address,A[C-1].Address);
        strcpy(A[a[v]].City,A[C-1].City);
        strcpy(A[a[v]].Number,A[C-1].Number);
        C--;
        printf("Contact deleted successfully.\n");
    }
    printf("Press any key to return to main menu.\n");
    getch();
    system("cls");
    Menu();
}
void Query()
{
    int K=0,i=0;
    char phone[30];
    char city[30];
    char address[30];
    system("cls");
    printf("1.Search by first name.\n2.Search by last name.\n3-Search by address.\n4.Search by city.\n5.Search by number.\n");
    printf("\n");
    switch(getch())
    {
    case '1':
        printf("First name :");
        scanf("%s",first_name);
        printf("\n");
        while(i<=C)
        {
            if(strcmp(first_name,A[i].First_Name)==0)
                {printf("\First name:%s Last name:%s Address:%s City:%s Number:%s\n",A[i].First_Name,A[i].Last_Name,A[i].Address,A[i].City,A[i].Number);
            K++;}i++;
        }
        break;
    case '2':
        printf("Last name :");
        scanf("%s",last_name);
        printf("\n");
        while(i<=C)
        {
            if(strcmp(last_name,A[i].Last_Name)==0)
                               {printf("\First name:%s Last name:%s Address:%s City:%s Number:%s\n",A[i].First_Name,A[i].Last_Name,A[i].Address,A[i].City,A[i].Number);
            K++;}i++;
        }
        break;
    case '3':
        printf("Address : ");
        scanf("%s",address);
        printf("\n");
        while(i<=C)
        {
            if(strcmp(address,A[i].Address)==0)
                               {printf("\First name:%s Last name:%s Address:%s City:%s Number:%s\n",A[i].First_Name,A[i].Last_Name,A[i].Address,A[i].City,A[i].Number);
            K++;}i++;
        }
        break;
    case '4':
        printf("City : ");
        scanf("%s",city);
        printf("\n");
        while(i<=C)
        {
            if(strcmp(city,A[i].City)==0)
                                {printf("First name:%s Last name:%s Address:%s City:%s Number:%s\n",A[i].First_Name,A[i].Last_Name,A[i].Address,A[i].City,A[i].Number);
            K++;}i++;
        }
        break;
    case '5':
        printf("Number : ");
        scanf("%s",phone);
        printf("\n");
        while(i<=C)
        {
            if(strcmp(phone,A[i].Number)==0)
                               {printf("\First name:%s Last name:%s Address:%s City:%s Number:%s\n",A[i].First_Name,A[i].Last_Name,A[i].Address,A[i].City,A[i].Number);
            K++;}i++;
        }
        break;
    default :
        printf("Incorrect entry,please try again.\n");
        printf("press any key to continue..\n");
        getch();
        Query();
    }
    if(K==0)
        printf("No contacts found.\n");
    printf("\n");
    printf("Press any key to return to main menu.\n");
    getch();
    system("cls");
    Menu();
}
void Print()
{
    int q=1,a=0;
    Phone s;
    for (a=0; a<=C-1; a++)
    {
        for (q=a+1; q<C; q++)
            if (strcmp(A[a].Last_Name, A[q].Last_Name)>0)
            {
                strcpy(s.Last_Name, A[a].Last_Name);
                strcpy(A[a].Last_Name, A[q].Last_Name);
                strcpy(A[q].Last_Name, s.Last_Name);

                strcpy(s.First_Name, A[a].First_Name);
                strcpy(A[a].First_Name, A[q].First_Name);
                strcpy(A[q].First_Name, s.First_Name);

                strcpy(s.City, A[a].City);
                strcpy(A[a].City, A[q].City);
                strcpy(A[q].City, s.City);

                strcpy(s.Address, A[a].Address);
                strcpy(A[a].Address, A[q].Address);
                strcpy(A[q].Address, s.Address);

                strcpy(s.Number, A[a].Number);
                strcpy(A[a].Number, A[q].Number);
                strcpy(A[q].Number, s.Number);
            }
    }
    for (q = 1; q <C; q++)
    {
        printf("First name:%s Last name:%s Address:%s City:%s Number:%s\n",A[q].First_Name,A[q].Last_Name,A[q].Address,A[q].City,A[q].Number);
    }
    printf("Press any key to return to main menu.\n");
    getch();
    system("cls");
    Menu();
}
