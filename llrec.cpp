#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************
void llpivot (Node*& head, Node*& smaller, Node*& larger, int pivot){


  if(head == nullptr){
    return;
  }

  Node* temp = head->next;
  

  if(head->val > pivot){
    head->next = larger;
    larger = head; 
  }
  else{
    head->next = smaller;
    smaller = head; 
  }

  head = nullptr;

  llpivot(temp, smaller, larger, pivot);
}


