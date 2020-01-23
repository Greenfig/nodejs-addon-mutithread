#include <node.h>

namespace nodejscplusopenmp
{

using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::NewStringType;
using v8::Object;
using v8::String;
using v8::Number;
using v8::Value;
using v8::Context;
using namespace std;

void SingleThreaded(const FunctionCallbackInfo<Value> &args)
{
    Isolate *isolate = args.GetIsolate();
    Local<Context> context = Context::New(isolate);

    // Get method parameters
    unsigned long long int number = args[0]->IsUndefined() ? 0 : args[0]->ToBigInt(context).ToLocalChecked()->Uint64Value();

    const auto recurseDivide = [](unsigned long long int num) -> unsigned long long int {
        auto rF = [](unsigned long long int num, unsigned long long int count, auto& ref) mutable -> unsigned long long int {
            if ((count != 1) && (num != count) && (num % count == 0)) return count;
            else if (num == count) return 0;
            return ref(num, ++count, ref);
        };
        return rF(num, 1, rF);
    };

    unsigned long long int f = recurseDivide(number);

    args.GetReturnValue().Set((uint32_t)f);
}

void OpenMp(const FunctionCallbackInfo<Value> &args)
{
    Isolate *isolate = args.GetIsolate();
    Local<Context> context = Context::New(isolate);

    // Get method parameters
    int number = args[0]->IsUndefined() ? 1 : args[0]->ToNumber(context).ToLocalChecked()->NumberValue(context).ToChecked();

    

    args.GetReturnValue().Set(number);
}

void Cuda(const FunctionCallbackInfo<Value> &args)
{
    Isolate *isolate = args.GetIsolate();
    Local<Context> context = Context::New(isolate);

    // Get method parameters
    int number = args[0]->IsUndefined() ? 1 : args[0]->ToNumber(context).ToLocalChecked()->NumberValue(context).ToChecked();

    

    args.GetReturnValue().Set(number);
}

// Set the name of the method that will be exported
// eg. module.exports.{method name}
void Initialize(Local<Object> exports)
{
    NODE_SET_METHOD(exports, "Single", SingleThreaded);
    NODE_SET_METHOD(exports, "OpenMp", OpenMp);
    NODE_SET_METHOD(exports, "Cuda", OpenMp);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, Initialize)

} // namespace nodejscplusopenmp