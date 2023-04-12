#if !defined STACK_DEQUE_H
#define STACK_DEQUE_H

#include "DequeArray.h"

template <class T>
class StackDeque { //Deque for LiFo - Last in, First out.
private:
	DequeA<T>* sDeque; //Used to impliment DequeArray and its functions
public:
	//Pre: Constructor, create a stack deque that utilizes an array
	//Post: Array to hold objects is created
	StackDeque();
	//Pre: Array is created in dynamic memory
	//Post: Array is deleted from dynamic memory
	~StackDeque();

	//Pre: Adding an item to the FRONT of the stack/array is desired
	//Post: Item is added to FRONT of array, Lifo Last in array is oldest item
	void Push(T* item);
	//Pre: Removal of an item from the FRONT of the array is desired
	//Post: Item is removed from FRONT of array
	void Pop();
	//Pre: As long as array is not empty, assigns pointer to BACK of array to 'peek' at the object placed there.
	//Post: The object at the BACK element is returned following Lifo since it is the oldest object
	T* Peek();

	//Pre: An array has been constructed
	//Post: Returns current size of the array (indices occupied)
	int size();
	//Pre: Array is constructed
	//Post: Return true if the array is empty
	bool isEmpty();
	//Pre: Deque is holding items
	//Post: Items are removed from back until currentSize is 0, default array is reset.
	void dequeueAll();
};

template<class T>
inline StackDeque<T>::StackDeque() {
	sDeque = new DequeA <T>();
}

template<class T>
inline StackDeque<T>::~StackDeque() {
	delete sDeque;
}

template<class T>
inline void StackDeque<T>::Push(T* item) {
	sDeque->enqueueDeque(item);
}

template<class T>
inline void StackDeque<T>::Pop() {
	sDeque->dequeue();
}

template<class T>
inline T* StackDeque<T>::Peek() {
	return sDeque->peek(); //view oldest widget for LiFo
}

template<class T>
inline int StackDeque<T>::size() {
	return sDeque->size();
}

template<class T>
inline bool StackDeque<T>::isEmpty() {
	return sDeque->isEmpty();
}

template<class T>
inline void StackDeque<T>::dequeueAll() {
	sDeque->DequeueAll();
}
#endif
