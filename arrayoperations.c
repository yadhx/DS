//  Array Operations
#include<stdio.h>

void cases(int arr[],int n);
void display(int arr[],int n);
void insert(int arr[],int n);
void delete(int arr[],int n);
void searcharrray(int arr[],int n);
void sort(int arr[],int n);
void merge(int arr[],int n);
int search(int arr[],int n,int elem);

int main(){
    int arr[100];
    int n;
    printf("Enter the Number of array Elements : ");
    scanf("%d",&n);
    printf("\n");
    for(int i=0;i<n;i++){
        printf("Enter the Element  %d : ",i+1);
        scanf("%d",&arr[i]);
    }
    printf("\n Array given - ");
    for(int i=0;i<n;i++){
        printf(" %d ",arr[i]);
    }
    cases(arr,n);
    return 0;
}
void cases(int arr[],int n){
    int choice;
    printf("\n\n\n........Choose a Array Operation........\n1.Display\n2.Insert\n3.Delete\n4.Search\n5.Sort\n6.Merge New Array\n7.Exit\nEnter Option : ");
    scanf("%d",&choice);
    switch(choice){
        
    case 1 : 
        display(arr,n);
        printf("Press 7 if you dont want to continue ");
        
        break;


    case 2 :
        insert(arr,n);
        break;

    case 3 :
        delete(arr,n);
        break;

    case 4 :
        searcharrray(arr,n);
        break;

    case 5 : 
        sort(arr,n);
        break;

    case 6 :
        merge(arr,n);
        break;

    
    case 7 :
        printf("Exiting Program..\n");
        break;
    

    default:
        printf("\nEnter a Valid Choice !\n");
    }
}


void display(int arr[],int n){
    printf("\n......Array.......\n");
    for(int i=0;i<n;i++){
        printf(" %d ",arr[i]);
    }
    printf("\n");
    cases(arr,n);
}

void insert(int arr[],int n){
    int elem,pos;
    printf("\nEnter the Element to Insert : ");
    scanf("%d",&elem);
    printf("\nEnter the Position to insert(Not index) : ");
    scanf("%d",&pos);
    if(pos>0 && pos<n){
        
    for(int i=n;i>pos;i--){
        arr[i] = arr[i-1];
    }
    arr[pos-1]=elem;
    
    printf("\nElement Inserted at Position %d",pos);
    display(arr,n);
    }
    else{
        printf("\nEnter a Valid Position !\n");
        insert(arr,n);
    }

}


void delete(int arr[],int n){
    int elem;
    int pos;
    printf("\nEnter Element to Delete : ");
    scanf("%d",&elem);
    pos = search(arr,n,elem);
    if(pos == -1){
        printf("\nElement is Not Present In The Array ! Try Again\n");
        delete(arr,n);
    }
    else{
        for(int i=pos;i<n;i++){
            arr[i] = arr[i+1];
        }
        printf("Element Deleted Successfully ");
        display(arr,n-1);
    }
}

int search(int arr[],int n,int elem){
    for(int i=0;i<n;i++){
        if(arr[i] == elem){
            return i;
        }
    }
    return -1;
}

void searcharrray(int arr[],int n){
    int elem;
    printf("\nEnter Element to Search : ");
    scanf("%d",&elem);
    int pos = search(arr,n,elem);
     if(pos == -1){
        printf("\nElement is Not Present In The Array ! Try Again\n");
        searcharrray(arr,n);
    }
    else{
        
        printf("Element Found at Position %d ",pos+1);
        display(arr,n);
    }

}

void sort(int arr[],int n){
    int i,j,temp;
    for(i=0;i<n+1;i++){  // 0-2
        for(j=0;j<n-i-1;j++){  //  n = 3 
            if( arr[j] > arr[j+1] ){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    printf("Array Sorted Successfully");
    display(arr,n);
}


void merge(int arr[],int n){
    int m,i;
    printf("Enter the size of array to Merge : ");
    scanf("%d",&m);
    int newarr[m];
    for(i=0;i<m;i++){
        printf("Enter the Element %d : ",i+1);
        scanf("%d",&newarr[i]);
    }
    int n2 = n + m;
    int mergedarr[n2];
    for(i=0;i<n;i++){
        mergedarr[i] = arr[i];
    }
    for(i=0;i<m;i++){
        mergedarr[i+n] = newarr[i];
    }
    display(mergedarr,n2);
}