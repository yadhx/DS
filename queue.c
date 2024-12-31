#include<stdio.h>
#define SIZE 5
int f=0,r=-1,choice,queue[SIZE];
void enqueue();
void dequeue();
void display();
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
    if(r > SIZE -1){
        printf("Queue is FULL\n");
    }
    else{
        r++;
        printf("Enter element to insert : ");
        scanf("%d",&queue[r]);
    }
}
void dequeue(){
    if(f > r){
        printf("Queue is Empty !\n");

    }
    else{
        queue[f]=0;
        f++;
        printf("Element Deleted Successfully ! \n");
    }
}
void display(){
    if(f > r){
        printf("Queue is Empty !\n");
        
    }
    else{
        for(int i=f;i<=r;i++){
            printf("%d -> ",queue[i]);
        }
    }
}