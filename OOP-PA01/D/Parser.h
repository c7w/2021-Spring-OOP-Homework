#include <string>
using namespace std;

class Argument {
    char* argName;
    int val;
    char* desp;
   
   public:
    Argument(){

    }

    Argument(char* argName, int val, char* desp) { 
        this->argName = argName;
        this->val = val;
        this->desp = desp;
    }

    char* GetArgName() const {
        return argName;
    }

    void SetArgName(char* argName) {
        this->argName = argName;
    }

    int GetVal() const {
        return val;
    }

    void SetVal(int val) {
        this->val = val;
    }

    char* GetDesp() const {
        return desp;
    }

    void SetDesp(char* desp) {
        this->desp = desp;
    }


};

class Parser {
   private:
    int pos = 0;
    Argument s[2001];

    void help();
    void unRecoArg(char* a);
    void expArg(char* a);
    void ilVal(char* a, char*b);

   public:
    void add_argument(char* argName, int val, char* desp);
    void init(int argc, char* argv[]);
    int get_argument(char* argName);
    int get_argument_byId(char* argName);
    void set_argument_byId(int id, int val);

    
};