#include "../include/function.h"
#include "../include/datatype.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<windows.h>
#include<ctype.h>
void menuStart(int *menu) {
    do {
        printf("\n*** Student Management System Using C ***\n");
        printf("\n\t    CHOOSE YOUR ROLE\n");
        printf("\t=======================\n");
        printf("\t[1] Admin.\n");
        printf("\t[2] Student.\n");
        printf("\t[3] Teacher.\n");
        printf("\t[4] Exit the Program.\n");
        printf("\n\tEnter your choice: ");
        if (scanf("%d", menu) != 1) {
            printf("Invalid input! Exiting.\n");
            exit(1);
        }
    } while (*menu < 1 || *menu > 4);
}
void studentMenu(){
	printf("\n\t     *** Student Menu ***\n");
	printf("\t=============================\n");
    printf("\t[1]. Show student list\n");
    printf("\t[2]. Add a new student\n");
    printf("\t[3]. Edit student information\n");
    printf("\t[4]. Search a student by name\n");
    printf("\t[5]. Sort a student by name\n");
    printf("\t[6]. Delete a student by name\n");
    printf("\t[7] Exit\n");
    printf("\n\tEnter your choice: ");
}
int load_file(struct Student *students, int *n) {
    if (students == NULL || n == NULL) {
        printf("Error: Invalid input to load_file ^ ^\n");
        return 0;
    }
    FILE *file = fopen("students.dat", "rb");
    if (file == NULL) {
        printf("Error: Could not open file %s for reading.\n", "students.dat");
        return 0;
    }
    if (fread(n, sizeof(int), 1, file) != 1) {
        printf("Error: Could not read the number of students.\n");
        fclose(file);
        return 0;
    }
    if (fread(students, sizeof(struct Student), *n, file) != (size_t)*n) {
        printf("Error: Could not read student data.\n");
        fclose(file);
        return 0;
    }
    fclose(file);
    printf("Data loaded from %s successfully. Total students: %d.\n", "students.dat", *n);
    return 1;
}
void show_student_list(struct Student *students[], int *n) {
    if (*n == 0) {
        printf("\n\t\t\t\t\t**** No Students Found ****\n");
        return;
    }
    printf("\n\t\t\t\t\t**** All Students List ****\n");
    printf("\n");
    printf("|========================================================================================================|\n");
    printf("| ID | Classroom |   Name         | Birthdate  | Gender  | Email               | Phone         | Courses |\n");
    printf("|____|___________|________________|____________|_________|_____________________|_______________|_________|\n");
    for (int i = 0; i < *n; i++) {
        printf("| %-2s | %-9s | %-14s | %02d/%02d/%04d | %-7s | %-19s | %-13s | %-7d |\n",
               students[i]->student_id,    
               students[i]->classroom,
               students[i]->name,
               students[i]->date.day,
               students[i]->date.month,
               students[i]->date.year,
               students[i]->gender ? "Male" : "Female",
               students[i]->email,
               students[i]->phone,
               students[i]->number_course);
    }
    printf("---------------------------------------------------------------------------------------------------------\n");
}
void addStudent(struct Student students[], int *n) {
    if (*n >= 100) {
        printf("Error: Maximum student limit reached (100 students).\n");
        return;
    }
    struct Student new_student;
    while (1) {
        printf("\tInput ID: ");
        fgets(new_student.student_id, sizeof(new_student.student_id), stdin);
        new_student.student_id[strcspn(new_student.student_id, "\n")] = '\0'; 
        if (strlen(new_student.student_id) == 0) {
            printf("Error: ID cannot be empty.\n");
        } else if (strlen(new_student.student_id) > 9) {
            printf("Error: ID cannot exceed 9 characters.\n");
        } else {
            break;
        }
    }
    while (1) {
        printf("\tInput classroom: ");
        fgets(new_student.classroom, sizeof(new_student.classroom), stdin);
        new_student.classroom[strcspn(new_student.classroom, "\n")] = '\0';
        if (strlen(new_student.classroom) == 0) {
            printf("Error: Classroom cannot be empty.\n");
        } else if (strlen(new_student.classroom) > 10) {
            printf("Error: Classroom cannot exceed 10 characters.\n");
        } else {
            break;
        }
    }
    while (1) {
        printf("\tInput name: ");
        fgets(new_student.name, sizeof(new_student.name), stdin);
        new_student.name[strcspn(new_student.name, "\n")] = '\0';
        if (strlen(new_student.name) == 0) {
            printf("Error: Name cannot be empty ^ ^\n");
        } else if (strlen(new_student.name) > 49) {
            printf("Error: Name cannot exceed 49 characters ^ ^\n");
        } else {
            break;
        }
    }
    while (1) {
        printf("\tInput birthdate (day month year): ");
        if (scanf("%d %d %d", &new_student.date.day, &new_student.date.month, &new_student.date.year) != 3) {
            printf("Error: Invalid date format. Please try again.\n");
            while (getchar() != '\n');
        } else if (new_student.date.day < 1 || new_student.date.day > 31 ||
                   new_student.date.month < 1 || new_student.date.month > 12 ||
                   new_student.date.year < 1900 || new_student.date.year > 2100) {
            printf("Error: Invalid date. Please enter a valid day, month, and year.\n");
        } else {
            break;
        }
    }
    getchar();
    while (1) {
        printf("\tInput gender (1 for Male, 0 for Female): ");
        if (scanf("%d", &new_student.gender) != 1 || (new_student.gender != 0 && new_student.gender != 1)) {
            printf("Error: Gender must be 1 (Male) or 0 (Female).\n");
            while (getchar() != '\n');
        } else {
            break;
        }
    }
    getchar();
    while (1) {
        printf("\tInput email (without @gmail.com): ");
        fgets(new_student.email, sizeof(new_student.email), stdin);
        new_student.email[strcspn(new_student.email, "\n")] = '\0';
        if (strlen(new_student.email) == 0) {
            printf("Error: Email cannot be empty.\n");
        } else if (strlen(new_student.email) > 30) {
            printf("Error: Email prefix cannot exceed 30 characters.\n");
        } else {
            strcat(new_student.email, "@gmail.com");
            break;
        }
    }
    while (1) {
        printf("\tInput phone: ");
        fgets(new_student.phone, sizeof(new_student.phone), stdin);
        new_student.phone[strcspn(new_student.phone, "\n")] = '\0';
        if (strlen(new_student.phone) == 0) {
            printf("Error: Phone number cannot be empty.\n");
        } else if (strlen(new_student.phone) > 19) {
            printf("Error: Phone number cannot exceed 19 characters.\n");
        } else if (strspn(new_student.phone, "0123456789") != strlen(new_student.phone)) {
            printf("Error: Phone number must contain only digits.\n");
        } else {
            break;
        }
    }
    while (1) {
        printf("\tInput number of courses: ");
        if (scanf("%d", &new_student.number_course) != 1 || new_student.number_course < 0) {
            printf("Error: Number of courses must be a positive integer.\n");
            while (getchar() != '\n');
        } else {
            break;
        }
    }
    getchar();
    students[*n] = new_student;
    (*n)++;
    printf("\nStudent added successfully!\n");
}
void editStudent(struct Student *students[], int *n) {
    if (*n <= 0) {
        printf("\n\tNo student data to edit ^ ^\n");
        return;
    }
    char student_id[20];
    printf("\nEnter the ID of the student to edit: ");
    scanf("%s", student_id);
    getchar();

    int found = -1;
    for (int i = 0; i < *n; i++) {
        if (strcmp(students[i]->student_id, student_id) == 0) {
            found = i;
            break;
        }
    }
    if (found == -1) {
        printf("Student with ID %s not found.\n", student_id);
        return;
    }
    struct Student *student = students[found];
    printf("\nEditing information for student ID: %s\n", student_id);
    while (1) {
        printf("Classroom (current: %s): ", student->classroom);
        char temp_classroom[11];
        fgets(temp_classroom, sizeof(temp_classroom), stdin);
        temp_classroom[strcspn(temp_classroom, "\n")] = '\0';
        if (strlen(temp_classroom) > 0 && strlen(temp_classroom) <= 10) {
            strcpy(student->classroom, temp_classroom);
            break;
        } else {
            printf("Error: Classroom must be 1-10 characters. Please try again.\n");
        }
    }
    while (1) {
        printf("Name (current: %s): ", student->name);
        char temp_name[50];
        fgets(temp_name, sizeof(temp_name), stdin);
        temp_name[strcspn(temp_name, "\n")] = '\0';
        if (strlen(temp_name) > 0 && strlen(temp_name) <= 49) {
            strcpy(student->name, temp_name);
            break;
        } else {
            printf("Error: Name cannot exceed 49 characters. Please try again.\n");
        }
    }
    while (1) {
        printf("Birthdate (day/month/year) (current: %02d/%02d/%04d): ",
               student->date.day, student->date.month, student->date.year);
        int day, month, year;
        if (scanf("%d/%d/%d", &day, &month, &year) == 3 &&
            day >= 1 && day <= 31 &&
            month >= 1 && month <= 12 &&
            year >= 1900 && year <= 2100) {
            student->date.day = day;
            student->date.month = month;
            student->date.year = year;
            break;
        }
        printf("Error: Invalid date. Please try again.\n");
        getchar();
    }
    while (1) {
        printf("Gender (1 for Male, 0 for Female) (current: %s): ",
               student->gender ? "Male" : "Female");
        int gender_input;
        if (scanf("%d", &gender_input) == 1 && (gender_input == 0 || gender_input == 1)) {
            student->gender = gender_input;
            break;
        }
        printf("Error: Gender must be 1 (Male) or 0 (Female). Please try again.\n");
        getchar();
    }
    getchar();
    while (1) {
        printf("Email (current: %s): ", student->email);
        char temp_email[20];
        fgets(temp_email, sizeof(temp_email), stdin);
        temp_email[strcspn(temp_email, "\n")] = '\0';
        if (strlen(temp_email) > 0 && strlen(temp_email) <= 14) {
            strcat(temp_email, "@gmail.com");
            strcpy(student->email, temp_email);
            break;
        } else {
            printf("Error: Email prefix cannot exceed 14 characters. Please try again.\n");
        }
    }
    while (1) {
        printf("Phone (current: %s): ", student->phone);
        char temp_phone[20];
        fgets(temp_phone, sizeof(temp_phone), stdin);
        temp_phone[strcspn(temp_phone, "\n")] = '\0';
        if (strlen(temp_phone) > 0 && strlen(temp_phone) <= 19 && strspn(temp_phone, "0123456789") == strlen(temp_phone)) {
            strcpy(student->phone, temp_phone);
            break;
        } else {
            printf("Error: Phone number must be numeric and cannot exceed 19 digits. Please try again.\n");
        }
    }
    while (1) {
        printf("Number of courses (current: %d): ", student->number_course);
        int courses;
        if (scanf("%d", &courses) == 1 && courses >= 0) {
            student->number_course = courses;
            break;
        }
        printf("Error: Number of courses must be a non-negative integer. Please try again.\n");
        getchar();
    }
    printf("\nStudent information updated successfully.\n");
}
void searchStudent(struct Student *students[], int *n) {
    if (*n <= 0) {
        printf("\n\tNo student data to search ^ ^\n");
        return;
    }
    char search[50];
    while (1) {
        printf("Enter the name or part of the name to search (1-49 characters): ");
        fgets(search, sizeof(search), stdin);
        search[strcspn(search, "\n")] = '\0';
        if (strlen(search) == 0) {
            printf("Error: Search string cannot be empty. Please try again.\n");
        } else if (strlen(search) > 49) {
            printf("Error: Search string is too long (maximum 49 characters). Please try again.\n");
        } else {
            break;
        }
    }
    int found = 0;
    printf("\nSearching for students with name containing \"%s\"...\n", search);
    for (int i = 0; i < *n; i++) {
        if (strstr(students[i]->name, search) != NULL) {
            if (found == 0) {
                printf("\n\tStudent information found:\n");
                printf("|========================================================================================================|\n");
                printf("| ID        | Classroom | Name            | Birthdate  | Gender  | Email               | Phone         | Courses |\n");
                printf("|___________|___________|_________________|____________|_________|_____________________|_______________|_________|\n");
            }
            printf("| %-9s | %-9s | %-15s | %02d/%02d/%04d | %-7s | %-19s | %-13s | %-7d |\n",
                   students[i]->student_id,
                   students[i]->classroom,
                   students[i]->name,
                   students[i]->date.day,
                   students[i]->date.month,
                   students[i]->date.year,
                   students[i]->gender ? "Male" : "Female",
                   students[i]->email,
                   students[i]->phone,
                   students[i]->number_course);
            found++;
        }
    }
    if (found == 0) {
        printf("No students found matching \"%s\".\n", search);
    } else {
        printf("|========================================================================================================|\n");
    }
}
void deleted(struct Student *students[], int *n) {
    if (*n <= 0) {
        printf("\n\tNo student data ^ ^\n");
        return;
    }
    printf("Input the ID of the student to delete: ");
    char id[20];
    getchar(); 
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = '\0';
    int index = -1;
    for (int i = 0; i < *n; i++) {
        if (strcmp(students[i]->student_id, id) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Student with ID: %s not found.\n", id);
        return;
    }
    printf("Student found with ID: %s\n", id);
    printf("|========================================================================================================|\n");
    printf("| ID | Classroom |   Name         | Birthdate  | Gender  | Email               | Phone         | Courses |\n");
    printf("|____|___________|________________|____________|_________|_____________________|_______________|_________|\n");
    printf("| %-9s | %-9s | %-15s | %02d/%02d/%04d | %-7s | %-19s | %-13s | %-7d |\n",
           students[index]->student_id,
           students[index]->classroom,
           students[index]->name,
           students[index]->date.day,
           students[index]->date.month,
           students[index]->date.year,
           students[index]->gender ? "Male" : "Female",
           students[index]->email,
           students[index]->phone,
           students[index]->number_course);
    printf("|========================================================================================================|\n");
    printf("Are you sure you want to delete this student? (YES/NO): ");
    char confirm[10];
    scanf("%s", confirm);
    for (int i = 0; confirm[i]; i++) {
        confirm[i] = toupper(confirm[i]);
    }
    if (strcmp(confirm, "YES") == 0) {
        free(students[index]);
        for (int i = index; i < *n - 1; i++) {
            students[i] = students[i + 1];
        }
        (*n)--;
        printf("Student deleted successfully ^ ^\n");
    } else if (strcmp(confirm, "NO") == 0) {
        printf("Deletion canceled.\n");
    } else {
        printf("Invalid input. Deletion canceled.\n");
    }
}
//0giam1tang
void sort_Student_i_or_d(struct Student *students[], int *n) {
    if (*n <= 0) {
        printf("\n\tNo student data to sort ^ ^\n");
        return;
    }
    char choice;
    int check = 0;
    do {
        printf("Choose the order in which the student list is sorted:\n");
        printf("\n\t\t[1]. Increase\n");
        printf("\t\t[2]. Decrease\n");
        printf("\n\tYour choice: ");
        while (getchar() != '\n');
        scanf("%c", &choice);
    } while (choice != '1' && choice != '2');
    check = (choice == '1' ? 1 : 0);
    for (int i = 0; i < *n - 1; i++) {
        for (int j = i + 1; j < *n; j++) {
            if (check ? strcmp(students[i]->name, students[j]->name) > 0 :
                        strcmp(students[i]->name, students[j]->name) < 0) {
                struct Student *temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
    printf("\nThe list of students after sorting is:\n");
    printf("\n\t\t|========================================================================================================|\n");
    printf("\t\t| ID | Classroom |   Name         | Birthdate  | Gender  | Email               | Phone         | Courses |\n");
    printf("\t\t|____|___________|________________|____________|_________|_____________________|_______________|_________|\n");
    for (int i = 0; i < *n; i++) {
        printf("\t\t| %-9s | %-9s | %-15s | %02d/%02d/%04d | %-7s | %-19s | %-13s | %-7d |\n",
                students[i]->student_id,
                students[i]->classroom,
                students[i]->name,
                students[i]->date.day,
                students[i]->date.month,
                students[i]->date.year,
                students[i]->gender ? "Male" : "Female",
                students[i]->email,
                students[i]->phone,
                students[i]->number_course);
    }
    printf("\t\t----------------------------------------------------------------------------------------------------------\n");
}
void save_file(struct Student *students[], int n) {
    if (n <= 0 || students == NULL) {
        printf("No student data to save.\n");
        return;
    }
    FILE *file = fopen("students.dat", "wb");
    if (file == NULL) {
        printf("Error: Could not open file %s for writing.\n", "students.dat");
        return;
    }
    fwrite(&n, sizeof(int), 1, file);
    for (int i = 0; i < n; i++) {
        fwrite(students[i], sizeof(struct Student), 1, file);
    }
    fclose(file);
    printf("Data saved to %s successfully.\n", "students.dat");
}
//In kieu ms(mili/s)
void printSlowly(const char *mes, int delay){
	for(int i = 0; mes[i] != '\0'; i++){
		printf("%c",mes[i]);
		fflush(stdout);
		Sleep(delay);
	}
}
//In ket thuc chuong trinh
void printfinish(){
	printf("\n\t\t========== Thank You ==========");
	printf("\n\t\t ======= See You Soon ========");
}
void back_or_exit(){
	char choice;
    while(1){
	printf("\n\t\tGo back (b) or Exit (0) ? : ");
	fflush(stdin);
	scanf("%c",&choice);
	if(choice == '0'){
		printSlowly("\n\tExiting program",40);
		printSlowly("...\n",160);
		printfinish();
		exit(0);
	}else if(choice == 'b'){
		return;
		//in la loi do
	}else{
		printSlowly("\n\t\t\tInvalid choice",100);
		printSlowly(" !!!\n",180);
	}
    }
}
