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
using v8::Array;
using v8::Context;
using namespace std;

void SingleThreaded(const FunctionCallbackInfo<Value> &args)
{
    Isolate *isolate = args.GetIsolate();
    Local<Context> context = Context::New(isolate);

	// Get method parameters
	string strNumValue = *String::Utf8Value(isolate, args[0]->ToString(context).ToLocalChecked());
    unsigned long long int number = strtoull(strNumValue.c_str(), nullptr, 0);

	// Brute force factorize
	for (unsigned long long int count = 2; count < number; count++) {
		if (number % count == 0) {
			char prime1[20], prime2[20];
			ultoa(count, prime1, 10);
			ultoa(number / count, prime2, 10);

			Local<Array> returnArr = Array::New(isolate, 3);
			returnArr->Set(context, 0, Local<String>::New(isolate, String::NewFromUtf8(isolate, strNumValue.c_str(), NewStringType::kNormal).ToLocalChecked()));
			returnArr->Set(context, 1, Local<String>::New(isolate, String::NewFromUtf8(isolate, prime1, NewStringType::kNormal).ToLocalChecked()));
			returnArr->Set(context, 2, Local<String>::New(isolate, String::NewFromUtf8(isolate, prime2, NewStringType::kNormal).ToLocalChecked()));

			args.GetReturnValue().Set(returnArr);
			break;
		}
	}
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