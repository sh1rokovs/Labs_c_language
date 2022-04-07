#pragma once
#include <iostream>

using namespace std;

class TLink;
class TList;
typedef TLink* pTLink;

class TLink //Класс звена
{
	int Data;
	pTLink pNext;
public:
	TLink(int d, pTLink p) //Конструктор, создает звено с эл-ом и указателем
	{
		Data = d;
		pNext = p;
	}
	friend TList;
};

class TList //Класс Списка
{
	pTLink pFirst;
	pTLink tmp;
	pTLink pHead;
	pTLink pCurr;
	pTLink pPrev;
	pTLink pLast;
	pTLink pNew;
	pTLink pDel;
public:
	int size, pos;
public:
	TList(); //Конструктор
	~TList(); //Деструктор
	void DelFirst(); //Удалить первый элемент
	void clear(); //Удалить весь список
	int GetSize() { return size; } // Кол элементов в списке
	int& operator[](const int index); //Перезагруженный оператор []
	void InsLast(int val); //тавить последний элемент в список
	void InsFirst(int val); //Вставить первый эоемент в список
	void DelLast(); //Удалить последний элемент в списке
	void InsElem(int val, int index); //Вставить элемент в список
	void DelElem(int index); //Удалить элемент в списке
};

TList::TList()
{
	size = 0;
	pHead = nullptr;
}
void TList::InsLast(int val)
{
	if (pHead == nullptr)
	{
		pHead = new TLink(val,nullptr);
	}
	else
	{
		pCurr = this->pHead;
		while (pCurr->pNext != nullptr)
		{
			pCurr = pCurr->pNext;
		}
		pCurr->pNext = new TLink(val, nullptr);
	}
	size++;
}
TList::~TList()
{
	clear();
}
int& TList::operator[](const int index)
{
	int pos = 0;
	pCurr = this->pHead;
	while (pCurr != nullptr)
	{
		if (pos == index)
		{
			return pCurr->Data;
		}
		pCurr = pCurr->pNext;
		pos++;
	}
}
void TList::DelFirst()
{
	tmp = pHead;
	pHead = pHead->pNext;
	delete tmp;
	size--;
}
void TList::clear()
{
	while (size)
	{
		DelFirst();
	}
}
void TList::InsFirst(int val)
{
	pHead = new TLink(val, pHead);
	size++;
}
void TList::DelLast()
{
	DelElem(size - 1);
}
void TList::InsElem(int val, int index)
{
	if (index == 0)
	{
		InsFirst(val);
	}
	else
	{
		if (index > size - 1)
		{
			InsLast(val);
		}
		else
		{
			pPrev = this->pHead;
			for (int i = 0; i < index - 1; i++)
			{
				pPrev = pPrev->pNext;
			}
			pNew = new TLink(val, pPrev->pNext);
			pPrev->pNext = pNew;

			size++;
		}
	}
}

void TList::DelElem(int index)
{
	if (index == 0)
	{
		DelFirst();
	}
	else
	{
		pPrev = this->pHead;
		for (int i = 0; i < index - 1; i++)
		{
			pPrev = pPrev->pNext;
		}
		pDel = pPrev->pNext;
		pPrev->pNext = pDel->pNext;
		delete pDel;
		size--;
	}
}
