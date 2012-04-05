#ifndef ZNODE_H
#define ZNODE_H

#include <node.h>
#include <v8.h>

using namespace node;
using namespace v8;

class Znode : ObjectWrap
{
    
    public:
        static void Init(Handle<Object> target);
    private:
        
        Znode();
        ~Znode();

        static Handle<Value> New(const Arguments& args);
        static Handle<Value> eval(const Arguments& args);
        
        int x;

};

#endif
