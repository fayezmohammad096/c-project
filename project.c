/************************************************************************
 * LIBRARY MANAGEMENT SYSTEM USING C LANGUAGE
 * NAME : MD FAIZ
 * FUNCTION PROTOTYPE :
void password();
void heading();
void  mainMenu();
void addBook();
void viewbooks();
void searchBook();
void editbooks();
void deletebooks();
void help();
void close();
 ************************************************************************/
#include<windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#include<time.h>

void password();
void heading();
void  mainMenu();
void addBook();
void viewbooks();
void searchBook();
void editbooks();
void deletebooks();
void help();
void close();
struct Book_info
{
    int id;
    char name[15];
    char author[15];
    int quantity;
    int rack;


};
struct Book_info a;
FILE *file, *copy_file;
int d = 1;
int main()
{
    password();

    //getch();
}
void  mainMenu()
{
    system("cls");
    int n;
    printf("\n\n\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 - MAIN MENU - \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\xDB\xDB\xDB\xDB\xB2 1. Add Books   ");
    printf("\n\n\t\xDB\xDB\xDB\xDB\xB2 2. View Book list");
    printf("\n\n\t\xDB\xDB\xDB\xDB\xB2 3. Search Books");
    printf("\n\n\t\xDB\xDB\xDB\xDB\xB2 4. Edit Book's Record");
    printf("\n\n\t\xDB\xDB\xDB\xDB\xB2 5. Delete books");
    printf("\n\n\t\xDB\xDB\xDB\xDB\xB2 6. Help");
    printf("\n\n\t\xDB\xDB\xDB\xDB\xB2 7. Close Application");
    printf("\n\n\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
//    int t;
//    time(&t);
//    printf("\n\t\xDB\xDB\xB2 Date & time:%s",ctime(&t));

    printf("\n\t Enter your choice : ");
    scanf("%d",&n);
    switch(n)
    {
    case 1:
    {

        addBook();
        break;
    }
    case 2:
    {
        viewbooks();
        break;
    }
    case 3:
    {
        searchBook();
        break;
    }
    case 4:
    {
        editbooks();
        break;
    }
    case 5:
    {
        deletebooks();
        break;
    }
    case 6:
    {
        help();
        break;
    }
    case 7:
    {
        close();
        break;
    }
    default :
    {
        printf("\n\n\t Your choice is wrong ! Try again... ");

        fflush(stdin);
        getchar();
        mainMenu();
    }
    }

}
void addBook()
{
    system("cls");
    int d, count=0;
    printf("\n\n\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 - Book Add - \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\t\xB2");
    printf("\t\t\t\t\t \xB2\n");


    file = fopen("books.txt","ab+");
    printf("\n\n\t Enter ID : ");
    fflush(stdin);
    scanf("%d",&d);

    rewind(file);//pointer intial location zero
    while(fread(&a, sizeof(a),1,file)==1)
    {
        if(d==a.id)
        {
            printf("\n\n\t This Book ID already available ");
            count=1;
        }
    }
    if(count==1)
    {
        fflush(stdin);
        getchar();
        mainMenu();
    }
    a.id=d;

    printf("\n\n\t Enter Name : ");
    fflush(stdin);
    scanf("%s", a.name);
    printf("\n\n\t Enter Author : ");
    fflush(stdin);
    scanf("%s", a.author);
    printf("\n\n\t Enter Quantity : ");
    scanf("%d",&a.quantity);
    printf("\n\n\t Enter Rack No : ");
    scanf("%d",&a.rack);

    fseek(file,0,SEEK_END);//pointer location end
    fwrite(&a,sizeof(a),1,file);
    fclose(file);
    printf("\n\n\t Successfully added");
    printf("\n\n\t press any key...");
    fflush(stdin);
    getchar();
    mainMenu();
}
void viewbooks()
{
    system("cls");
    int count=0,i=0;
    printf("\n\n\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 - View Book List -  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    //printf("\n\t SI\tID\tName\tAuthor\tQuantity\tRack\n");
    printf("\n\tSI\tID\tName\tAuthor\t\tQuan\tRack\n");
    file=fopen("books.txt","rb");
    while(fread(&a,sizeof(a),1,file)==1)
    {
        printf("\n\t%d",++i);
        printf("\t%d",a.id);
        printf("\t%s",a.name);
        printf("\t%s",a.author);
        printf("\t\t %d",a.quantity);
        printf("\t %d\n",a.rack);
        count+=a.quantity;
    }
    fclose(file);
    printf("\n\t\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB2 Total Books : %d \xB2\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\n",count);
    printf("\n\t Press any key...");
    fflush(stdin);
    getchar();
    mainMenu();
}
void searchBook()
{
    int s,count=0,s_id;
    char s_name[30];
    system("cls");
    printf("\n\n\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 - Search Book List -  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\n\t 1. Search by ID\t 2. Search by Name\n");
    printf("\n\t\xDB\xDB\xDB\xDB\xDB ");

    scanf("%d",&s_id);
    printf("\n\t\xDB\xDB\xDB\xDB\xB2 Searching...  \n");
    if(s_id==1 || s_id==2)
    {

        if(s_id==1)
        {
            //printf("\t\xDB\xDB\xDB\xDB\xB2 Searching...  \n");
            file=fopen("books.txt","rb");
            printf("\n\n\t Enter ID : ");
            scanf("%d",&s);
            while(fread(&a,sizeof(a),1,file)==1)
            {
                if(s==a.id)
                {
                    printf("\n\t Book is Found->\n");
                    printf("\n\t Books ID : %d\n",a.id);
                    printf("\n\t Name : %s\n",a.name);
                    printf("\n\t Author : %s\n",a.author);
                    printf("\n\t Quantity : %d\n",a.quantity);
                    printf("\n\t Rack No : %d\n",a.rack);
                    count=1;
                }
            }
            if(count==0)
            {
                printf("\n\t Book is NOT Found !");
            }
            printf("\n\t Press any key...");
            fflush(stdin);
            getchar();
            mainMenu();
        }
        else if(s_id==2)
        {
            //printf("\n\n\t\xDB\xDB\xDB\xDB\xB2 Searching...  \n");
            file=fopen("books.txt","rb");
            printf("\n\n\t Enter Name : ");
            scanf("%s",s_name);
            while(fread(&a,sizeof(a),1,file)==1)
            {
                if(strcmp(a.name,s_name)==0)
                {
                    printf("\n\t Book is Found->\n");
                    printf("\n\t Books ID : %d\n",a.id);
                    printf("\n\t Name : %s\n",a.name);
                    printf("\n\t Author : %s\n",a.author);
                    printf("\n\t Quantity : %d\n",a.quantity);
                    printf("\n\t Rack No : %d\n",a.rack);
                    count=1;
                }
            }
            if(count==0)
            {
                printf("\n\t Book is NOT Found !");
            }
            printf("\n\t Press any key...");
            fflush(stdin);
            getchar();
            mainMenu();
        }
    }
    else
    {
        printf("\n\tWrong Input ! please Enter 1 or 2..\n");
        searchBook();
    }

}
void editbooks()
{
    int e,count=0;
    system("cls");
    printf("\n\n\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 - Edit Book -  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    file=fopen("books.txt","rb+");
    printf("\n\t\xDB\xDB\xDB\xDB\xDB Enter id : ");
    scanf("%d",&e);
    while(fread(&a,sizeof(a),1,file)==1)
    {
        if(e==a.id)
        {
            printf("\n\t\xDB\xDB\xDB\xDB\xB2 Book is Available\n");
            printf("\n\t ID : %d",a.id);
            printf("\n\t Enter New Name : ");
            scanf("%s",a.name);
            printf("\n\t Enter New Author : ");
            scanf("%s",a.author);
            printf("\n\t Enter New Quantity : ");
            scanf("%d",&a.quantity);
            printf("\n\t Enter New Rack No : ");
            scanf("%d",&a.rack);
            fseek(file,ftell(file)-sizeof(a),0);//moving courser inisial position
            fwrite(&a,sizeof(a),1,file);
            fclose(file);
            count =1;
        }
        if(count==0)
        {
            printf("\n\t Book is NOT Found !");
        }
        printf("press any key...");
        fflush(stdin);
        getchar();
        mainMenu();

    }

}
void deletebooks()
{
    system("cls");
    int D,count=0;
    printf("\n\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 - Delete Records - \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\n\tEnter ID : ");
    scanf("%d",&D);
    file= fopen("books.txt","rb+");
    rewind(file);
    while(fread(&a,sizeof(a),1,file)==1)
    {
        if(D==a.id)
        {
            printf("\n\tBooks is Available.\n");
            printf("\n\tBook Name is : %s",a.name);
            printf("\n\tBook Rack No : %d",a.rack);
            count=1;

        }
    }
    if(count==0)
    {
        printf("\n\t Book is not found Under this ID!");
    }
    else
    {
        copy_file = fopen("copy_books.txt","wb+");
        rewind(file);
        while(fread(&a,sizeof(a),1,file)==1)
        {
            if(D!=a.id)
            {
                fseek(copy_file,ftell(copy_file)-sizeof(a),0);//For courser position initial
                fwrite(&a,sizeof(a),1,copy_file);
            }
        }
        fclose(file);//close main file
        fclose(copy_file);//close 2nd file

        remove("books.txt");
        rename("copy_books.txt","books.txt");
        file=fopen("books.txt","rb");
        fclose(file);
    }
    printf("\n\t Press any key...");
    fflush(stdin);
    getchar();
    mainMenu();

}
void help()
{
    system("cls");
    printf("\n\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 - HELP - \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\xDB\xDB\xDB\xDB\xB2  Library management system   ");
    printf("\n\n\t\xDB\xDB\xDB\xDB\xB2  password : admin   ");
    printf("\n\n\t\xDB\xDB\xDB\xDB\xB2  All feature under MAIN MENU   ");
    printf("\n\n\t\xDB\xDB\xDB\xDB\xB2  Add Books   ");
    printf("\n\n\t\xDB\xDB\xDB\xDB\xB2  View Book list");
    printf("\n\n\t\xDB\xDB\xDB\xDB\xB2  Search Books");
    printf("\n\n\t\xDB\xDB\xDB\xDB\xB2  Edit Book's Record");
    printf("\n\n\t\xDB\xDB\xDB\xDB\xB2  Delete books");
    printf("\n\n\t\xDB\xDB\xDB\xDB\xB2  Close Application");
    printf("\n\n\t\xDB\xDB\xDB\xDB\xB2  Press any key ....to back main menu\n");
    printf("\n\t\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB2-Thank You -\xB2\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
    printf("\tpress any key..");
    fflush(stdin);
    getchar();
    mainMenu();
    //getch();


}
void close()
{
    int i;
    system("cls");
    printf("\n\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 - Library management system - \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
    printf("\n\t Exiting in 3 second........\n\n");
    printf("\n\t\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xB2-Thank You -\xB2\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
    Sleep(3000);

    exit(0);


}



void heading()
{
    system("cls");
    printf("\n\n\t");
    char d[50]=" Library Management System";

    int i=0,j;
    for(j=0; j<20; j++)
    {
        Sleep(50);
        printf("*");
    }
    for(j=0; j<27; j++)
    {
        Sleep(50);
        printf("%c",d[j]);
    }
    for(j=0; j<20; j++)
    {
        Sleep(50);
        printf("*");
    }


//    fflush(stdin);
//    getch();
}
void password()
{
    heading();

    char pwd1[10]= {"admin"};//This is password

    char pwd2[10], ch;
    int i, j;

   printf("\n\n\tEnter password : ");
    for(i = 0; i < 10; i++)
    {
        ch = getch();
        if(ch == 13)
            break;
        pwd2[i] = ch;
        ch = '*' ;
        printf("%c ", ch);
    }

    if(strcmp(pwd1,pwd2)==0)
    {
        printf("\n\n\tmatch password!\n");
        printf("\n\n\tpress any key...");

    }
    else
    {
        if(d==3)
        {
            exit(0);
        }

        printf("\n\n\tworng password . Dont try after %d to 3 times\n",d);
        printf("\n\n\tTry again...");
        d++;
        fflush(stdin);
        getchar();
        password();
    }
//    fflush(stdin);
//    getchar();
    getch();
    mainMenu();
}
///-------------------------------End program-------------------------------------------------

