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

	// �⺻ ������ ũ�� 10�� �迭
public:
	SimpleVecotr() : currentSize(0), currentCapacity(10) {
		data = new T[currentCapacity];
		cout << "SimpleVector() called. Default capacity : " << currentCapacity << endl;
	}

	// ���ڸ� �ϳ� �޴� �����ڴ� �ش� ���ڿ� �ش�Ǵ� ũ�� �迭 ����
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
	// push_back ���� �ް� ���� �ǵڿ� �߰�, ��ȯ�� x, �迭 ũ�� �� á�� �� ���� x 
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

	// pop_back ���� ������ ���� ����, ������ ���Ұ� ������ ���� x, ���� �� ��ȯ x
	void pop_back() {
		if (currentSize > 0) {
			currentSize--;
			cout << "Pop back Current size : " << currentSize << endl;
		}
		else {
			cout << "Vector is empty. Cannot pop back. Current size : " << currentSize << endl;
		}
	}
	// size ���� ���� ���� ������ ���� ��ȯ
	int size() const {
		return currentSize;
	}
	// capacity ���� ���� �迭�� ũ�� ��ȯ
	int capacity() const {
		return currentCapacity;
	}

};

// ���� ������ ����
// push_back �迭�� ũ�Ⱑ �� á�µ� ���Ұ� �� ���� ��� ���� �迭���� 5 �ø��� ���ο� ���� �߰� (���� �� ����)