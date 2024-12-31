#include<stdio.h>
void readSet(int set[],int universal[],int size);
int isPresent(int arr[],int elem,int size);
void printSet(int arr[],int size);
int n,n1,n2;
void main(){
    // Read Universal
    printf("Enter the size of Universal Set : ");
    scanf("%d",&n);
    int U[n];
    printf("Enter the elements of Set : \n");
    readSet(U,NULL,n);
    
    // Read Set 1
    printf("Enter the size of Set1 : ");
    scanf("%d",&n1);
    if(n1 > n){
        printf("\nEnter a valid Size");
        return;
    }
    
    int set1[n1];
    printf("Enter the elements of Set 1 : \n");
    readSet(set1,U,n1);
    
    

    // Read Set 2
    printf("Enter the size of Set2 : ");
    scanf("%d",&n2);
    if(n2 > n){
       printf("\nEnter a valid Size");
       return;
    }
    int set2[n2];
    printf("Enter the elements of Set 2 : \n");
    readSet(set2,U,n2);

    int b_set1[n],b_set2[n];
    // Bit string  set1
    for(int i=0;i<n;i++){
        b_set1[i] = 0;
        b_set2[i] = 0;
        for(int j=0;j<n1;j++){
             if(U[i] == set1[j]){
                b_set1[i] = 1;
             }
        }

        for(int j=0;j<n2;j++){
             if(U[i] == set2[j]){
                b_set2[i] = 1;
             }
        }
    }

    
    // Union Operation
    int union_set[n];
    for(int i=0;i<n;i++){
        union_set[i] = 0;
        if(b_set1[i] == 1 || b_set2[i] == 1){
            union_set[i] = 1;
        }
    }

    // Intersection
    int intersection_set[n];
    for(int i=0;i<n;i++){
        intersection_set[i] = 0;
        if(b_set1[i] == 1 && b_set2[i] == 1){
            intersection_set[i] = 1;
        }
    }



    // Printing Sets
    printf("\nUniversal Set : ");
    printSet(U,n);
    
    printf("\nSet 1 : ");
    printSet(set1,n1);
    printf("\nSet 2 : ");
    printSet(set2,n2);

    printf("\nBitstring Representation");
    printf("\nSet 1 : ");
    printSet(b_set1,n);
    printf("\nSet 2 : ");
    printSet(b_set2,n);

    printf("\nUnion Representation");
    printSet(union_set,n);

    printf("\nIntersection Representation");
    printSet(intersection_set,n);


}
void readSet(int set[],int universal[],int size){
    int element;
    for(int i=0;i<size;i++){
        printf("Enter Element %d : ",i+1);
        scanf("%d",&element);
        if(!isPresent(set,element,size) && (universal == NULL || isPresent(universal,element,n)))
        {
            set[i]=element;
            
        }
        else{
            printf("\nInvalid Entry ! ");
            i--;
            
            
        }
    }
}
void printSet(int arr[],int size){
    for(int i=0;i<size;i++){
        printf(" %d ",arr[i]);
    }
}

int isPresent(int arr[],int elem,int size){
    for(int i=0;i<size;i++){
        if(elem == arr[i]){
            return 1;
        }
    }
    return 0;
}