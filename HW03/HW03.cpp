#include <iostream>
#include <stdexcept>

template <typename T>
class SimpleVector {
private:
	T* data;
	int currentSize;
	int currentCapacity;

	void resize() {

	}

	// 기본 생성자 크기 10인 배열
public:
	SimpleVecotr() : currentSize(0), currentCapacity(10) {
		data = new T[currentCapacity];
		cout << "SimpleVector() called. Default capacity : " << currentCapacity << endl;
	}

	// 숫자를 하나 받는 생성자는 해당 숫자에 해당되는 크기 배열 생성
	SimpleVector(int capacity) : currentSize(0) {
		if (capacity <= 0) {
			cerr << "Warning" << endl;
			currentCapacity = 10;
		}
		else {
			currentCapacity = capacity;
		}
		data = new T[currentCapacity];
		cout << "SimpleVector (" << capacity << ") called. Capacity : " << currentCapacity << endl;
	}
	
	~SimpleVector() {
		delete[] data;
		data = nullptr;
		cout << "~SimpleVector() called. Memory deallocated.\n";
	}
	// push_back 인자 받고 원소 맨뒤에 추가, 반환값 x, 배열 크기 꽉 찼을 시 동작 x 
	void push_back(const T& value) {
		if (currentSize < currentCapacity) {
			data[currentSize] = value;
			currentSize++;

			cout << "Push back : " << value << ", Current size : " << currentSize << endl;
		}
		else {
			cout << "Capacity full. Cannot push back" << value << " Current size : " << currentSize << ", Capacity : " << currentCapacity << endl;
		}
	}

	// pop_back 벡터 마지막 원소 제거, 제거할 원소가 없으면 동작 x, 인자 및 반환 x
	void pop_back() {
		if (currentSize > 0) {
			currentSize--;
			cout << "Pop back Current size : " << currentSize << endl;
		}
		else {
			cout << "Vector is empty. Cannot pop back. Current size : " << currentSize << endl;
		}
	}
	// size 인자 없이 현재 원소의 개수 반환
	int size() const {
		return currentSize;
	}
	// capacity 현재 내부 배열의 크기 반환
	int capacity() const {
		return currentCapacity;
	}

};

// 복사 생성자 구현
// push_back 배열의 크기가 꽉 찼는데 원소가 더 들어온 경우 기존 배열보다 5 늘리고 새로운 원소 추가 (기존 값 유지)