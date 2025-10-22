#include <iostream>
#include <fstream>
#include <functional>
#include "llrec.h"
using namespace std;

/**
 * Reads integers (separated by whitespace) from a file
 * into a linked list.
 *
 * @param[in] filename
 *  The name of the file containing the data to read
 * @return
 *  Pointer to the linked list (or NULL if empty or the
 *  file is invalid)
 */
Node* readList(const char* filename);

/**
 * Prints the integers in a linked list pointed to
 * by head.
 */
void print(Node* head);

/**
 * Deallocates the linked list nodes
 */
void dealloc(Node* head);


Node* readList(const char* filename)
{
    Node* h = NULL;
    ifstream ifile(filename);
    int v;
    if( ! (ifile >> v) ) return h;
    h = new Node(v, NULL);
    Node *t = h;
    while ( ifile >> v ) {
        t->next = new Node(v, NULL);
        t = t->next;
    }
    return h;
}

void print(Node* head)
{
    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

void dealloc(Node* head)
{
    Node* temp;
    while(head) {
        temp = head->next;
        delete head;
        head = temp;
    }
}

// -----------------------------------------------
//   Add any helper functions or
//   function object struct declarations
// -----------------------------------------------

struct Objo{
  bool operator()(int n){
    if( n < 170 ) return 0;
    else return 1;
  }
};



int main(int argc, char* argv[])
{
    if(argc < 2) {
        cout << "Please provide an input file" << endl;
        return 1;
    }

    // -----------------------------------------------
    // Feel free to update any code below this point
    // -----------------------------------------------
    Node* head = readList(argv[1]);
    cout << "Original list: ";
    print(head);

    // Test out your linked list code
    //testing llpivot
    std::cout << "testing llpivot (y/n)?" << std::endl;
    char yn;
    std::cin >> yn;
    Node* smaller = NULL; 
    Node* bigger = NULL;
    if(yn == 'y'){
      std::cout << "enter a pivot now" << std::endl;
      int next$;
      std::cin >> next$;
      llpivot(head, smaller, bigger, next$);
      std::cout << "smaller: ";
      print(smaller);
      std::cout << "larger: ";
      print(bigger);
    }

    //deleting the list
    Node *currnode = smaller;
    while(currnode != NULL){
      Node* tnode = currnode;
      currnode = currnode->next;
      delete tnode;
    }
    currnode = bigger;
    while(currnode != NULL){
      Node* tnode = currnode;
      currnode = currnode->next;
      delete tnode;
    }


    //testing llfilter
    head = NULL;
    head = readList(argv[1]);
    std::cout << "about to test llfilter list is: " << std::endl ;
    print(head);
    Objo jake;
    head = llfilter<Objo>(head, jake);
    std::cout << "after calling llfilter on all items less than 170: ";
    print(head);

    //deleting the list
    currnode = head;
    while(currnode != NULL){
      Node* tnode = currnode;
      currnode = currnode->next;
      delete tnode;
    }


    
    return 0;

}
