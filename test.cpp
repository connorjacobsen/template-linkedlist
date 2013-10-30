#include "tll.h"

int main()
{
  // int LinkedList
  std::cout << "With ints! " << std::endl;
  LinkedList<int>* ll = new LinkedList<int>();
  ll->printList(); // empty list

  ll->prepend( 9 );
  ll->printList();

  ll->prepend( 13 );
  ll->append( 67 );
  ll->printList();

  ll->decapitate();
  ll->decaudate();
  ll->insertAt( 11, 3 );
  ll->append( 32 );
  ll->append( 33 );
  std::cout << "Length: " << ll->length() << std::endl;
  ll->printList();

  std::cout << std::endl << "With doubles! " << std::endl;
  // double LinkedList
  LinkedList<double>* ll2 = new LinkedList<double>();
  ll2->printList(); // empty list

  ll2->prepend( 9.8 );
  ll2->printList();

  ll2->prepend( 1.3 );
  ll2->append( 6.7 );
  ll2->printList();

  ll2->decapitate();
  ll2->decaudate();
  ll2->insertAt( 1.1, 3 );
  ll2->append( 3.32 );
  ll2->append( 0.33 );
  std::cout << "Length: " << ll2->length() << std::endl;
  ll2->printList();

  std::cout << std::endl << "With chars! " << std::endl;
  // char LinkedList
  LinkedList<char>* ll3 = new LinkedList<char>();
  ll3->printList(); // empty list

  ll3->prepend( 'a' );
  ll3->printList();

  ll3->prepend( 'd' );
  ll3->append( 'c' );
  ll3->printList();

  ll3->decapitate();
  ll3->decaudate();
  ll3->insertAt( 't', 3 );
  ll3->append( 'x' );
  ll3->append( 'z' );
  std::cout << "Length: " << ll3->length() << std::endl;
  ll3->printList();

  return 0;
}
