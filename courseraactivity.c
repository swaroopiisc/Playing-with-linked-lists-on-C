#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student {
    char name[50];
    int age;
    struct student *next;
};

struct student * createStudent(char studentName[],int age);

int main(void){
    struct student * studentPtr;
    char StudentName[40];
    int StudentAge = 0;
    memset(StudentName,0,40);
    printf("%s\n",StudentName);
    
    printf("Enter Student Name and Age with a space \n");
    scanf("%s %d",StudentName,&StudentAge);

    studentPtr = createStudent(StudentName,StudentAge);
    printf("New student created: %s is %d years old.\n", studentPtr->name, studentPtr->age);
    free(studentPtr);
    
    return 0;
}

struct student * createStudent(char studentName[], int age){
    struct student * ptr = (struct student *)malloc(sizeof(struct student));
    int i=0;
    memset(ptr->name,0,strlen(ptr->name));
    while(studentName[i] != '\0'){
        ptr->name[i] = studentName[i];
        i++;
    }
    ptr->age = age;
    ptr->next = NULL;
    return ptr;
}
