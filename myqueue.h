#ifndef MYQUEUE_H
#define MYQUEUE_H
#define MAX_SIZE 10000

template <class T>
class myqueue{
  private:
        // Declare necessary variables and methods
	T *array;
	int f;
	int r;
	int c;
  public:
        myqueue();
    	void enqueue(T x);
    	T front();
        T dequeue();
    	bool empty();
        int size();
	bool full();
};

template <class T> myqueue<T>::myqueue() {
	array = new T[MAX_SIZE];
	f = 0;
	r = -1;
	c = 0;
}

template <class T> void myqueue<T>::enqueue(T x) {
	r = (r + 1) % MAX_SIZE;
	array[r] = x;
	c++;
}

template <class T> T myqueue<T>::front() {
	return array[f];
}

template <class T> T myqueue<T>::dequeue() {
	int t = f;
	f = (f + 1) % MAX_SIZE;
	c--;
	return array[t];
}

template <class T> bool myqueue<T>::empty() {
	if (c == 0) {
		return true;
	}
	return false;
}

template <class T> int myqueue<T>::size() {
	return c;
}

template <class T> bool myqueue<T>::full() {
	if (c == MAX_SIZE) {
		return true;
	}
	return false;
}
#endif
