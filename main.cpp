#include<bits/stdc++.h>

using namespace std;

struct node{
    int val;
    node *next;
};

node* revLL(node *head){
    node *tempHead = NULL;
    while(head){
        node *temp = (node *)malloc(sizeof(node));
        temp->val = head->val;
        temp->next = tempHead;
        tempHead = temp;
        head = head->next;
    }
    return tempHead;
}

void printLL(node *temp){
    while(temp){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    cout << endl;
}

node* remOdd(node *head){
    node *temp = head;
    node *lastEven = NULL;
    bool flag = false;
    while(temp){
        if(!(temp->val%2)){
            lastEven = temp;
            if(!flag){
                head = temp;
                flag = true;
            }
        }else{
            if(lastEven){
                lastEven->next = temp->next;
            }
        }
        temp = temp->next;
    }
    return head;
}

node *insertIntoLL(int arr[], int len){
    node *head = NULL;
    node *tail = NULL;
    for (int i = 0; i < len; i++){
        node *temp = (node *)malloc(sizeof(node));
        temp->val = arr[i];
        temp->next = NULL;
        if(!head){
            head = temp;
            tail = temp;
            continue;
        }
        tail->next = temp;
        tail = temp;
    }

    return head;
}

node *remDup(node *head){
    
    unordered_map<int, bool> myMap;
    myMap.insert(make_pair(head->val, true));
    
    node *prev = head;
    node *temp = head->next;

    while(temp){
        if(myMap.find(temp->val) != myMap.end()){
            prev->next = temp->next;
        }else{
            myMap.insert(make_pair(temp->val, true));
            prev = temp;
        }
        temp = temp->next;
    }
    return head;
}

int lenLL(node *head){
    int len = 0;
    node *temp = head;
    while(temp){
        len++;
        temp = temp->next;
    }
    return len;
}

node *sortLL(node *head){
    
    node *newHead = (node *)malloc(sizeof(node));
    newHead->val = head->val;
    newHead->next = NULL;
    head = head->next;

    while(head){
        node *temp = (node *)malloc(sizeof(node));
        node *newTemp = (node *)malloc(sizeof(node));
        node *newPrev = (node *)malloc(sizeof(node));

        temp->val = head->val;
        temp->next = NULL;
        head = head->next;

        if(lenLL(newHead) == 1){
            if(temp->val < newHead->val){
                temp->next = newHead;
                newHead = temp;
            }else{
                newHead->next = temp;
            }
            continue;
        }

        if(temp->val < newHead->val){
            temp->next = newHead;
            newHead = temp;
            continue;
        }else{
            newTemp = newHead->next;
            newPrev = newHead;
        }

        while(newTemp){  
            if(temp->val < newTemp->val){
                temp->next = newTemp;
                newPrev->next = temp;
                break;
            }else if(!(newTemp->next)){
                newTemp->next = temp;
                break;
            }else{
                newPrev = newPrev->next;
                newTemp = newTemp->next;
            }   
        }        
    }
    return newHead;
}


int main() {

    int arr[] = {1,3,2,3,4,5,5,5,7,8,8,8,66,6,7,6};

    node *head = insertIntoLL(arr, sizeof(arr)/sizeof(arr[0]));
    
    cout<<"Original List is: ";
    printLL(head);

    cout<<"Length of list is: "<<lenLL(head)<<endl;

    cout<<"Reversed list is: ";
    head = revLL(head);
    printLL(head);    

    cout<<"Even numbers in the list are: ";
    head = remOdd(head);
    printLL(head);

    cout<<"List after removing duplicates: ";
    head = remDup(head);
    printLL(head);

    cout<<"Sorted List is: ";
    head = sortLL(head);
    printLL(head);

    return 0;
}