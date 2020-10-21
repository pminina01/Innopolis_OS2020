#include <stdio.h> 
#include <stdlib.h> 

struct Node { 
    int val; 
    struct Node* next; 
} Node;

void print_list(struct Node* head){
    /*
    * A function that print out the value of each element 
    */
    head=head->next;
    while (head!=NULL){
        printf("%d ",head->val);
        head=head->next;
    }
    printf("\n");
}

void insert_node(struct Node* head, int index,int value){
    /*
    * A function which will insert a new element after 
    * some existing element given by index 
    */
    int i = 0;
    while (i<index && head->next) {
        head = head->next;
        i++;
    }
    struct Node* new_node=(struct Node*) malloc(sizeof(struct Node));
    new_node->val=value;
    if(head->next){ //If insert somewhere in the middle or at the start of the list
        new_node->next=head->next;
    }
    else{ //If we insert at the end of list
        new_node->next=NULL;
    }
    head->next=new_node;
    
}
void delete_node(struct Node* head, int n){
    /*
    * A function which will delete a certain element given by index
    */
    int i = 0;
    while (i<n-1 && head->next) { //Find previous elemen of needed
        head = head->next;
        i++;
    }
    struct Node* del_node=head->next;
    head->next=del_node->next;
    free(del_node);
    
}
int main(){
    struct Node* head=(struct Node*)malloc(sizeof(struct Node));
    struct Node* v1=(struct Node*)malloc(sizeof(struct Node));
    struct Node* v2=(struct Node*)malloc(sizeof(struct Node));
    struct Node* v3=(struct Node*)malloc(sizeof(struct Node));
    
    head->next=v1;
    
    v1->val=1;
    v1->next=v2;
    
    v2->val=2;
    v2->next=v3;
    
    v3->val=3;
    v3->next=NULL;
    
    print_list(head);
    
    insert_node(head,0,4);
    print_list(head);
    
    insert_node(head,4,5);
    print_list(head);
    
    delete_node(head,0);
    print_list(head);
    
    delete_node(head,2);
    print_list(head);
}