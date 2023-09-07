#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

struct library{
char serial[20];
char ISBN[14];
char Book_title[50];
char Edition[10];
char Author[50];
char is_Reserved[2];
};

void AddBook();
void displayBook();
void searchBook();
void deleteBook();
void updateBook();
void issueBook();
FILE *fp;
int Menu=0;

int main()
{
 while(1){
        if (Menu==0){
             printf("\n\t\t\t\t\t\t*********************************\t\t\t\t\t\t");
             printf("\n\t\t\t\t\t\t* Welcome To The Library System *\t\t\t\t\t\t\n");
             printf("\t\t\t\t\t\t*********************************\t\t\t\t\t\t\n\n");
        }
        else{
             printf("\n\t\t\t\t\t\t****************************\t\t\t\t\t\t");
             printf("\n\t\t\t\t\t\t* Welcome Back To The Menu *\t\t\t\t\t\t\n");
             printf("\t\t\t\t\t\t****************************\t\t\t\t\t\t\n\n");
        }
    printf("Press 1 to Add a Record\n\nPress 2 to Delete Record\n\nPress 3 to search a Record\n\nPress 4 to update/Modify a book record\n\nPress 5 to display all the book Records\n\nPress 6 to issue the book\n\nPress 7 to Exit\n");
    printf("\n");
    int num;
    scanf("%d",&num);
    if (num==1)
        AddBook();
    else if (num==2)
        deleteBook();
    else if (num==3)
        searchBook();
    else if (num==4)
        updateBook();
    else if (num==5)
        displayBook();
    else if (num==6)
        issueBook();
    else if (num==7)
        exit(1);
    else{
        printf("Wrong input");
        exit(2);
    }
        printf("\n");
        Menu++;
}
}

void AddBook()
{
    struct library b;
    printf("\n\t\t\t\t\t\t***********************************\t\t\t\t\t\t");
    printf("\n\t\t\t\t\t\t* Welcome To The ADD Book Section *\t\t\t\t\t\t\n");
    printf("\t\t\t\t\t\t***********************************\t\t\t\t\t\t\n\n");
    fp=fopen("Library.txt","w");
    if (fp==NULL)
    {
        printf("File not found");
        exit(1);
    }
    printf("\n\t\t\t\t\t\t  ENTER THE INFORMATION IN ORDER\t\t\t\t\t\t\n");
    for (int i=0;i<=4;i++){
        printf("\n");
        printf("Enter Book serial number:\n\n");
        printf("Enter ISBN number:\n\n");
		printf("Enter Book name:\n\n");
		printf("Enter Book Edition year:\n\n");
		printf("Enter Book Author name:\n\n");
		printf("Enter book reserved number:\n\n");
        scanf(" %s %s %s %s %s %s",&b.serial,&b.ISBN,&b.Book_title,&b.Edition,&b.Author,&b.is_Reserved);
        fprintf(fp,"%s\t%s\t%s\t%s\t%s\t%s\n",b.ISBN,b.serial,b.Book_title,b.Edition,b.Author,b.is_Reserved);
    }
    fclose(fp);
}

void displayBook()
{
        struct library b;
     printf("\n\t\t\t\t\t\t***************************************\t\t\t\t\t\t");
    printf("\n\t\t\t\t\t\t* Welcome To The Display Book Section *\t\t\t\t\t\t\n");
    printf("\t\t\t\t\t\t***************************************\t\t\t\t\t\t\n\n");
    fp=fopen("Library.txt","r");
    if (fp==NULL)
    {
        printf("File not found");
        exit(1);
    }
    for (int i=0;i<=4;i++){
    fscanf(fp,"%s\t%s\t%s\t%s\t%s\t%s",b.ISBN,b.serial,b.Book_title,b.Edition,b.Author,b.is_Reserved);
    printf("\n\n");
    printf("Serial:%s\n",b.serial);
    printf("ISBN:%s\n",b.ISBN);
    printf("Book name:%s\n",b.Book_title);
    printf("Edition:%s\n",b.Edition);
    printf("Author:%s\n",b.Author);
    printf("Reservation:%s\n",b.is_Reserved);
    printf("\n");
    }
    fclose(fp);
}

void searchBook()
{
    struct library b[5];
    printf("\n\t\t\t\t\t\t***************************************\t\t\t\t\t\t");
    printf("\n\t\t\t\t\t\t* Welcome To The Search Book Section *\t\t\t\t\t\t\n");
    printf("\t\t\t\t\t\t***************************************\t\t\t\t\t\t\n\n");
    fp=fopen("Library.txt","r");
    if (fp==NULL)
    {
        printf("File not found");
        exit(1);
    }
    for (int i=0;i<=4;i++){
        fscanf(fp,"%s\t%s\t%s\t%s\t%s\t%s",b[i].ISBN,b[i].serial,b[i].Book_title,b[i].Edition,b[i].Author,b[i].is_Reserved);
    }
    fclose(fp);
    printf("Press 1 to search by ISBN\nPress 2 to search by Book name\nPress 3 to search by Author");
    printf("\n");
    int num,value,flag1=0;
    scanf("%d",&num);
    if (num==1){
        char isbn[14];
        printf("Please enter the isbn:");
        scanf("%s",&isbn);
        for (int i=0;i<=4;i++){
            value=strcmp(b[i].ISBN,isbn);
            if (value==0){
                printf("\nBook is found\n");
                flag1=1;
                break;
            }
        }
    }
    else if(num==2){
        char title[50];
        printf("Please enter the Book title:");
        scanf("%s",&title);
        for (int i=0;i<=4;i++){
            value=strcmp(b[i].Book_title,title);
            if (value==0){
                printf("\nBook is found\n");
                flag1=1;
                break;
            }
        }
    }
    else if (num==3){
        char author[50];
        printf("Please enter the Author Name:");
        scanf("%s",&author);
        for (int i=0;i<=4;i++){
            value=strcmp(b[i].Author,author);
            if (value==0){
                printf("\nBook is found\n");
                flag1=1;
                break;
            }
        }
    }
    else{
        printf("Wrong input");
        exit(2);
    }
    if (flag1==0)
        printf("\nBook not found\n");
}

