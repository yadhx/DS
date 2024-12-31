#include<stdio.h>
#include<stdlib.h>

void insert();
void delete();
void update();
void display();

struct node {
    int data;
    struct node *next;
}*new,*start=NULL,*temp,*prev;

int choice;
int main(){
    while(1){
        printf("\nEnter a operation\n1.Insert\n2.Delete\n3.Update\n4.Display\n5.Exit\nChoose an Operation : ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            delete();
            break;
        case 3:
            update();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid Choice !");
            break;
        }
    }
}

void insert(){
    new = (struct node *)malloc(sizeof(struct node));
    printf("Enter Element to Insert : ");
    scanf("%d",&new->data);
    new->next=NULL;
    
    if(start == NULL){
        start = new;
        temp = new;
    }else{
        temp->next=new;
        temp=new;
    }
    printf("\nElement Inserted Successfully ");
}

void delete(){
    if(start == NULL){
        printf("List is Empty ! \n");
        return;
    }
    if(start->next == NULL){
        free(start);
        start = NULL;
        printf("Deleted Successfully\n");
        return;
    }
    else{
        temp = start;
        while(temp->next != NULL){
            prev = temp;
            temp = temp->next;
        }
        free(temp);
        prev->next=NULL;
        printf("\n Deleted Successfully");
        
        
    }
}
void update(){
    
}

void display(){
    if(start == NULL){
        printf("List is Empty ! \n");
        return;
    }
    printf("Printing List -- \n ");
    temp = start;
    while(temp!=NULL){
        printf(" %d ",temp->data);
        if (temp->next != NULL) {
            printf(" ->"); 
        }
        temp = temp->next;
    }
    printf("\b\b\b\b\b");
}