#include <iostream>
using namespace std;

template<typename T>
class Base
{
public:
	virtual void PushFront(const T &element) {}
	virtual void PushBack(const T &element) {}
	virtual T PopFront() = 0;
	virtual T PopBack() = 0;
	virtual int GetSize() const = 0;
	virtual T PeekFront() const = 0;
	virtual T PeekBack() const = 0;
	virtual void GetFirst() {}
	virtual ~Base() {}
};
template<typename T>
class DequeTemp : Base<T>
{
public:
	DequeTemp()
	{
		head_ = NULL;
		tail_ = NULL;
		size_ = 0;
	}
	DequeTemp(const DequeTemp& other)
	{
		head_ = NULL;
		tail_ = NULL;
		size_ = 0;
		Node<T>* temp = new Node<T>();
		while (temp->pNext_ != other.tail_)
		{
			PushBack(temp->data_);
			temp = temp->pNext_;
		}
		PushBack(temp->data_);
	}
	DequeTemp(DequeTemp&& other)
	{
		head_ = NULL;
		tail_ = NULL;
		size_ = 0;
		Node<T>* temp = new Node<T>();
		while (temp->pNext_ != other.tail_)
		{
			PushBack(other.deQueue());
			temp = temp->pNext_;
		}
		PushBack(temp->data_);
	}
	~DequeTemp()
	{
		while (size_)
			PopFront();
	}
	int GetSize() const
	{
		return size_;
	}
	void PushFront(const T &element)
	{
		if (head_ == NULL)
		{
			head_ = new Node<T>(element);
			tail_ = head_;
		}
		else
		{
			head_->pPrev_ = new Node<T>(element, head_, NULL);
			head_ = head_ -> pPrev_;
		}
		size_++;
	}
	void PushBack(const T &element) 
	{
		if (head_ == NULL)
		{
			head_ = new Node<T>(element);
			tail_ = head_;
		}
		else
		{
			tail_->pNext_ = new Node<T>(element, NULL, tail_);
			tail_ = tail_->pNext_;
		}
		size_++;
	}
	T PopFront()
	{
		Node<T>* temp = head_; 
		head_ = head_->pNext_; 
		head_->pPrev_ = NULL;
		delete temp; 
		size_--;
	}
	T PopBack()
	{
		Node<T>* temp = tail_; 
		tail_ = tail_->pPrev_; 
		tail_->pNext_ = NULL;
		delete temp; 
		size_--;
	}
	T PeekFront() const
	{
		return head_->data_;
	}
	T PeekBack() const
	{
		return tail_->data_;
	}
	DequeTemp<T>& operator=(const DequeTemp<T>& other)
	{
		if (this == &other)
			return *this;
		head_ = NULL;
		tail_ = NULL;
		size_ = 0;
		Node<T>* temp = new Node<T>();
		while (temp->pNext_ != other.tail_)
		{
			PushBack(temp->data_);
			temp = temp->pNext_;
		}
		PushBack(temp->data_);
	}
	DequeTemp<T>& operator=(DequeTemp<T>&& other)
	{
		if (this == &other)
			return *this;
		head_ = NULL;
		tail_ = NULL;
		size_ = 0;
		Node<T>* temp = new Node<T>();
		while (temp->pNext_ != other.tail_)
		{
			PushBack(other.PopFront());
			temp = temp->pNext_;
		}
		PushBack(temp->data);
	}
	friend ostream& operator<<(ostream &out, DequeTemp &q)
	{
		Node<T>* temp = q.head_;
		while (temp->pNext_ != NULL)
		{
			int test = temp->data_;
			out << temp->data_ << " ";
			temp = temp->pNext_;
		}
		out << temp->data_ << " ";
		return out;
	}
private:
	template<typename T>
	class Node
	{
	public:
		Node(T data, Node* pNext = NULL, Node* pPrev = NULL)
		{
			data_ = data;
			pNext_ = pNext;
			pPrev_ = pPrev;
		}
		Node* pNext_;
		Node* pPrev_;
		T data_;
	};
	Node<T>* head_;
	Node<T>* tail_;
	int size_;
};