#ifndef CODE_H
#define CODE_H

void addstudent();
void studentrecord();
void searchstudent();
void studentmarks();
void studentdelete();
void sortstudents();

struct student {
    char sname[30];
    char fname[30];
    int hallticket;
    char course[10];
    char add[20];
    int marks[6];
    unsigned long long phno;
};

void addstudent() {
    char another;int i;
    FILE *fp;
    struct student info;
    int prevhtno = 0;

    fp = fopen("information.txt", "a+");
    if (fp == NULL) {
        fprintf(stderr, "Can't open file");
        exit(0);
    }

    rewind(fp);

    while (fscanf(fp, "%d", &info.hallticket) == 1) {
        if (info.hallticket > prevhtno) {
            prevhtno = info.hallticket;
        }
        fscanf(fp, ",%[^,],%[^,],%[^,],%[^,],%llu", info.sname, info.fname, info.course, info.add, &info.phno);
        for (i = 0; i < 6; i++) {
            fscanf(fp, ",%d", &info.marks[i]);
        }
       
    }

    do {
      printf("\n\n\t\t\t|------------------------------------------------------|");
        printf("\n\t\t\t|                 ADD STUDENTS INFO                    |");
        printf("\n\t\t\t|------------------------------------------------------|");

        printf("\n\n\t\t\t///////Previous Hall ticket no : %d///////////", prevhtno);

        printf("\n\n\t\t\t Enter Hallticket-No  : ");
        scanf("%d", &info.hallticket);
        prevhtno = info.hallticket;
        printf("\n\t\t\t Enter Name           : ");
        scanf(" %[^\n]s", info.sname);
        printf("\n\t\t\t Enter father's Name  : ");
        scanf(" %[^\n]s", info.fname);
        printf("\n\t\t\t Enter course         : ");
        scanf("%s", info.course);
        printf("\n\t\t\t Enter Address        : ");
        scanf(" %[^\n]s", info.add);
        printf("\n\t\t\t Enter phone no       : ");
        scanf("%llu", &info.phno);
        for (i=0;i<6;i++) {
            printf("\n\t\t\t-> Enter marks scored in subject %d   : ", i + 1);
            scanf("%d", &info.marks[i]);
        }
        printf("\n\t\t\t________________________________________\n");

        printf("\t\t\tRecord stored successfully\n");

        fprintf(fp, "%d,%s,%s,%s,%s,%llu", info.hallticket, info.sname, info.fname, info.course, info.add, info.phno);
        for (i = 0; i < 6; i++) {
            fprintf(fp, ",%d", info.marks[i]);
        }
        fprintf(fp, "\n");

        printf("\t\t\tYou want to add another record? (y/n) : ");
        scanf(" %c", &another);

    } while (another == 'y' || another == 'Y');

    fclose(fp);
}

