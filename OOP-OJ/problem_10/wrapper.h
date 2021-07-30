#include "wrapper_counter.h"
using namespace std;

class AbstractWrapper {
	string uid;
public:
	AbstractWrapper(string _uid){
		uid = _uid;
	}
	virtual string type() = 0;
	virtual string to_string() = 0;
	friend ostream &operator <<(ostream &out, AbstractWrapper *w) {
		return out << w->uid << ": " << w->to_string();
	}
	virtual ~AbstractWrapper() {}
};

class IntegerWrapper : public AbstractWrapper {
	int *ptr;
public:
	IntegerWrapper(int *ptr)
		: AbstractWrapper(WrapperCounter::getUID(type())), ptr(ptr) {}
	virtual string type() { return "int"; }
	virtual string to_string() {
		return std::to_string(*ptr);
	}
	~IntegerWrapper() { delete ptr; }
};

class StringWrapper : public AbstractWrapper
{
protected:
	char *ptr;
	int len;
public:
	StringWrapper(char *ptr, int len)
		: AbstractWrapper(WrapperCounter::getUID(type())), ptr(ptr), len(len) {}
	StringWrapper(string uid, char *ptr, int len)
		: AbstractWrapper(uid), ptr(ptr), len(len) {}
	~StringWrapper() { delete[] ptr; }
	int length() { return len; }
	virtual string type() { return "string"; }
	virtual string to_string() {
		return string(ptr, len);
	}
};

class ChineseStringWrapper : public StringWrapper
{
	// 用三个char表示一个汉字
public:
	ChineseStringWrapper(char *ptr, int len)
		: StringWrapper(WrapperCounter::getUID(type()), ptr, len) {}
	// ~ChineseStringWrapper() { delete[] ptr; }
	virtual string type() { return "chineseString"; }
	int length(bool rawChars=true) {
		// 如果rawChars为false，则返回中文字符数；否则返回实际char数组长度
		if (rawChars) return len;
		else return len / 3;
	}
};
