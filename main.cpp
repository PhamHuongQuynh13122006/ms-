#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "function.h"
#include "datatype.h"

struct Student students[100] = {
    {"1", "ENG_A", "Nguyen Van A", {1, 12, 2000}, true, "TVA@gmail.com", "0123456789", "QAZ123", 3},
    {"2", "ENG_B", "Nguyen Thi V", {23, 5, 2002}, false, "TTV@gmail.com", "0122837333", "qaz468", 4},
    {"3", "ENG_C", "Nguyen Van D", {11, 10, 2004}, true, "TVH@gmail.com", "0738493720", "tdz246", 2},
    {"4", "ENG_D", "Nguyen Van T", {3, 11, 2005}, true, "TVT@gmail.com", "0627392739", "plm678", 5},
    {"5", "ENG_A", "Nguyen Thi B", {18, 2, 2003}, false, "TTB@gmail.com", "0937595931", "ugc789", 1}
};

int n = 5;
int main() {	

	const char *file_name = "students.dat";
    int menu;
    menuStart(&menu);
    switch (menu) {
        case 1:
            printf("Admin role is under development.\n");
            break;
        case 2:
            while (1) {
                int choice;
                system("cls");
                displayMenu();
                scanf("%d", &choice);
                switch (choice) {
                    case 1:
                    	system("cls");
                    	load_file(students, &n, file_name);
                        showAllStudents();
						back_or_exit();
                        break;
                    case 2:
                    	system("cls");
                    	load_file(students, &n, file_name);
                        addStudent();
                        save_file(file_name,students,n);
                        back_or_exit();
                        break;
                    case 3:
                    	system("cls");
                    	load_file(students, &n, file_name);
                        editStudent();
                        save_file(file_name,students,n);
                        back_or_exit();
                        break;
                    case 4:
                    	system("cls");
                    	load_file(students, &n, file_name);
                    	searchStudent();
                    	back_or_exit();
                    	break;
                    case 5:
                    	system("cls");
                    	load_file(students, &n, file_name);
                    	sort_Student_i_or_d(students,n);
                    	save_file(file_name,students,n);
                    	break;
					case 6:
						system("cls");
						load_file(students, &n, file_name);
						deleted(students, &n);
						save_file(file_name,students,n);
						break;
					case 7:
                        printSlowly("\nExisting student menu",50);
                        printSlowly("...",150);
						printfinish();
                        return 0;
                    default:
                        printf("\tInvalid choice. Please try again.\n");/////////
                        break;
                }
            }
            break;
        case 3:
            printf("Teacher role is under development.\n");
            break;
        case 4:
            printSlowly("\n\tExiting program",50);
            printSlowly("...\n",150);
            printfinish();
            exit(0);
            return 0;
        default:
            printf("Invalid choice. Exiting...\n");
            back_or_exit();
            break;
    }
    return 0;
}
