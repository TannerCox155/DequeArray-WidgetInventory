#if !defined DEQUE_ARRAY_H
#define DEQUE_ARRAY_H

template <class T>
class DequeA {
private:
	int back;		//keeps track of last element
	int front;		//keeps track of first element
	int currentSize;//return the current amount of indices occupied
	T** items;		//object array of pointers
	int capacity;	//total array capacity

	//Pre: Array is constructed, user tries to store more objects than capacity.
	//Post: Old array capacity is *2 and assigned as capacity for new array, old array is deleted and items is set to use new array.
	void resize();
public:
	//Pre: Constructor, sets up a default array to store objects. 
	//Post: Array of pointers 'items' is assigned a new array of objects. Front and back of array are initialized.
	DequeA();
	//Pre: Destructor, an array is created by constructor
	//Post: items array is deleted from dynamic memory
	~DequeA();

	//Pre: Adding an object to the BACK of the array is desired
	//Post: Item is added to the BACK element of the array
	void enqueue(T* item);
	//Pre: Removal of an item from the FRONT of the array is desired
	//Post: Item is removed from FRONT of array
	void dequeue();
	//Pre: As long as array is not empty, assigns pointer to FRONT of array to 'peek' at the object placed there.
	//Post: The object at the FRONT element is returned
	T* peek();

	//Pre: Adding an object to the FRONT of the array is desired
	//Post: Item is added to FRONT of the array
	void enqueueDeque(T* item);
	//Pre: Removal of an item from the BACK of the array is desired
	//Post: Item is removed from BACK of array 
	void dequeueDeque();
	//Pre: As long as array is not empty, assigns pointer to BACK of array to 'peek' at the object placed there.
	//Post: The object at the BACK element is returned
	T* peekDeque();
	//Pre: Deque is holding items
	//Post: Items are removed from back until currentSize is 0, default array is reset.
	void DequeueAll();

	//Pre: An array has been constructed
	//Post: Returns current size of the array (indices occupied)
	int size();
	//Pre: Array is constructed
	//Post: Return true if the array is empty
	bool isEmpty();
};

template<class T>
inline void DequeA<T>::resize() {
	T** newArray = new T * [capacity * 2]; //creates new object array of current capcity * 2
	int j = front;						   //local variable to keep track of front element
	for (int i = 0; i < capacity; i++) {   //iterate from 0 to total capacity
		newArray[i] = items[j]; //newarray is assigned values from the old array
		j++; //j is incremented to continue iterating from front to total capacity
		if (j == capacity) j = 0; //if j reaches the total capacity, j set to 0 to end iteration
	}
	delete[] items; //deletes old items
	items = newArray; //new array is stored in previous and now empty object array
	//Some assignments for front and back
	front = 0; //front is set to return to 0
	back = capacity - 1; //back set to total capacity minus 1 meaning back is 1 element before total capacity
	capacity *= 2; //array is resized
}

template<class T>
inline DequeA<T>::DequeA() {
	capacity = 2; //default capacity 2
	front = 0;
	currentSize = 0;
	items = new T * [capacity]; //default list size is 2
	back = capacity - 1; //back is at element 1
}

template<class T>
inline DequeA<T>::~DequeA() {
	delete[] items; //deletes stored items from object
}

template<class T>
inline void DequeA<T>::enqueue(T* item) {
	if (capacity == currentSize) resize(); //check for validity, resize if array is full
	back++;	//increment back
	if (back == capacity) back = 0; //set back to 0 if its equal to capacity
	items[back] = item; //item at back holds item passed
	currentSize++; //increment the current size
}

template<class T>
inline void DequeA<T>::dequeue() {
	T* item = nullptr; //pointer object assigned as null
	if (!isEmpty()) { //if the list is NOT empty
		item = items[front]; //assigns item object pointer with front of array
		items[front] = nullptr; //original front assigned null, essentially switches.
		front++; //front is incremented
		if (front == capacity) front = 0; //if front is equal to the capacity of the array, assign front with 0
		currentSize--; //decrement currentsize
	}
}

template<class T>
inline T* DequeA<T>::peek() {
	T* item = nullptr;
	if (!isEmpty()) //if array is not empty, assigns object pointer from null to the item at the front of the array
		item = items[front];
	return item; //returns that item
}

template<class T> //add to front of list
inline void DequeA<T>::enqueueDeque(T* item) {
	if (capacity == currentSize) { resize(); }
	front--; //decrement front 1 position
	if (front == -1) front = capacity - 1;
	items[front] = item; // front element now holds item passed by user
	currentSize++; // increment current size of list
}

template<class T> //remove from back of list
inline void DequeA<T>::dequeueDeque() { //check  remove from back
	T* item = nullptr; //create local item
	if (!isEmpty()) { //make sure array is not empty
		item = items[back]; //assign item with the item located at back of array
		items[back] = nullptr; //set item at back of the array to null
		back--; //decrement back
		if (back == capacity) back = capacity - 1; //back should be the same number as capacity, subtract 1
		currentSize--; //decrement current size of array
	}
}

template<class T> //view last element
inline T* DequeA<T>::peekDeque() {
	T* item = nullptr;
	if (!isEmpty())
		item = items[back];
	return item;
}

template<class T>
inline void DequeA<T>::DequeueAll() {
	while (currentSize > 0) {
		DequeA()->dequeueDeque();
		currentSize--;
	}
	capacity = 2;
	front = 0;
	currentSize = 0;
	items = new T * [capacity];
	back = capacity - 1;
}

template<class T> //Return indices occupied
inline int DequeA<T>::size() {
	return currentSize;
}

template<class T> //return true if array is empty
inline bool DequeA<T>::isEmpty() {
	return currentSize == 0;
}

#endif
