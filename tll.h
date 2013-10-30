#ifndef _TLL_H_
#define _TLL_H_

#include <iostream>

/*
 * This is the header file for the template linkedlist (tll) implementation file.
 */

// The Node struct
template <typename E>
struct Node 
{
  /* Data members */
  E data;     // the data that the Node holds
  Node* next;   // pointer to the next Node in the list

  

  /* Methods */
  bool lastNode()
  {
    /* If next isn't a nullptr, its not the last Node */
    if ( next != 0 )
      return false;
    /* Otherwise, it is the last node */
    return true;
  }

  unsigned int length()
  {
    if ( lastNode() ) // BASE CASE
      return 1;
    else
      return 1 + next->length();
  }

  void append( E data )
  {
     if ( next == 0 ) // BASE CASE
     {
       /* The last Node has been reached, create the new one */
       Node<E>* tmp = new Node<E>;
       tmp->data = data;
       tmp->next = next; // will be the nullptr (or 0)
       next = tmp;
     }
     else
       next->append( data );
  }

  bool contains( E value )
  {
    if ( data == value )
      return true;
    if ( lastNode() )
      return false;
    else
      return next->contains( value );  
  }

  void insertAt( E value, unsigned int const position )
  {
    if ( position == 1 || lastNode() ) // BASE CASE
    {
      Node<E>* tmp = new Node<E>;
      tmp->data = value;
      tmp->next = next;
      next = tmp;
    }
    else
      next->insertAt( value, position-1 ); // recursive call
  }

  E removeAt( unsigned int const position )
  {
    if ( position == 1 || lastNode() ) // BASE CASE
    {
      E value = next->data; // get the data to return (from next Node)
      Node<E>* toDelete = next; // create ptr to Node to delete
      next = next->next;     // make sure list not broken
      delete toDelete;       // delete the desired Node
      return value;
    }
    else
      return next->removeAt( position-1 );
  }

  void printList( unsigned int const position )
  {
    if ( lastNode() ) // BASE CASE
      std::cout << "Position: " << position << ", Data: " << data << std::endl;
    else
    {
      std::cout << "Position: " << position << ", Data: " << data << std::endl;
      next->printList( position+1 ); // recursive step
    }
  }

  E decaudate()
  {
    if ( next->lastNode() ) // BASE CASE
    {
      E value = next->data; // named value to not conflict with data member name
      Node<E>* toDelete = next;
      next = 0; // set next to be the nullptr
      delete toDelete;
      return value;
    }
    else              // recursive step
      return next->decaudate();
  }

  void clear()
  {
    if ( lastNode() == 0 )
    {
      Node<E>* toDelete = next;
      next->clear(); // recursive step
      delete toDelete;
    }
  }

  E itemAtTail()
  {
    if ( lastNode() )
      return data;
    else
      return next->itemAtTail();
  }

  E itemAt( unsigned int const position )
  {
      /* If the next item is the desired position, or the next item is the lastNode
     and the desired position doesnt exist, return data in next Node */
    if ( position == 1 || next->lastNode() ) 
      return next->data;
    else // Else, check the next one
      return next->itemAt( position-1 );
  }
  
};


// LinkedList struct
template <typename E>
struct LinkedList
{
  // Data members
  Node<E>* head;

  // Constructor
  LinkedList() { head = 0; }

  // Member functions
  bool empty()
  {
    /* 
     * If the head data member of the LinkedList is 0 (nullptr)
     * then it is an empty LinkedList 
     */
    if ( head != 0 )
      return false;
    /* Otherwise, head is a nullptr and the LinkedList is empty */
    return true;
  }

  unsigned int length()
  {
    if ( empty() ) // BASE CASE
      return 0;
    else 
      return head->length();
  }

  void prepend( E data )
  {
    Node<E>* tmp = new Node<E>;  // create the new Node object
    tmp->data = data;      // set its data
    tmp->next = head;      // point next to the next Node
    head = tmp;            // make head point to the new Node object
  }

  E decapitate()
  {
    E data = head->data;  // capture the data
    Node<E>* toDelete = head;  // create a ptr to the Node to remove
    head = head->next;      // point head to the list's second item (or nullptr)
    delete toDelete;        // delete the Node object
    return data;            // return the data
  }

  void append( E data )
  {
    if ( empty() )
      prepend( data );
    else
    {
      head->append( data );
    }
  }

  bool contains( E value )
  {
    if ( empty() )
      return false;
    else
      return head->contains( value ); // call the Node method
  }

  void insertAt( E value, unsigned int const position )
  {
    if ( position == 0 || empty() ) 
      prepend( value );
    else
      head->insertAt( value, position );
  }

  E removeAt( unsigned int const position )
  {
    if ( position == 0 ) // If we just want to remove the first element
      decapitate();      // we can use the decapitate function.
    else                 // Else we need remove at.
      return head->removeAt( position );
  }

  void printList()
  {
    if ( empty() ) // If empty, print to screen
      std::cout << "This LinkedList is empty!" << std::endl;
    else           // Else call printList on the Nodes
      head->printList( 0 );
  }

  E decaudate()
  {
    return head->decaudate();
  }

  void clear()
  {
    if ( empty() )
      std::cout << "LinkedList already empty!" << std::endl;
    else
    {
      head->clear();
      delete head; // delete the first Node in the list
      head = 0; // set head to point to nullptr
    }
  }

  E itemAtHead()
  {
    return head->data;
  }

  E itemAtTail()
  {
    return head->itemAtTail();
  }

  E itemAt( unsigned int const position )
  {
    if ( position == 0 )
      return head->data;
    else
      return head->itemAt( position );
  }
};

#endif
