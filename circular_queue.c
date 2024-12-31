#include<stdio.h>
#define SIZE 5
int f=-1,r=-1,choice,queue[SIZE];
void enqueue();
void dequeue();
void display();
int addIndex(int index);
int main(){
    while(1){
        printf("Choose a Queue Operation \n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\nChoose an Operation : ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            return 0;
        default:
            printf("Enter a Valid Choice !\n");
            break;
        }
    }
    return 0;
}
void enqueue(){

    if(addIndex(r) == f){
        printf("Queue is FULL\n");
    }
    else{
        if(f == -1){
            f = 0;
        }
        r=addIndex(r);
        printf("Enter element to insert : ");
        scanf("%d",&queue[r]);
    }
}
void dequeue(){
    if(f == -1){
        printf("Queue is Empty !\n");

    }
    else{
        
        if(f == r){
            f = -1;
            r = -1;

        }
        else{
            f = addIndex(f);
        }
        
        printf("Element Deleted Successfully ! \n");
    }
}
void display(){
    if(f == -1){
        printf("Queue is Empty !\n");

    }
    else{
        int i = f;
        while(i != r){
            printf("%d -> ",queue[i]);
            i = addIndex(i);
        }
        printf("%d  ",queue[r]);
    }
}
int addIndex(int index){
    return (index + 1) % SIZE;
}