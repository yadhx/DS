#include<stdio.h>
#define MAX 100

void display(int arr[],int top){
    printf("\n---------DISPLAY---------\n");
   
    if(top == -1){
        printf("\nStack is Empty\n");
    }
    else{
    for(int i=0; i<=top; i++)
    {
    printf("%d ", arr[i]);
    }

    }
    printf("\n");
}
int push(int arr[],int n,int top){
    int elem;
    printf("\n...............PUSH.................\n");
    if(top>n-1){
        printf("\nStack is Full POP a Element to Continue ! OVERFLOW Condition\n");
    }
    else{
        top += 1;
        printf("\nEnter the Element To Push : ");
        scanf("%d",&elem);
        arr[top]=elem;
        printf("\nPUSH OPERATION SUCCESSFULL\n");
    }
    display(arr,top);
    return top;
}
int pop(int arr[],int n,int top){
    if(top == -1 || top > n ){
        display(arr,top);
        return top;
    }else{
        int elem = arr[top];
        top -= 1;
        printf("%d Deleted Successfully !\n",elem);
        return top;
    }
}
int peek(int arr[],int n,int top){
    if(top == -1 || top > n ){
        display(arr,top);
        
    }else{
        printf("\nElement at Top of stack : ");
      printf("%d",arr[top]);
    
    }
}


int main(){
    int arr[MAX],n,choice,top=-1;
    printf("Enter the Size of Stack : ");
    scanf("%d",&n);
    do{
        printf("\n\nChoose a operation :\n1.PUSH\n2.POP\n3.PEEK\n4.DISPLAY\n5.Exit\n\nChoice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            top = push(arr,n,top);
            break;
            case 2:
            top = pop(arr,n,top);
            break;
            case 3:
            peek(arr,n,top);
            break;
            case 4:
            display(arr,top);
            break;
            case 5:
            printf("\nExiting successfully...\n");
            break;
            default:
            printf("\nEnter a Valid Choice ! \n");
            
        }
    }while(choice != 5);

}
