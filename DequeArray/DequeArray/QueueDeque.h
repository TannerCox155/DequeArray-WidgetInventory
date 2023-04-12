#if !defined QUEUE_DEQUE_H
#define QUEUE_DEQUE_H

#include "DequeArray.h"

template <class T>
class QueueDeque { //Deque for FiFo - First in, First out.
private:
	DequeA<T>* Deque; //Used to impliment DequeArray and its functions
public:

	//Pre: Constructor, create a queue deque that utilizes an array
	//Post: Array to hold objects is created
	QueueDeque();
	//Pre: Array is created in dynamic memory
	//Post: Array is deleted from dynamic memory
	~QueueDeque();

	//Pre: Adding an item to the FRONT of the deque/array is desired, FiFo First in
	//Post: Function is using enqueueDeque from DequeArray in order to work with the idea of FiFo, item is added to front of array
	void Enqueue(T* item);
	//Pre: Removal of an item from the BACK of the array is desired, First in, First out
	//Post: Item is removed from BACK of array
	void Dequeue();
	//Pre: As long as array is not empty, assigns pointer to FRONT of array to 'peek' at the object placed there.
	//Post: The object at the FRONT element is returned following FiFo First out
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
inline QueueDeque<T>::QueueDeque() {
	Deque = new DequeA <T>();
}

template<class T>
inline QueueDeque<T>::~QueueDeque() {
	delete Deque;
}

template<class T>
inline void QueueDeque<T>::Enqueue(T* item) {
	Deque->enqueueDeque(item);
}

template<class T>
inline void QueueDeque<T>::Dequeue() {
	Deque->dequeueDeque();
}

template<class T>
inline T* QueueDeque<T>::Peek() {
	return Deque->peek();
}

template<class T>
inline int QueueDeque<T>::size() {
	return Deque->size();
}

template<class T>
inline bool QueueDeque<T>::isEmpty() {
	return Deque->isEmpty();
}

template<class T>
inline void QueueDeque<T>::dequeueAll() {
	Deque->DequeueAll();
}

#endif
