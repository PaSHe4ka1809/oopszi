#include "iostream"
using namespace std;

template <typename T>
class DequeTemplate
{
	T* arr;
	int count;
	int end = 0, size = 0;

public:
	DequeTemplate(int count)
		: count(count)
	{
		this->count = count;
		arr = new T[count];
	}
	DequeTemplate(const DequeTemplate& other)
	{
		arr = new T[other.count];
		count = other.count;
		end = other.end;
		size = other.size;
		for (int i = 0; i < count; ++i)
		{
			arr[i] = other.arr[i];
		}
	}
	DequeTemplate(DequeTemplate&& other)
	{
		arr = other.arr;
		count = other.count;
		other.arr = nullptr;
	}
	~DequeTemplate()
	{
		delete[] arr;
	}
	DequeTemplate& operator=(const DequeTemplate& other)
	{
		if (this == &other)
		{
			return *this;
		}
		delete[] arr;
		arr = new T[other.count];
		count = other.count;
		for (int i = 0; i < count; ++i)
		{
			arr[i] = other.arr[i];
		}
	}
	DequeTemplate& operator=(DequeTemplate&& other)
	{
		if (this == &other)
		{
			return *this;
		}
		delete[] arr;
		arr = other.arr;
		count = other.count;
		other.arr = nullptr;
	}
	int GetSize() const
	{
		return this->size;
	}
	void PushFront(const T &element)
	{
		if (size <= count)
		{
			int* tmp = new int[size];
			for (int i = 0; i <= size; i++)
			{
				tmp[i] = arr[i];
			}
			for (int i = 0; i <= size; i++)
			{
				arr[i + 1] = tmp[i];
			}
			arr[0] = element;
			size++;
			end++;
		}
	}
	void PushBack(const T &element)
	{
		if (size <= count)
		{
			end += 1;
			arr[end] = element;
			size++;
		}
	}
	T PopFront()
	{
		if (size <= count)
		{
			for (int i = 0; i < end; i++)
			{
				arr[i] = arr[i + 1];
			}
			arr[end] = 0;
			end--;
			size--;
		}
		return 0;
	}
	T PopBack()
	{
		if (size <= count)
		{
			arr[end] = 0;
			end--;
			size--;
		}
		return 0;
	}
	T PeekFront() const
	{
		return arr[0];
	}
	T PeekBack() const
	{
		return arr[end];
	}
	void GetFirst(T element)
	{
		arr[0] = element;
		size++;
	}
	bool CheckNoEmptyStack() const
	{
		return (size > 0);
	}
	friend ostream& operator<<(ostream& stream, DequeTemplate& a)
	{
		for (int i = 0; i < a.size; i++)
			stream << a.arr[i] << " ";
		return stream;
	}
};