#pragma once

class BaseTree{
private:
	int tree[1000];
public:
    BaseTree() { for(int i = 0; i < 1000; ++i) tree[i] = 0;}
	int lowbit(int x){
		return x&(-x);
	}
	void update(int i, int x)
	{
	    while(i < 1000){
	        tree[i] += x;
	        i += lowbit(i);
	    }
	    return ;
	}
	int getsum(int i){        
		int res = 0;
		while(i > 0){
	        res += tree[i];
	        i -= lowbit(i);
	    }
	    return res;
	}
};