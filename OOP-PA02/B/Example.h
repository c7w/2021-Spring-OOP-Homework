#ifndef __EXAMPLE__
#define __EXAMPLE__
	
class Example {
		
   private:
    // (1)
 	static int memberCount;
 	int data = 0;
 	int id = 0;

public:
	
	Example(int data);
	void getData();
	~Example();

};
		
#endif