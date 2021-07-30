#pragma once
#include "User.h"
#include "EncryptStrategy.h"
#include "VerificationStrategy.h"
#include <iostream>
using namespace std;


class UserProxy
{

    RealUser *ru;
    EncryptStrategy *e;
    VerificationStrategy *v;

public:
    UserProxy(RealUser *ruser, EncryptStrategy *es, VerificationStrategy *vs)
    {
        ru = ruser;
        e = es;
        v = vs;
    }

    void sendMessage(std::string message)
    {
        string ms;
        ms += e->encode(message);
        ms += "\n";
        ms += v->verify(message);
        ru->sendMessage(ms);
    }
};