void studentrecord() {
    FILE *fp;int i;
    struct student info;
    fp = fopen("information.txt", "r");

  printf("\n\n\t\t|--------------------------------------------------------------------------------------------------------------------------|");
    printf("\n\t\t|                                              STUDENT RECORD                                                              |");
    printf("\n\t\t|--------------------------------------------------------------------------------------------------------------------------|");

    if (fp == NULL) {
        fprintf(stderr, "Can't open file\n");
        exit(0);
    }
    printf("\n\n\t _______________________________________________________________________________________________________________________________________________________");
    printf("\n\t|   HT.NO\t|   Name\t\t\t|   Father's Name\t\t|  Course\t|   Address\t\t\t|   Phone Number        |");
    printf("\n\t|_______________|_______________________________|_______________________________|_______________|_______________________________|_______________________|");

    while (fscanf(fp, "%d,%[^,],%[^,],%[^,],%[^,],%llu", &info.hallticket, info.sname, info.fname, info.course, info.add, &info.phno) == 6) {
        for (i = 0; i < 6; i++) {
            fscanf(fp, ",%d", &info.marks[i]);
        }
        fscanf(fp, "\n");

        printf("\n\t|\t%-8d|%-24s\t|%-24s\t|%-10s\t|%-24s\t|%llu\t\t|", info.hallticket, info.sname, info.fname, info.course, info.add, info.phno);
    printf("\n\t|_______________|_______________________________|_______________________________|_______________|_______________________________|_______________________|");
    }

    fclose(fp);
    printf("\n\n\t\t\t\tPress any key to exit..... \n");
    getch();
}

    
    void searchstudent() {
    struct student info;
    FILE *fp;
    int roll_no, found = 0;
    int i;

    fp = fopen("information.txt", "r");
    printf("\n\n\t\t\t|------------------------------------------------------|");
    printf("\n\t\t\t|               SEARCH STUDENT RECORD                  |");
    printf("\n\t\t\t|------------------------------------------------------|");

    printf("\n\n\t\t\tEnter the roll no : ");
    scanf("%d", &roll_no);

    while (fscanf(fp, "%d,%[^,],%[^,],%[^,],%[^,],%llu", &info.hallticket, info.sname, info.fname, info.course, info.add, &info.phno) == 6) {
        for (i = 0; i < 6; i++) {
            fscanf(fp, ",%d", &info.marks[i]);
        }
        fscanf(fp, "\n");

        if (info.hallticket == roll_no) {
            found = 1;
            printf("\n\t\t\t\t Roll NO         : %d", info.hallticket);
            printf("\n\t\t\t\t Student Name    : %s", info.sname);
            printf("\n\t\t\t\t Father's Name   : %s", info.fname);
            printf("\n\t\t\t\t Class           : %s", info.course);
            printf("\n\t\t\t\t address         : %s", info.add);
            printf("\n\t\t\t\t phone number    : %llu", info.phno);
            printf("\n\t\t\t\t Recent marks of  student:");
            for (i=0;i<6;i++) {
                printf("\n\t\t\t marks scored in subject %d  :%d ", i + 1, info.marks[i]);
            }
            printf("\n\t\t\t______________________________________\n");
        }
    }

    if (!found) {
        printf("\n\t\t\tRecord not found\n");
    }

    fclose(fp);
    printf("\n\n\t\t\t\tPress any key to exit.......\n");
    getch();
}

