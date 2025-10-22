#include "llrec.h"
#include <iostream>

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){
  //need to take each element, see whether it should go into larger or smaller, need
  //to preserve relative order
  //need to make sure all pointers point to the right shit
  //list: 2 5
  // we take two and put it in the "smaller" list
  //two still points to five, we need to decide whether five belongs in the smaller or larger list
  //if it belongs in the larger list, two should no longer point to it
  
  if(head == NULL){
    smaller = NULL;
    larger = NULL;
    return;
  }
  //handle cases where current element is bigger/smaller than pivot
  if(head->val <= pivot) {

    smaller = head;
    //copying head->next into a new node* variable, 
    Node* temp = head->next;
    //temp is the new head
    smaller->next = NULL;
    //now we have the address to what head pointed to and can make sure the last element doesn't point to this one
    head = NULL;
    llpivot(temp, smaller->next, larger, pivot);
  }
  else{
    larger = head;
    Node *temp = head->next;
    larger->next = NULL;
    head = NULL;
    llpivot(temp, smaller, larger->next, pivot);
  }
  return;
}


/* debugging
int main(){
  Node* head = new Node(1, NULL);
  std::cout << "enter values to go in your list" << std::endl;
  int next$;
  std::cin >> next$;
  head->val = next$;
  head->next = NULL;
  Node* currnode = head;
  while(std::cin >> next$){
    currnode->next = new Node(1, NULL);
    currnode = currnode->next;
    currnode->val = next$;
    currnode->next = NULL;
  }
  std::cout << "enter a pivot now" << std::endl;
  std::cin.clear();
  std::cin.ignore();
  std::cin >> next$;
  Node* nodez = new Node(33, NULL);
  Node* smaller =  new Node(1, nodez); 
  Node *bigger = new Node(1, nodez);
  llpivot(head, smaller, bigger, next$);
  std::cout << "smaller: ";
  currnode = smaller;
  while(currnode != NULL){
    std::cout << currnode->val << ' ';
    currnode = currnode->next;
  }
  std::cout << std::endl;
  std::cout << "larger: ";
  currnode = bigger;
  while(currnode != NULL){
    std::cout << currnode->val << ' ';
    currnode = currnode->next;
  }
  std::cout << std::endl;
  currnode = head;
  while(currnode != NULL){
    Node* tnode = currnode;
    currnode = currnode->next;
    delete tnode;
  }
  delete smaller;
  delete bigger;
  return 0;
}
//*/