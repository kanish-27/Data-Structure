#include <stdio.h>
#define MAX 10
int num,arr[MAX];
void create(){
    printf("Enter the number of elements: ");
    scanf("%d",&num);
    for(int i=0;i<num;i++){
        printf("Enter element %d: ", i+1);
        scanf("%d",&arr[i]);
    }
}

void addElement() {
    if(num >= MAX) {
        printf("Array is full! Cannot add more elements.\n");
        return;
    }
    int element, pos;
    printf("Enter the element to add: ");
    scanf("%d", &element);
    printf("Enter position to insert (1 to %d): ", num+1);
    scanf("%d", &pos);
    
    if(pos < 1 || pos > num+1) {
        printf("Invalid position!\n");
        return;
    }
    
    for(int i=num; i>=pos; i--) {
        arr[i] = arr[i-1];
    }
    
    arr[pos-1] = element;
    num++;
    printf("Element added successfully!\n");
}

void deleteElement() {
    if(num == 0) {
        printf("Array is empty! Nothing to delete.\n");
        return;
    }
    int pos;
    printf("Enter position to delete (1 to %d): ", num);
    scanf("%d", &pos);
    
    if(pos < 1 || pos > num) {
        printf("Invalid position!\n");
        return;
    }
    
    for(int i=pos-1; i<num-1; i++) {
        arr[i] = arr[i+1];
    }
    num--;
    printf("Element deleted successfully!\n");
}

void displayArray() {
    if(num == 0) {
        printf("Array is empty!\n");
        return;
    }
    printf("Array elements:\n");
    for(int i=0; i<num; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    int choice;
    while(1) {
        printf("\n1.Create, 2.Adding, 3.Delete, 4.Display, 5.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        
        if(choice == 5) {
            printf("Exiting...\n");
            break;
        }
        
        switch(choice){

            case 1:
                create();
                break;
            case 2:
                addElement();
                break;
            case 3:
                deleteElement();
                break;
            case 4:
                displayArray();
                break;
            default:
                printf("Invalid choice! Please try again.\n");
    }
}
}