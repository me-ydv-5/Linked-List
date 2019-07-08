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
        cout<<temp->val<<" -> ";
        temp = temp->next;
    }
    cout <<"NULL"<<endl;
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

node *insertIntoLLAtTail(int arr[], int len){
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

node *findMiddle(node *head){
    node *half = head, *full = head;
    while(full){
        (full->next) ? ((full->next->next) ? ({full = full->next->next; half = half->next;}) : ({full = full->next->next;})) : ({full=full->next;});
    }
    return half;
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

node *remDupSorted(node *head){
    node *prev = head;
    node *temp = head->next;
    int curEl = prev->val;
    while(temp){
        if(temp->val == curEl){
            prev->next = temp->next;
        }else{
            prev = temp;
            curEl = prev->val;
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

bool hasEl(node *head, int el){
    node *temp = head;
    while(temp){
        if(temp->val == el)
            return true;
    }
    return false;
}

node *addOne(node *head){
    node *newHead = revLL(head);
    node *temp = newHead;
    while(temp){
        if(temp->val<9){
            temp->val += 1;
            break; 
        }else{
            temp->val = 0;
            if(!(temp->next)){
                node *el = (node *) malloc(sizeof(node));
                el->val = 1;
                el->next = NULL;
                temp->next = el;
                break;
            }
            temp = temp->next;
        }
    }

    return revLL(newHead);
}

node *insertIntoLLAtHead(node *head, int num){
    node *temp = (node *)malloc(sizeof(node));
    temp->val = num;
    temp->next = head;
    head = temp;
    return head;
}

node *numToLL(int num){
    node *head = NULL;
    if(num==0){
        return insertIntoLLAtHead(head, 0);
    }
    while(num){
        head = insertIntoLLAtHead(head, num%10);
        num /= 10;
    }
    return head;
}

node *revForEveryGroup(node *head, int grp){
    if(grp==1)
        return head;
    else if(lenLL(head) == grp)
        return revLL(head);
    else {

    }
}

bool ifLoop(node *head){
    node *half = head;
    node *full = head->next;
    while(full && full->next){
        if(half==full)
            return true;          
        full = full->next->next;
        half = half->next;
    }
    return false;
}

node *remLoop(node *head){
    node *half = head;
    node *prev = head;
    node *full = head->next;
    while(full && full->next){
        if(half==full){
            prev->next = NULL;
            return head;
        }
        prev = full->next;
        full = full->next->next;
        half = half->next;
    }
    return head;
}

node *nthFromFront(node *head, int n){
    node *temp = head;
    int i=1;
    while(i<n){
        temp = temp->next;
        i++;
    }
    return temp;
}

node *nthFromEnd(node *head, int n){
    return nthFromFront(head, lenLL(head)-n+1);
}

bool ifPalindrome(node *head){
    node *rev = revLL(head);
    node *temp = head;
    while(temp){
        if(temp->val != rev->val)
            return false;
        
        rev = rev->next;
        temp = temp->next;
    }
    return true;
}

node *deleteLastOcc(node *head, int el){
    node *temp = head, *prev = NULL, *nex = head->next;
    node *cur = NULL, *elPrev = NULL, *elNext = NULL;
    while(temp){
        if(temp->val == el){
            cur = temp;
            elPrev = prev;
            elNext = nex;
        }
        temp = temp->next;

        if(!prev){
            prev = head;
        }else{
            prev = prev->next;
        }

        if(nex){
            nex = nex->next;
        }
    }
    if(!elPrev){
        head = head->next;
    }else{
        elPrev->next = elNext;
    }

    return head;
}


int main() {

    int arr[] = {1,3,4,5,9,9,11};

    node *head = insertIntoLLAtTail(arr, sizeof(arr)/sizeof(arr[0]));
    
    cout<<"Original List is: ";
    printLL(head);

    cout<<"Length of list is: "<<lenLL(head)<<endl;


    // cout<<"Reversed list is: ";
    // head = revLL(head);
    // printLL(head);    

    // cout<<"Even numbers in the list are: ";
    // head = remOdd(head);
    // printLL(head);

    // cout<<"List after removing duplicates: ";
    // head = remDup(head);
    // printLL(head);

    // cout<<"Sorted List is: ";
    // head = sortLL(head);
    // printLL(head);

    // node *midd = findMiddle(head);
    // cout<<midd->val<<endl;

    // int n;
    // cin >> n;
    // head = numToLL(n);
    // cout<<"List of number is: ";
    // printLL(head);

    // cout<<"List after adding one: ";
    // head = addOne(head);
    // printLL(head);

    // cout<<"List after removing duplicates: ";
    // head = deleteLastOcc(head, 1);
    // printLL(head);

    return 0;
}