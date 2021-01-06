class MyCircularDeque {
	int* elem;
	int size;
	int capacity;
public:
	/** Initialize your data structure here. Set the size of the deque to be k. */
	MyCircularDeque(int k) {
		elem = new int[k];
		size = 0;
		capacity = k;
	}

	/** Adds an item at the front of Deque. Return true if the operation is successful. */
	bool insertFront(int value) {
		if (isFull()) {
			return false;
		}
		else {
			for (int i = size; i >= 1; i--) {
				elem[i] = elem[i - 1];
			}
			elem[0] = value;
			size++;
			return true;
		}
	}

	/** Adds an item at the rear of Deque. Return true if the operation is successful. */
	bool insertLast(int value) {
		if (isFull()) {
			return false;
		}
		else {
			elem[size] = value;
			size++;
			return true;
		}
	}

	/** Deletes an item from the front of Deque. Return true if the operation is successful. */
	bool deleteFront() {
		if (isEmpty()) {
			return false;
		}
		else {
			for (int i = 0; i < size-1; i++) {
				elem[i] = elem[i + 1];
			}
			size--;
			return true;
		}
	}

	/** Deletes an item from the rear of Deque. Return true if the operation is successful. */
	bool deleteLast() {
		if (isEmpty()) {
			return false;
		}
		else {
			size--;
			return true;
		}
	}

	/** Get the front item from the deque. */
	int getFront() {
		if (isEmpty()) {
			return -1;
		}
		return elem[0];
	}

	/** Get the last item from the deque. */
	int getRear() {
		if (isEmpty()) {
			return -1;
		}
		return elem[size - 1];
	}

	/** Checks whether the circular deque is empty or not. */
	bool isEmpty() {
		return size == 0;
	}

	/** Checks whether the circular deque is full or not. */
	bool isFull() {
		return size == capacity;
	}
};
