#define BUILDING_NODE_EXTENSION
#include <node.h>
#include <v8.h>
#include <iostream>
#include <cstdio>

#include "Znode.h"

using namespace v8;
using namespace std;

Znode::Znode()
{
};

Znode::~Znode()
{
};

void Znode::Init( Handle<Object> target )
{
    HandleScope scope;

    Local<FunctionTemplate> tpl = FunctionTemplate::New(New);
    tpl->SetClassName(String::NewSymbol("Znode"));
    tpl->InstanceTemplate()->SetInternalFieldCount(1);
    tpl->PrototypeTemplate()->Set(String::NewSymbol("eval"),FunctionTemplate::New(eval)->GetFunction());
    
    Persistent<Function> constructor = Persistent<Function>::New(tpl->GetFunction());
    target->Set(String::NewSymbol("Znode"),constructor); 
}

Handle<Value> Znode::New( const Arguments& args )
{
    HandleScope scope;

    Znode* znode = new Znode();
    znode->Wrap(args.This());

    return args.This();

}

Handle<Value> Znode::eval( const Arguments& args )
{

    HandleScope scope;

    if( args.Length()<1 )
    {
        ThrowException(Exception::TypeError(String::New("at least one argument required.")));
    }
    if(!args[0]->IsString() )
    {
        ThrowException(Exception::TypeError(String::New("argument should be string.")));
    }
    return scope.Close(args[0]);
}


