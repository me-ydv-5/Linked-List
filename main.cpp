#include<bits/stdc++.h>

using namespace std;

struct node{
    int val;
    node *next;
};

struct heavyNode{
    int val;
    heavyNode *right;
    heavyNode *down;
};

node *insertIntoLLAtHead(node *head, int num){
    node *temp = (node *)malloc(sizeof(node));
    temp->val = num;
    temp->next = head;
    head = temp;
    return head;
}

node *insertIntoLLAtTail(vector<int> arr){
    node *head = NULL;
    node *tail = NULL;
    for (int i = 0; i < arr.size(); i++){
        node *temp = (node *)malloc(sizeof(node));
        temp->val = arr.at(i);
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

void printLL(node *temp){
    while(temp){
        cout<<temp->val<<" -> ";
        temp = temp->next;
    }
    cout <<"NULL"<<endl;
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



/* Problem 1. */

node *findMiddle(node *head){
    node *half = head, *full = head;
    while(full){
        (full->next) ? ((full->next->next) ? ({full = full->next->next; half = half->next;}) : ({full = full->next->next;})) : ({full=full->next;});
    }
    return half;
}

/* Problem 2. */

heavyNode *insertIntoHeavyNode(heavyNode* head, vector<int> arr){

    heavyNode *list = NULL;
    for(int i=0; i<arr.size(); i++){

        heavyNode *temp = (heavyNode *)malloc(sizeof(heavyNode));
        temp->val = arr.at(i);
        temp->right = NULL;
        temp->down = NULL;

        if(!list){
            list = temp;
        }else{
            heavyNode *newTemp = list;
            while(newTemp->down){
                newTemp = newTemp->down;
            }
            newTemp->down = temp;
        }
    }

    if(!head){
        head = list;
        return head;
    }

    heavyNode *temp = head;
    while(temp->right){
        temp = temp->right;
    }
    temp->right = list;

    return head;
}

void printHeavyList(heavyNode *head){
    while(head){
        heavyNode *temp = head;
        while(temp){
            cout<<temp->val<<"->";
            temp = temp->down;
        }
        cout<<"NULL"<<endl;
        cout<<"|"<<endl;
        head = head->right;
    }
    cout<<"NULL"<<endl;
}

node *flattenLists(heavyNode *head){
    vector<int> arr;
    arr.push_back(head->val);
    heavyNode *tempT = head->right;
    heavyNode *tempD1 = head->down;
    heavyNode *tempD2 = tempT;
    while(1){
        if(!tempD1 && tempD2){
            while(tempD2){
                arr.push_back(tempD2->val);
                tempD2 = tempD2->down;
            }
            break;
        }else if(tempD1 && !tempD2){
            while(tempD1){
                arr.push_back(tempD1->val);
                tempD1 = tempD1->down;
            }
            break;
        }else if(!tempD1 && !tempD2){
            break;
        }else{
            if(tempD1->val <= tempD2->val){
                arr.push_back(tempD1->val);
                if(tempD1->down){
                    tempD1 = tempD1->down;
                }else{
                    tempD1 = tempT->right;
                    tempT = tempD1;
                }
            }else{
                arr.push_back(tempD2->val);
                if(tempD2->down){
                    tempD2 = tempD2->down;
                }else{
                    tempD2 = tempT->right;
                    tempT = tempD2;
                }
            }
        }       
    }
    return insertIntoLLAtTail(arr);
}


/* Problem 3. */

// Still to Update


/* Problem 4. */

node *deleteMiddle(node *head){

    if(!(head->next)){
        return NULL;
    }else if(!(head->next->next)){
        head = head->next;
        return head;
    }

    node *half = head, *full = head, *prev = head;
    while(full){
        (full->next) ? ((full->next->next) ? ({full = full->next->next;prev = half; half = half->next;}) : ({full = full->next->next;})) : ({full=full->next;});
    }
    prev->next = half->next;
    return head;
}

/* Problem 5. */

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

/* Problem 6. */

node *addOne(node *head){
    node *newHead = reverseLL(head);
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

    return reverseLL(newHead);
}

/* Problem 7. */

node *revForEveryGroup(node *head, int grp){
    if(grp==1)
        return head;
    else if(lenLL(head) == grp)
        return reverseLL(head);
    else {

    }
}

/* Problem 8. */

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

/* Problem 9. */

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

/* Problem 10. */

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

/* Problem 11. */

bool ifPalindrome(node *head){
    node *rev = reverseLL(head);
    node *temp = head;
    while(temp){
        if(temp->val != rev->val)
            return false;
        
        rev = rev->next;
        temp = temp->next;
    }
    return true;
}

/* Problem 12. */

// Still to Update

/* Problem 13. */

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

/* Problem 14. */

node *rotateByK(node *head, int k){
    node *temp=head, *newHead=NULL, *prev=NULL;
    int i=1;
    while(temp->next){
        if(i==k+1){
            newHead = temp;
        }
        if(i==k){
            prev = temp;
        }
        temp = temp->next;
        i++;
    }
    temp->next = head;
    prev->next = NULL;
    head = temp;

    return newHead;
}

/* Problem 15. */

node *deletedMNnodes(node *head, int m, int n){
    node *temp = head;
    int i=1;
    while(temp){
        if(i==m){
            node *temp2 = temp->next;
            int j=1;
            bool end = true;
            while(temp2){
                if(j==n+1){
                    temp->next = temp2;
                    end = false;
                    break;
                }
                temp2 = temp2->next;
                j++;
            }
            if(end){
                temp->next = NULL;
            }
            i=0;
        }
        temp = temp->next;
        i++;
    }
    return head;
}

/* Problem 16. */

pair<node*, node*> mergeTwoLL(node *head1, node *head2){
    node *temp1 = head1;
    node *temp2 = head2;
    while(temp1 && temp2){
        node *newTemp2 = temp2->next;
        temp2->next = temp1->next;
        temp1->next = temp2;
        temp2 = newTemp2;
        temp1 = temp1->next->next;
    }
    return make_pair(head1, temp2);
}

/* Problem 17. */

void deleteLL(node *head){
    node *temp = head;
    node *prev = NULL;
    while(temp){
        prev = temp;
        temp = temp->next;
        free(prev);
    }
    head = NULL;
    cout<<"List Deleted."<<endl;
}

/* Problem 18. */

node *reverseLL(node *head){
    if(!(head->next)){
        return head;
    }else if(!(head->next->next)){
        node *prev = head, *cur = head->next;
        prev->next = NULL;
        cur->next = prev;
        head = cur;
        return head;
    }

    node *prev = head, *cur = head->next, *nex = head->next->next;
    prev->next = NULL;
    cur->next = prev;
    head = cur;
    while(nex){
        cur = nex;
        nex = nex->next;
        cur->next = head;
        head = cur;
    }
    return head;
}



int main() {

    vector<int> vec1 = {1,2,33,44,5,6,5};

    // vector<int> vec2 = {6,7,8,9,10,11,12,13,22,24,25,33};
    // vector<int> vec3 = {11,12,13,14,15,16,17,18};

    node *head = insertIntoLLAtTail(vec1);  
    cout<<"Original List is: ";
    printLL(head);
    cout<<"Length of list is: "<<lenLL(head)<<endl;

    // cout<<"Reversed list is: ";
    // head = reverseLL(head);
    // printLL(head);

    // heavyNode *head = NULL;
    // head = insertIntoHeavyNode(head, vec);
    // head = insertIntoHeavyNode(head, vec2);
    // head = insertIntoHeavyNode(head, vec3);
    // printHeavyList(head);
    // cout<<"List after flattening list is: ";
    // node *flattened = flattenLists(head);
    // printLL(flattened);   

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

    // cout<<"List after removing last occurence: ";
    // head = deleteLastOcc(head, 1);
    // printLL(head);

    // cout<<"List after rotating by K: ";
    // head = rotateByK(head, 4);
    // printLL(head);

    // cout<<"List after deleting MN nodes: ";
    // head = deletedMNnodes(head, 2, 4);
    // printLL(head);

    // pair<node*, node*> result = mergeTwoLL(head1, head2);
    // cout<<"Lists after merging 2 Lists: "<<endl;
    // cout<<"List 1: ";
    // printLL(result.first);
    // cout<<"List 2: ";
    // printLL(result.second);

    // deleteLL(head);
    
    // cout<<"List after reversing nodes: ";
    // head = deletedMNnodes(head);
    // printLL(head);

    // cout<<"List after deleting middle node: ";
    // head = deleteMiddle(head);
    // printLL(head);

    return 0;
}