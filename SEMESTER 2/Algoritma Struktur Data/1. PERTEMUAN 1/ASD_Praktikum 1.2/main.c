#include <stdio.h>
#include <stdlib.h>

///// Q4
//
//typedef struct{
//    int d,m,y;
//} Date;
//
//int main()
//{
//    Date day1 = {21, 2, 2024};
//    Date day2 = {22, 2, 2024};
//
//    if(sameDay(day1, day2))
//        printf("It is the same day\n");
//    else
//        printf("It is not the same day\n");
//    return 0;
//}
//
//int sameDay (Date day1, Date day2){
//    if(day1.year != day2.year)
//        return 0;
//    if(day1.month != day2.month)
//        return 0;
//    if(day1.day != day2.day)
//        return 0;
//
//    return 1;
//}

/// Q5

typedef struct {
    int d, m, y;
} Date;

typedef struct {
    char name[60];
    double averageScore;
    Date dob;
} Student;

struct Class {
    Student stud[30];
    int numStud;
};

int main(){
    Student stud1 = {"Irvan", 88.5, {19, 2, 2025}};
    Student stud2 = {"Andy", 98.5, {21, 2, 2025}};
    isYounger(stud1, stud2);
}

int isYounger (Student stud1, Student stud2) {
    int result = 0;
    if(stud1.dob.y > stud2.dob.y)
        result = 1;
    if(stud1.dob.m > stud2.dob.m)
        result = 1;
    if(stud1.dob.d > stud2.dob.d)
        result = 1;
    if(result == 0){
        printf("Student 1 lebih tua dari Student 2");
    } else {
        printf("Student 1 seumur dengan Student 2");
    }
}
