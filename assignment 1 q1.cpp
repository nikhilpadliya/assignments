#include<iostream>
using namespace std;
 struct node
{
int data;
    struct node *next;
} Node;
int length( node * head )
{
intlen = 0;
    node * current  = head;
    while(current)
{
len++;
        current = current->next;
    }
    return len;
}
void addRemainingDigits(node *L1, int *carry, node **result, int diff);
void addListRecursively(node *L1, node *L2, int *carry, node **result);
node * createNode(int value)
{  
    node * newNode = (node *)malloc(sizeof(node));
newNode->data = value;
newNode->next = NULL;  
    return newNode;  
}
 void push(node **head, int value)
 {
    node *newNode = createNode (value);
    if(!(*head) ){
        *head = newNode;
    }
    else{
newNode->next = (*head);
        *head = newNode;
    }
}
void addTwoNumbers(node *L1, node *L2, int *carry, node  **result)
{
int len1 = length( L1 );
int len2 = length( L2 );
int diff = 0;  
    if(len1 < len2)
    {
        node * current = L1;
        L1 = L2;
        L2 = current;
    }
    diff = abs(len1-len2);
    node * current = L1;  
    while(diff--)
        current = current->next;
addListRecursively(current, L2, carry, result);
  diff = abs(len1-len2);
addRemainingDigits(L1, carry, result, diff);
  if(*carry)
  {
        push(result, *carry);
   }
    return;
} 
void addListRecursively(node *L1, node *L2, int *carry, node **result)
{  
int sum;
        if(!L1)
            return;  
addListRecursively(L1->next, L2->next, carry, result);  
         sum = L1->data + L2->data + (*carry);  
int value = sum%10;
        *carry = sum/10;
        push(result, value);  
        return;
} 
void addRemainingDigits(node *L1, int *carry, node **result, int diff){
int sum = 0;  
    if(!L1 || !diff)
        return;
addRemainingDigits(L1->next, carry, result, diff-1);  
    sum = L1->data + (*carry);
int value = sum%10;
    *carry = sum/10;  
    push(result, value);  
    return;
}
void printList( node * head ){
    node * current = head;
    while(current){
cout<<current->data;
        current = current->next;
    }
}
int main(){
	int v1,v2,n1,n2;
	int ch1=1,ch2=1;
        node * L1 = NULL;
        node * L2 = NULL;
        node * result = NULL;
int carry = 0 ;
cout<<"minimum length of 1st infinite number\n";
cin>>n1;
cout<<"enter the 1st number in reverse order\n";
        for(inti=0;i<n1-1;i++)
        {cin>>v1;
        push(&L1,v1);} 
        while(ch1==1)
        { 
		cin>>v1;
        push(&L1,v1);
cout<<"want to enter more(1/0)\n";
cin>>ch1;
        }
cout<<"minimum length of 2nd infinite number in reverse order\n";
cin>>n2;
cout<<"enter the 2nd number\n";
        for(int j=0;j<n2-1;j++)
        {cin>>v2;
        push(&L2,v2);}
        while(ch2==1)
        {
cin>>v2;
        push(&L2,v2);
cout<<"want to enter more(1/0)\n";
cin>>ch2;
        }
cout<<"1st number\n";
printList(L1);
cout<<"\n";
cout<<"2nd number\n";
printList(L2);
cout<<"\n";
addTwoNumbers(L1,L2, &carry, &result);
printList(result);
cout<<"\n";
        return 0;
}
