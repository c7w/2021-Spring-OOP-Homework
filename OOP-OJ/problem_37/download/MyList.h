#pragma once
#include <list>
#include <memory>
#include <iostream>

class MyList
{
public:
	std::shared_ptr< std::list<int> > pt; // a pointer to the real container
	std::list<int>::iterator left, right; // the position of slice is [left, right). 'left' is included, 'right' is excluded.


	std::list<int>::iterator forward(int pos) const{
		// count from 'left', find the element at position 'pos'.
		auto now = left;
		while(pos>0)
		{
			now++;
			pos--;
		}
		return now;
	}


	MyList() {
		std::list<int> *myl = new std::list<int>;
		pt = std::shared_ptr<std::list<int>>(myl);
		left = myl->begin();
		right = myl->end();
		// Actually, left = right = pt->end(), because there is no element in the list.
	}

	MyList(std::shared_ptr<std::list<int>> _pt, int a, int b)
	{
		pt = _pt;
		auto begin = pt->begin();
		left = right = begin;
		for (int i = 0; i < a; i++)
		{
			left++;
		}
		for (int i = 0; i < b; i++)
		{
			right++;
		}
	}

	void append(int i)
	{
		pt->insert(right, i); //insert i just before 'right'. 'right' and 'left' will be still valid (because we use list, not vector).
		// pt->push_back(1);
		// DEBUG !! Why I can't insert i??
		if(pt->size() == 1)
		{
			left = pt->begin();
			right = pt->end();
		}
	}

	int& operator[](int pos) const{
		return *forward(pos); // access the element at the 'pos'
	}

	void output(std::ostream& out){
		out << "[";
		if (left != right){
			auto now = left;
			out << *now;
			now ++;
			for(; now != right; now++){
				out << "," << *now;
			}
		}
		out << "]";
	}

	friend std::ostream &operator<<(std::ostream &out, MyList &list)
	{
		list.output(out);
		return out;
	}

	MyList operator()(int a, int b)
	{
		return MyList(pt, a, b);
	}
};