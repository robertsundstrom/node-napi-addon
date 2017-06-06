#include "napi.h"

#include <iostream>

using namespace std;

#define NULL nullptr

napi_value SayHello(napi_env env, napi_callback_info info)
{
    napi_status status;
    napi_value result;

    //printf("Hello\n");

    cout << "Hello" << endl;

    //status = napi_get_undefined(env, &result);

    status = napi_create_string_utf8(env,
                                    "Foo",
                                    3,
                                    &result);

    return result;
}

void Init(napi_env env, napi_value exports, napi_value module, void *priv)
{
    napi_status status;

    napi_value fn;
    status = napi_create_function(env, NULL, SayHello, NULL, &fn);
    if (status != napi_ok)
        return;

    status = napi_set_named_property(env, exports, "sayHello", fn);
    if (status != napi_ok)
        return;

    napi_value obj;
    status = napi_create_object(env, &obj);

    status = napi_set_named_property(env, obj, "sayHello", fn);
    if (status != napi_ok)
        return;

    status = napi_set_named_property(env, exports, "Foo", obj);
    if (status != napi_ok)
        return;
}

NAPI_MODULE(addon, Init)