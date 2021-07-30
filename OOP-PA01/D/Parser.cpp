#include "Parser.h"
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

void outputUpperCase(char* a){
    int len = strlen(a);
    for (int i = 0; i<len; i++){
        if(a[i]>='a' && a[i]<='z'){
            cout << (char)(a[i] + 'A' - 'a');
        }
    }
}

bool notInt(char* a){
    int len = strlen(a);
    for (int i = 0; i < len; i++) {
        if (a[i] < '0' || a[i] > '9') {
            return true;
        }
    }
    return false;
}

void Parser::add_argument(char* argNameRaw, int val, char* desp){
    pos++;
    Argument newArg(argNameRaw+2, val, desp);
    s[pos] = newArg;
}

void Parser::help(){
    cout << "usage: ./main [--help]";
    for (int i = 1; i <= pos; i++){
        cout << " [--" << s[i].GetArgName() << " " ;
        outputUpperCase(s[i].GetArgName());
        cout << "]";
    }
    cout << "\n";
    cout << "\n";
    cout << "optional arguments:\n";
    cout << " --help show this help message and exit";
    for (int i = 1; i <= pos; i++) {
        cout << "\n";
        cout << " --" << s[i].GetArgName() << " ";
        outputUpperCase(s[i].GetArgName());
        cout << "   " << s[i].GetDesp();
    }
    exit(0);
}

void Parser::unRecoArg(char* a){
    cout << "usage: ./main [--help]";
    for (int i = 1; i <= pos; i++) {
        cout << " [--" << s[i].GetArgName() << " ";
        outputUpperCase(s[i].GetArgName());
        cout << "]";
    }
    cout << "\n";
    cout << "./main: error: unrecognized arguments: --" << a;
    exit(0);
}

void Parser::expArg(char* a) {
    cout << "usage: ./main [--help]";
    for (int i = 1; i <= pos; i++) {
        cout << " [--" << s[i].GetArgName() << " ";
        outputUpperCase(s[i].GetArgName());
        cout << "]";
    }
    cout << "\n";
    cout << "./main: error: argument --" << a << ": expected an argument";
    exit(0);
}

void Parser::ilVal(char* a, char* b) {
    cout << "usage: ./main [--help]";
    for (int i = 1; i <= pos; i++) {
        cout << " [--" << s[i].GetArgName() << " ";
        outputUpperCase(s[i].GetArgName());
        cout << "]";
    }
    cout << "\n";
    cout << "./main: error: argument --" << a << ": invalid int value: '" << b
         <<"'";
    exit(0);
}

void Parser::init(int argc, char* argv[]) {
    for (int i = 1; i < argc; i++){
        if(strcmp(argv[i], "--help") == 0){
            help();
        }
    }
    for (int i = 1; i < argc; i+=2){
        char* a = argv[i];
        a += 2;
        int ida = get_argument_byId(a);
        if(ida==-1){
            unRecoArg(a);
        }

        if(i+1 == argc){
            expArg(a);
        }

        char *b = argv[i+1];
        int val;
        if(notInt(b)){
            ilVal(a, b);
        }
        val = atoi(b);
            
        set_argument_byId(ida, val);
    }
}

int Parser::get_argument(char* argName){
    for (int i = 1; i <= pos; i++){
        if(strcmp(s[i].GetArgName(), argName) == 0){
            return s[i].GetVal();
        }
    }
    return 404;
}

int Parser::get_argument_byId(char* argName){
    for (int i = 1; i <= pos; i++){
        if(strcmp(s[i].GetArgName(), argName) == 0){
            return i;
        }
    }
    return -1;
}

void Parser::set_argument_byId(int id, int val){
    s[id].SetVal(val);
}