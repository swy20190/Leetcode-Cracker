#include <iostream>

using namespace std;

class MyCircularQueue {
private:
	int capacity = 0;
	int size = 0;
	int* storage;
	int front = 0;
	int rear = 0;

public:
	/** Initialize your data structure here. Set the size of the queue to be k. */
	MyCircularQueue(int k) {
		capacity = k;
		storage = new int[k];
	}

	/** Insert an element into the circular queue. Return true if the operation is successful. */
	bool enQueue(int value) {
		if (isFull()) {
			return false;
		}
		size++;
		storage[rear] = value;
		rear = (rear + 1) % capacity;
		return true;
	}

	/** Delete an element from the circular queue. Return true if the operation is successful. */
	bool deQueue() {
		if (isEmpty()) {
			return false;
		}
		size--;
		front = (front + 1) % capacity;
		return true;
	}

	/** Get the front item from the queue. */
	int Front() {
		if (isEmpty()) {
			return -1;
		}
		return storage[front];
	}

	/** Get the last item from the queue. */
	int Rear() {
		if (isEmpty()) {
			return -1;
		}
		if (rear == 0) {
			return storage[capacity - 1];
		}
		else {
			return storage[rear - 1];
		}
	}

	/** Checks whether the circular queue is empty or not. */
	bool isEmpty() {
		return size == 0;
	}

	/** Checks whether the circular queue is full or not. */
	bool isFull() {
		return size == capacity;
	}
};