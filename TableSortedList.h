#if !defined (TABLESORTEDLIST_H)
#define TABLESORTEDLIST_H

#include "SortedListDoublyLinked.h"

template < class T >
class TableSortedList
{

   private:
      SortedListDoublyLinked<T>* sldl;

   public:
      TableSortedList(int (*comp_item) (T* item_1, T* item_2), int (*comp_key) (String* key, T* item));
      ~TableSortedList();

      bool tableIsEmpty();
      int tableSize();
      T* tableRetrieve(String* sk);
      void tableInsert(T* item);  //does not allow duplicate search keys into the table (need to use getKey() to check for duplicates)
      bool tableRemove(String* search_key);  //returns true if delete is successful (need to call tableRetrieve to see if the item is there)

      ListDoublyLinkedIterator<T>* iterator();

};

template <class T>
TableSortedList<T>::TableSortedList(int (*comp_item) (T* item_1, T* item_2), int (*comp_key) (String* key, T* item));
{
	
}

template <class T>
TableSortedList<T>::~TableSortedList();
{
	
}

template <class T>
bool TableSortedList<T>::tableIsEmpty();
{
	
}

template <class T>
int TableSortedList<T>::tableSize();
{
	
}

template <class T>
T* TableSortedList<T>::tableRetrieve(String* sk);
{
	
}

template <class T>
void TableSortedList<T>::tableInsert(T* item);  //does not allow duplicate search keys into the table (need to use getKey() to check for duplicates)
{
	
	
}

template <class T>
bool TableSortedList<T>::tableRemove(String* search_key);  //returns true if delete is successful (need to call tableRetrieve to see if the item is there)
{
	
}

template <class T>
ListDoublyLinkedIterator<T>* TableSortedList<T>::iterator();
{
	
}












#endif
