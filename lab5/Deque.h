#include "iostream"
using namespace std;

class Deque
{
	int* arr;
	int count;
	int end = 0, size = 0;
public:
	void insertBefore(const int& value, int index);
	Deque();
	Deque(int count);
	Deque(const Deque& other);
	Deque(Deque&& other);
	~Deque();
	int GetSize() const;
	void PushFront(const int &element);
	void PushBack(const int &element);
	void PopFront();
	void PopBack();
	int PeekFront() const;
	int PeekBack() const;
	void GetFirst(int element);
	bool CheckNoEmptyStack() const;
	Deque& operator=(const Deque& other);
	Deque& operator=(Deque&& other);
	friend ostream& operator << (ostream& stream, const Deque& a);
};