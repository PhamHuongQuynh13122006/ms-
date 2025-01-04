#include <stdbool.h>

struct Date {
    int day, month, year;
};
struct Student{
    char student_id[10];
    char classroom[10];
    char name[50];
    struct Date date;
    bool gender;
    char email[20];
    char phone[20];
   // char password[50];
    int number_course;
};
struct Classroom {
    char classroomId[10];
	char teacherId[10];    
	char teacherName[20];    
	char classroomName[10];
	};
struct Teacher{
	char teacher[10];
	char classroom[10];
	char Name[20];
	struct Date;
	bool gender;
	char email[30];
	char phone[20];
	char password[20];
	
};
