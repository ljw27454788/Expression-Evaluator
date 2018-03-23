#ifndef MYSTACK_H
#define MYSTACK_H
#define MAX_SIZE 10000

using namespace std;
template <class T>
class mystack{
  private:
        // Declare necessary variables and methods
	T *array;
	int pe;
  public:
        mystack();
        void push(T x);
        T top();
        T pop();
        bool empty();
        int size();
	bool full();
};

template <class T> mystack<T>::mystack() {
	array = new T[MAX_SIZE];
	pe = -1;
}

template <class T> void mystack<T>::push (T x) {

	array[++pe] = x;
	
}

template <class T> T mystack<T>::top() {
	

	return array[pe];
}

template <class T> T mystack<T>::pop() {
	
	
	return array[pe--];
}

template <class T> bool mystack<T>::empty() {
	return pe == -1;
}

template <class T> int mystack<T>::size() {
	return pe + 1;
}

template <class T> bool mystack<T>::full() {
	return pe == MAX_SIZE - 1;
}
#endif
