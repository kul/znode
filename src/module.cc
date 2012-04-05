#define BUILDING_NODE_EXTENSION
#include <node.h>
#include <v8.h>
#include <Znode.h>

using namespace v8;
using namespace node;

void InitAll(Handle<Object> target)
{
    HandleScope scope;
    Znode::Init(target);
}

NODE_MODULE(znode,InitAll)