void deleteBook()
{
    FILE *fptr;
    struct library b[5];
    printf("\n\t\t\t\t\t\t***************************************\t\t\t\t\t\t");
    printf("\n\t\t\t\t\t\t* Welcome To The Delete Book Section *\t\t\t\t\t\t\n");
    printf("\t\t\t\t\t\t***************************************\t\t\t\t\t\t\n\n");
    fp=fopen("Library.txt","r");
    if (fp==NULL)
    {
        printf("File not found");
        exit(1);
    }
        for (int i=0;i<=4;i++){
        fscanf(fp,"%s\t%s\t%s\t%s\t%s\t%s",b[i].ISBN,b[i].serial,b[i].Book_title,b[i].Edition,b[i].Author,b[i].is_Reserved);
    }
    fclose(fp);
    fptr=fopen("Library.txt","w");
    if (fptr == NULL)
    {
        printf("File not found");
        exit(1);
    }
    printf("Please enter the book name to delete:");
    char Book[14];
    int value;
    scanf("%s",&Book);
    int flag=0;
    for (int i=0;i<=4;i++){
        value = strcmp(b[i].Book_title,Book);
        if (value==0){
            flag=1;
            continue;
        }
        else{
            fprintf(fptr,"%s\t%s\t%s\t%s\t%s\t%s\n",b[i].ISBN,b[i].serial,b[i].Book_title,b[i].Edition,b[i].Author,b[i].is_Reserved);
        }
    }
        if (flag==0)
            printf("Record was not found");
        else
            printf("Record successfully deleted");
    fclose(fptr);

}

void updateBook()
{
    printf("\n\t\t\t\t\t\t***************************************\t\t\t\t\t\t");
    printf("\n\t\t\t\t\t\t* Welcome To The Update Book Section *\t\t\t\t\t\t\n");
    printf("\t\t\t\t\t\t***************************************\t\t\t\t\t\t\n\n");
   fp=fopen("Library.txt","r");
    if (fp==NULL)
    {
        printf("File not found");
        exit(1);
    }
    struct library b[5];
    for (int i=0;i<=4;i++){
        fscanf(fp,"%s\t%s\t%s\t%s\t%s\t%s",b[i].ISBN,b[i].serial,b[i].Book_title,b[i].Edition,b[i].Author,b[i].is_Reserved);
    }
    fclose(fp);
    char oldBookName[50],newBookName[50];
    int value;
    printf("Please enter the Old book name:");
    fflush(stdin);
    scanf("%s",oldBookName);
    printf("Enter the new book name:");
    fflush(stdin);
    scanf("%s",newBookName);
    int flag=0;
    for (int i=0;i<=4;i++)
    {
        value= strcmp(b[i].Book_title,oldBookName);
        if (value==0)
        {
            strcpy(b[i].Book_title,newBookName);
            flag=1;
        }
    }
    FILE *fptr=fopen("Library.txt","w");
    if (fptr == NULL)
    {
        printf("File not found");
        exit(1);
    }
    for(int i=0;i<=4;i++)
    {
        fprintf(fptr,"%s\t%s\t%s\t%s\t%s\t%s\n",b[i].ISBN,b[i].serial,b[i].Book_title,b[i].Edition,b[i].Author,b[i].is_Reserved);
    }
    fclose(fptr);
    if (flag==1)
        printf("\nRecord Successfully Updated\n");
    else
        printf("\nBook not found-Records not updated\n");
}

void issueBook()
{
    printf("\n\t\t\t\t\t\t***************************************\t\t\t\t\t\t");
    printf("\n\t\t\t\t\t\t* Welcome To The Issue Book Section *\t\t\t\t\t\t\n");
    printf("\t\t\t\t\t\t***************************************\t\t\t\t\t\t\n\n");
    struct library b[5];
    fp=fopen("Library.txt","r");
    if (fp==NULL)
    {
        printf("File not found");
        exit(1);
    }
        for (int i=0;i<5;i++){
        fscanf(fp,"%s\t%s\t%s\t%s\t%s\t%s\n",b[i].ISBN,b[i].serial,b[i].Book_title,b[i].Edition,b[i].Author,b[i].is_Reserved);
    }
    fclose(fp);
    fp=fopen("Library.txt","w");
    if (fp == NULL)
    {
        printf("File not found");
        exit(1);
    }
    char yourname[50];
    printf("Please enter the Book name:");
    scanf("%s",yourname);
    int flag=0,value,reservation;
    //char reserved='1';
    for (int i=0;i<=4;i++)
    {
        value=strcmp(b[i].Book_title,yourname);
        reservation= (int)b[i].is_Reserved[0];
        if (value==0 && reservation == 48)              //ASCII 48 is zero
        {
            printf("Book is issued");
            strcpy(b[i].is_Reserved,"1");
            flag=1;
            break;
        }
    }
    if (flag==0)
        printf("Book cannot be issued-Already issued");
    for(int i=0;i<5;i++)
        {
       fprintf(fp,"%s\t%s\t%s\t%s\t%s\t%s\n",b[i].ISBN,b[i].serial,b[i].Book_title,b[i].Edition,b[i].Author,b[i].is_Reserved);
        }
    fclose(fp);
}
