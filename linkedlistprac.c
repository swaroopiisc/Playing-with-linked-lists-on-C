#include<stdio.h>
#include<stdlib.h>

struct point{
    int x;
    int y;
    struct point * next_ptr;
};

struct point * createPoint(int, int);

int main(){
    int xcordi = 0,ycordi =0, num = 0;
    printf(" How many times do you want to enter coordinates: \n");
    scanf("%d",&num);
    printf("Enter new coordinates with a space in between \n");
    scanf("%d %d",&xcordi,&ycordi);
    struct point * start = createPoint(xcordi,ycordi);
    struct point * end = start;
    printf("Created point is: (%d,%d) \n",start->x,start->y);
    printf("Created address at %p \n",start);
    printf("%p\n",start->next_ptr);
    for(int i=0;i<num-1;i++){
        printf("Enter x and y coordinate with a space in between \n");
        scanf("%d %d",&xcordi,&ycordi);
        struct point * ptr1 = createPoint(xcordi,ycordi);
        printf("Created point is: (%d,%d) \n",ptr1->x,ptr1->y);
        printf("Created address at %p \n",ptr1);
        end->next_ptr = ptr1;
        end = ptr1;
        ptr1->next_ptr = NULL;
    }
    printf("%p \n",start->next_ptr);
    return 0;
}

struct point * createPoint(int x, int y) {
    struct point * ptr = (struct point *)malloc(sizeof(struct point));
    ptr->x = x;
    ptr->y = y;
    ptr->next_ptr = NULL; 
    return ptr;
}