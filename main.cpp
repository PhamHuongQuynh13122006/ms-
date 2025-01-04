#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function.h"
//#include "datatype.h"
int main() {
	struct Student students[100] = {
    {"1", "ENG_A", "Nguyen Van A", {1, 12, 2000}, true, "TVA@gmail.com", "0123456789",3},
    {"2", "ENG_B", "Nguyen Thi V", {23, 5, 2002}, false, "TTV@gmail.com", "0122837333", 4},
    {"3", "ENG_C", "Nguyen Van D", {11, 10, 2004}, true, "TVH@gmail.com", "0738493720", 2},
    {"4", "ENG_D", "Nguyen Van T", {3, 11, 2005}, true, "TVT@gmail.com", "0627392739", 5},
    {"5", "ENG_A", "Nguyen Thi B", {18, 2, 2003}, false, "TTB@gmail.com", "0937595931", 1}
};
	int n = 5;
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
                studentMenu();
                scanf("%d", &choice);
                switch (choice) {
                    case 1:
                    	system("cls");
                    //	load_file(students, &n);
                        show_student_list();
						back_or_exit();
                        break;
                    case 2:
                    	system("cls");
                    //	load_file(students, &n);
                        addStudent();
                    //  save_file(students,n);
                        back_or_exit();
                        break;
                    case 3:
                    	system("cls");
                    //	load_file(students, &n);
                        editStudent();
                    //  save_file(students,n);
                        back_or_exit();
                        break;
                    case 4:
                    	system("cls");
                    // 	load_file(students, &n);
                    	searchStudent();
                    	back_or_exit();
                    	break;
                    case 5:
                    	system("cls");
                    //	load_file(students, &n);
                    	sort_Student_i_or_d();
                    	back_or_exit();
                    	break;
					case 6:
						system("cls");
					//	load_file(students, &n);
						deleted();
					//	save_file(students,n);
						back_or_exit();
						break;
					case 7:
                        printSlowly("\nExisting student menu",50);
                        printSlowly("...",150);
						printfinish();
                        return 0;
                    default:
                        printf("\tInvalid choice. Please try again.\n");
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
