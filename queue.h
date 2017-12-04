#pragma once

template <class T>
class TQueue {
	int first, last, size, maxsize;
	T* tarray;

public:
	TQueue(int _size = 200);
	TQueue(const TQueue<T>& tq);
	~TQueue();

	bool isempty();
	bool isfull();
	
	int getsize();
	int getmaxsize();
	
	void push(T element);
	T pop();

	T getfirst();
	T getlast();

	TQueue<T>& operator=(const TQueue<T>& tq);
};

template <class T>
TQueue<T>::TQueue(int _size) {
	if (_size <= 0) throw "uncorrect value of maxsize in constructor";
	maxsize = _size;
	size = 0;
	first = 0;
	last = -1;

	tarray = new T[size];
}

template <class T>
TQueue<T>::~TQueue() {
	delete[] tarray;
}

template <class T>
TQueue<T>::TQueue(const TQueue<T>& tq) {
	if (this == &tq) throw "can't assign object to itself";
	maxsize = tq.maxsize;
	size = tq.size;
	first = tq.first;
	last = tq.last;

	tarray = new T[maxsize];
	for (int i = 0; i < maxsize; i++) {
		tarray[i] = tq.tarray[i];
	}
}

template <class T>
bool TQueue<T>::isempty() {
	return !size;
}

template <class T>
bool TQueue<T>::isfull() {
	return size == maxsize;
}

template <class T>
int TQueue<T>::getsize() {
	return size;
}

template <class T>
int TQueue<T>::getmaxsize() {
	return maxsize;
}

template <class T>
void TQueue<T>::push(T element) {
	if (isfull()) throw "push to full queue";
	
	if (last == maxsize - 1) last = 0;
	else last++;
	tarray[last] = element;
	size++;
}

template <class T>
T TQueue<T>::pop() {
	if (isempty()) throw "pop from full queue";

	T tmp = tarray[first];
	if (first == maxsize - 1) first = 0;
	else first++;
	size--;
	return tmp;
}

template <class T>
T TQueue<T>::getfirst() {
	return tarray[first];
}

template <class T>
T TQueue<T>::getlast() {
	return tarray[last];
}

template <class T>
TQueue<T>& TQueue<T>::operator=(const TQueue<T>& tq) {
	if (this == &tq) throw "can't assign object to itself";
	if (maxsize != tq.maxsize) {
		maxsize = maxsize;
		delete[] tarray;
		tarray = new T[maxsize];
	}
	size = tq.size;
	first = tq.first;
	last = tq.last;
	for (int i = 0; i < maxsize; i++) {
		tarray[i] = tq.tarray[i];
	}

	return *this;
}




