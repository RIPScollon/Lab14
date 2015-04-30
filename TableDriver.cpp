#include "TableSortedList.h"
#include "ListArray.h"
using CSC2110::ListArray;
#include "ListArrayIterator.h"
using CSC2110::ListArrayIterator;
#include "CD.h"
using CSC2110::CD;
#include "Text.h"
using CSC2110::String;

#include <iostream>
using namespace std;

void deleteCDs(ListArray<CD>* list)
{
   ListArrayIterator<CD>* iter = list->iterator();

   while(iter->hasNext())
   {
      CD* cd = iter->next();
      delete cd;
   }
   delete iter;
}

int main()
{
   ListArray<CD>* cds = CD::readCDs("cds.txt");
   int num_items = cds->size();
   cout << num_items << endl;

   TableSortedList<CD>* slt = new TableSortedList<CD>(&CD::compare_items, &CD::compare_keys);
   
   cout << " First is empty test: Starting with nothing so should display 1 for true\n " << slt->tableIsEmpty() << endl;
   
   ListArrayIterator<CD>* iter = cds->iterator();
   while(iter->hasNext())
   {
	   CD* cd = iter->next();
	   cd->getKey()->displayString();
	   cout << endl;
		slt->tableInsert(cd);
   }
   delete iter;
   
   cout << endl << endl << "Second is empty test: Everything is added so should display 0 for false\n" << slt->tableIsEmpty() << endl;
   
   cout << "Retrieval Test: for \"The God That Never Was\". Returns the title \n";
    slt->tableRetrieve(new String("The God That Never Was"))->getKey()->displayString();   
	cout << endl;
	
	cout << "Removal Test: for \"Power Ranger's Theme Song\". Returns NULL or 0\n" << endl;
	cout << slt->tableRemove(new String("Power Ranger's Theme Song")) << endl;
   
   cout << "Retrieval Test: for \"Honey Boo Boo's Theme Song\". Returns nothing because not in list\n" << endl;
   slt->tableRetrieve(new String("Honey Boo Boo's Theme Song"));
   cout << endl;

   ListDoublyLinkedIterator<CD>*  iter2 = slt->iterator();
   while (iter2->hasNext())
   {
	  CD* cd = iter2 ->next();
	  cd->getKey()->displayString();
	  cout << endl;
	  slt->tableRemove(cd->getKey());
   }
   delete iter2;
   
   cout << endl << endl << "Third is empty test: Everything has been removed so should display 1 for true\n" << slt->tableIsEmpty() << endl;
   
   cout << "Removal Test: for \"Nickle Back Album\". Returns NULL or 0 \n" << endl;
   cout << slt->tableRemove(new String("Nickle Back Album"));
   cout << endl;
   
   
//




   deleteCDs(cds);
   delete cds;
   delete slt;
   return 0;
}
