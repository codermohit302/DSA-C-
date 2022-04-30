#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node *next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};
void insertionAtHead(node* &head,int data){
    node* temp=new node(data);
    temp->next=head;
    head=temp;

}
void insertionAtEnd(node* &tail,int data){
    node* temp=new node(data);
    tail->next=temp;
    tail=temp;
}
void insertionAtPosition(node* &head,int data,int index){
    int cn=1;
    node* temp=head;
    while(cn<index-1){
        temp=temp->next;
        cn++;
    }
    node *ans=new node(data);
    ans->next=temp->next;
    temp->next=ans;
}
void deleteNode(int index,node* &head,node* &tail){
    if(index==1){
        node* temp= head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }
    else{
        node* curr=head;
        node* prev=NULL;
        int cnt=1;
        while(cnt<index){
            prev=curr;
            curr=curr->next;
            cnt++;

        }
        
        prev->next=curr->next;
        if(prev->next==NULL){
            tail=prev;
        }
        curr->next=NULL;
        delete curr;
    }
}
void deleteByValue(int target,node* &head){
    node* curr=head;
    node* prev=NULL;
    while(curr!=NULL){

        if(curr->data==target){
            head=head->next;

        }
        curr=curr->next;
    }
}
void print(node* &head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int main(){
    node *head=new node(10);
    node *tail=head;
    insertionAtHead(head,20);
    insertionAtHead(head,30);
    
    insertionAtPosition(head,11,2);
    insertionAtEnd(tail,40);
    deleteNode(4,head,tail);
    cout<<"tail "<<tail->data<<endl;
    print(head);
    return 0;
}