void studentmarks() {
    struct student info;
    FILE *fp;
    int roll_no, found = 0;
    int i;
    float total = 0, percentage;

    fp = fopen("information.txt", "r");
  printf("\n\n\t\t\t|------------------------------------------------------|");
    printf("\n\t\t\t|                SEARCH STUDENT MARKS                  |");
    printf("\n\t\t\t|------------------------------------------------------|");

    printf("\n\n\t\t\tEnter the roll no : ");
    scanf("%d", &roll_no);

    while (fscanf(fp, "%d,%[^,],%[^,],%[^,],%[^,],%llu", &info.hallticket, info.sname, info.fname, info.course, info.add, &info.phno) == 6) {
        for (i = 0; i < 6; i++) {
            fscanf(fp, ",%d", &info.marks[i]);
        }
        fscanf(fp, "\n");

        if (info.hallticket == roll_no) {
            found = 1;
            printf("\n\t\t\tRoll No        : %d", info.hallticket);
            printf("\n\t\t\tStudent Name   : %s", info.sname);
            total = 0;
            for (i = 0; i < 6; i++) {
                printf("\n\t\t\t-> marks scored in subject %d  : %d ", i + 1, info.marks[i]);
                total += info.marks[i];
            }
            percentage = ((total * 100) / 600);
            printf("\n\t\t\tTotal Marks scored     : %.0f", total);
            printf("\n\t\t\tPercentage             : %.2f%%", percentage);
            printf("\n\t\t\t______________________________________\n");
        }
    }

    if (!found) {
        printf("\n\t\t\tRecord not found\n");
    }

    fclose(fp);
    printf("\n\n\t\t\t\tPress any key to exit.......\n");
    getch();
}
void sortstudents() { int k;
    struct student info[100];
    FILE *fp;
    int count = 0, i, j;

    fp = fopen("information.txt", "r");

    if (fp == NULL) {
        fprintf(stderr, "Can't open file\n");
        exit(0);
    }

    while (fscanf(fp, "%d,%[^,],%[^,],%[^,],%[^,],%llu", &info[count].hallticket, info[count].sname, info[count].fname, info[count].course, info[count].add, &info[count].phno) == 6) {
        for (i = 0; i < 6; i++) {
            fscanf(fp, ",%d", &info[count].marks[i]);
        }
        fscanf(fp, "\n");
        count++;
    }
    fclose(fp);

    for (i = 0; i < count - 1; i++) {
        for (j = 0; j < count - i - 1; j++) {
            int total_marks_j = 0;
            for (k = 0; k < 6; k++) {
                total_marks_j += info[j].marks[k];
            }

            int total_marks_j_next = 0;
            for (k = 0; k < 6; k++) {
                total_marks_j_next += info[j + 1].marks[k];
            }

            if (total_marks_j < total_marks_j_next) {
                struct student temp = info[j];
                info[j] = info[j + 1];
                info[j + 1] = temp;
            }
        }
    }
  printf("\n\n\t\t\t|------------------------------------------------------|");
    printf("\n\t\t\t|                  STUDENT LEADERBOARD                 |");
    printf("\n\t\t\t|------------------------------------------------------|");
	
  printf("\n\n\t\t __________________________________________________________________________________________________");
    printf("\n\t\t|   Rank    | HTNO      | Name\t\t\t          |  Total Marks         |   Percentage    |");
    printf("\n\t\t|___________|___________|_________________________________|______________________|_________________|");

    for (i = 0; i < count; i++) {
        int total_marks_i = 0;
        for (k = 0; k < 6; k++) {
            total_marks_i += info[i].marks[k];
        }

        float percentage_i = (total_marks_i / 600.0) * 100;

        printf("\n\t\t|   %d\t    |    %d\t|%-24s\t  |      %-15d |      %.2f      |", i + 1, info[i].hallticket,info[i].sname, total_marks_i, percentage_i);
        printf("\n\t\t|___________|___________|_________________________________|______________________|_________________|");
    }
    printf("\n");
	printf("\n\n\t\t\t\tPress any key to exit.......\n");
    getch();
}

void studentdelete() {
    struct student info;
    FILE *fp, *fp1;int i;

    int roll_no, found = 0;

  printf("\n\n\t\t\t|------------------------------------------------------|");
    printf("\n\t\t\t|                DELETE STUDENT RECORD                 |");
    printf("\n\t\t\t|------------------------------------------------------|");

    fp=fopen("information.txt", "r");
    if (fp==NULL) {
        fprintf(stderr,"can't open file\n");
        exit(0);
    }

    fp1 = fopen("temp.txt", "w");
    if (fp1 == NULL) {
        fclose(fp);
        exit(0);
    }

    printf("\n\n\t\t\t\tEnter the roll no : ");
    scanf("%d", &roll_no);

    while (fscanf(fp, "%d,%[^,],%[^,],%[^,],%[^,],%llu", &info.hallticket, info.sname, info.fname, info.course, info.add, &info.phno) == 6) {
        for (i=0;i<6;i++) {
            fscanf(fp,",%d",&info.marks[i]);
        }
        fscanf(fp,"\n");

        if (info.hallticket == roll_no) {
            found = 1;
        } else {
            fprintf(fp1,"%d,%s,%s,%s,%s,%llu", info.hallticket, info.sname, info.fname, info.course, info.add, info.phno);
            for (i = 0; i < 6; i++) {
                fprintf(fp1, ",%d", info.marks[i]);
            }
            fprintf(fp1, "\n");
        }
    }

    fclose(fp);
    fclose(fp1);

    if (!found) {
        printf("\n\t\t\t\tRecord not found\n");
    } else {
        if (found) {
            remove("information.txt");
            rename("temp.txt", "information.txt");
            printf("\n\t\t\t\tRecord deleted successfully\n");
        }
    }

    printf("\n\n\t\t\t\tPress any key to exit.......\n");
    getch();
}
#endif
