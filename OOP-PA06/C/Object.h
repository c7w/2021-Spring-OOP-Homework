#pragma once
#include <list>
#include <iostream>
#include <memory>

#include "CustomClass.h"

class Object;

class Content
{
public:
	virtual std::ostream& output(std::ostream& out){ //virtual function for output
		out << "the operator is not supported for this type." << std::endl;
		return out;
	}
	virtual Content &operator+=(int data) { return *this;  }
	virtual Content &operator+=(std::string data) { return *this; }
	virtual Object &operator[](int num) {  }
};

class IntContent: public Content
{
private:
	int x;
public:
	IntContent(int _x): x(_x) {}
	std::ostream& output(std::ostream &out)
	{ 
		out << x;
		return out;
	}
	virtual IntContent& operator+=(int data){
		this->x += data;
		return *this;
	}
};
class StringContent: public Content
{
private:
	std::string x;
public:
	StringContent(std::string _x): x(_x) {}
	std::ostream &output(std::ostream &out)
	{
		out << x;
		return out;
	}
	virtual StringContent &operator+=(std::string data)
	{
		this->x += data;
		return *this;
	}
};

class VectorContent: public Content
{
private:
    std::vector<Object> x; //Object is not defined???
public:
 	VectorContent(const std::vector<Object>& _x): x(_x) {}
	virtual Object& operator[](int num) {
		return x[num];
	}
};

class CustomContent: public Content
{
private:
	CustomClass x;
public:
	CustomContent(const CustomClass& _x): x(_x) {}
};

class Object
{
private:
	std::shared_ptr<Content> pt;
	// Content *pt;

public:
	Object() {}
	Object(int x) {
		pt = std::shared_ptr<Content>(new IntContent(x)); // where to delete? maybe use std::shared_ptr?
	}
	Object(const std::string &x){
		pt = std::shared_ptr<Content>(new StringContent(x));
		// pt = new StringContent(x);
	}
	Object(const std::vector<Object> &x){
		pt = std::shared_ptr<Content>(new VectorContent(x));
		// pt = new VectorContent(x);
	}
	Object(const CustomClass &x){
		pt = std::shared_ptr<Content>(new CustomContent(x));
		//pt = new CustomContent(x);
	}

	friend std::ostream& operator<<(std::ostream& out, const Object& obj) {
		obj.pt->output(out);
		return out;
	}

	Object& operator+=(int y){
		pt->operator+=(y);
		return *this;
	}
	Object& operator+=(const std::string &y){
		pt->operator+=(y);
		return *this;
	}

	//need more operators......

	Object& operator[](int num){
		return pt->operator[](num);
	}

	
};
