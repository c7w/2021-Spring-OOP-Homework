#pragma once

#include <iostream>

using namespace std;

class Test {
    
    int *buf;
    

   public:
    static int idPool;
    int id= 0;

    Test() {
        idPool++;
        id = idPool;
        buf = new int(0);
		cout << "[" << id <<  "+] Test(): this->buf @ " << hex << buf << endl;
	}
	Test(int val) {
        idPool++;
        id = idPool;
        buf = new int(val);
        cout << "[" << id << "+] Test(int): this->buf @ " << hex << buf
                                                            << endl;
    }
	~Test() {
        cout << "[" << id << "-] ~Test(): this->buf @ " << hex << buf << endl;
        if (buf) delete buf;
	}
	Test(const Test& t) : buf(new int(*t.buf)) {
        idPool++;
        id = idPool;
        cout << "[" << id << "+] Test(const Test&) called. this->buf @ "
                                      << hex << buf << endl;
    }
	Test(Test&& t) : buf(t.buf) {
        idPool++;
        id = idPool;
        cout << "[" << id << "+] Test(Test&&) called. this->buf @ " << hex
                         << buf << endl;
        t.buf = nullptr;
	}
	Test& operator= (const Test& right) {
        cout << "[" << "X" <<  "X] operator=(const Test& right) called. this->buf @ "
             << hex << buf << ". right->buf @ " << right.buf << endl;
        if (this != &right){
			if(buf) delete buf;
			buf = new int(*right.buf);
		}
		return *this;
	}
	Test& operator= (Test&& right) {
        cout << "[" << "X" << "X] operator=(Test&& right) called. this->buf @ "
             << hex << buf << ". right->buf @ " << right.buf << endl;
        if (this != &right){
			if(buf) delete buf;
			this->buf = right.buf;
			right.buf = nullptr;
		}
		return *this;
	}
	void print(const char *name) {
		cout << name << ".buf @ " << hex << buf << endl;
	}
};
