#include<stdio.h>
#include<stdlib.h> 
#include<string.h>
#include "code.h"

int main()
{
    int choice;
    struct student info;
    while(1){
  printf("\n\n\t\t\t|------------------------------------------------------|");     
    printf("\n\t\t\t|*********** SR UNIVERSITY STUDENT PORTAL *************|");
    printf("\n\t\t\t|------------------------------------------------------|"); 
printf("\n\n\t\t\t      _____________________\n");
    printf("\t\t\t     |        MENU         |\n");
    printf("\t\t\t     |_____________________|\n");
    printf("\t\t\t     | 1.| Add Student     |\n");
    printf("\t\t\t     |___|_________________|\n");
    printf("\t\t\t     | 2.| Students Records|\n");
    printf("\t\t\t     |___|_________________|\n");
    printf("\t\t\t     | 3.| Search Student  |\n");
    printf("\t\t\t     |___|_________________|\n");
    printf("\t\t\t     | 4.| Student Marks   |\n");
    printf("\t\t\t     |___|_________________|\n");
    printf("\t\t\t     | 5.| Leaderboard     |\n");
    printf("\t\t\t     |___|_________________|\n");
    printf("\t\t\t     | 6.| Delete Student  |\n");
    printf("\t\t\t     |___|_________________|\n");
    printf("\t\t\t     | 7.| Exit            |\n");
    printf("\t\t\t     |___|_________________|\n");
    printf("\n\t\t\t     Enter your choice : ");
    scanf("%d",&choice);
    printf("\n\t\t\t--------------------------------------------------------");

   switch(choice){
     case 1:
          addstudent();
         break;
     case 2: 
          studentrecord();
         break;
        
     case 3:
         searchstudent();
         break;
     case 4:
         studentmarks();
         break;
         
     case 5:
        sortstudents();
        break;    
        
     case 6:
        studentdelete();
        break;

     case 7:
          printf("\n\t\t\t\tThank you, for using this software.\n\n");
          exit(0);
        break;
        
     default :
         printf("\n\t\t\t\t\tEnter a valid number\n\n");
         printf("\t\t\t\tPress any key to continue.......");
         getch();
         break;
        }
    }
        getch();
}