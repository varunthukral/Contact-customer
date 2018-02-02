#include <stdio.h>
#include <conio.h>
#include <string.h>

struct person{
     char name[20];
     long contactno;
};

void appendData(){
      FILE *fp;
      struct person obj;
      fp=fopen("data.txt","a");
      printf("*****Add Record****\n");
      printf("Enter Name : ");
      fflush(stdin);
      gets(&obj.name);
      printf("Enter contact No. : ");
      fflush(stdin);
      scanf("%d",&obj.contactno);
      fprintf(fp,"%s %d",obj.name,obj.contactno);
      fclose(fp);
}

void showAllData(){
      FILE *fp;
      struct person obj;
      fp=fopen("data.txt","r");
      printf("*****Display All Records*****\n");
      printf("\n\n\t\tName\t\t\tcontact No.");
      printf("\n\t\t=====\t\t\t===============\n\n");
      while(!feof(fp))
      {
      fscanf(fp,"%s%d",obj.name,&obj.contactno);
      printf("%s %Ld\n",obj.name,obj.contactno);
      }
      fclose(fp);
      getch();
}

void findData(){
      FILE *fp;
      struct person obj;
      char name[20];
      int totrec=0;
      fp=fopen("data.txt","r");
      printf("*****Display Specific Records*****\n");
      printf("\nEnter Name : ");
      scanf("%s",&name);
      while(!feof(fp))
      {
      fscanf(fp,"%20s %7ld",obj.name,&obj.contactno);
         if(strcmpi(obj.name,name)==0){
        printf("\n\nName   :  %s",obj.name);
        printf("\ncontact No : %ld",obj.contactno);
        totrec++;
         }
      }
      if(totrec==0)
         printf("\n\n\nNo Data Found");
      else
         printf("\n\n===Total %d Record found===",totrec);
      fclose(fp);
      getch();
}



void main(){
      char choice;
      while(1){

    printf("*****contact list*****\n\n");
    printf("1) Add Record\n");
    printf("2) Find Record\n");
    printf("3) Read all record\n");
    printf("4) exit\n");
    printf("Enter your choice : ");
    fflush(stdin);
    choice = getche();
    switch(choice){
         case'1' : //call append record
            appendData();
            break;
         case'2' : //call find record
             findData();
            break;
         case'3' : //Read all record
            showAllData();
            break;


    }
      }
}
