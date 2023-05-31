# Octo SDK

## Install 
Download binary archive from [release page](https://github.com/allxon/octo-sdk/releases)

## Usage Example

```cpp
#include <string>
#include "octo/octo.h"

void main()
{
    // Your plugin name
    std::string name = "jeff_plugin";
    // Your plugin app guid (this app_guid is just for demo, please don't use it in your plugin)
    std::string app_guid = "2124820f-08zf-4ff1-a433-6ccb2e782fxd";
    // Your plugin access key (this key is just for demo, please don't use it in your plugin)
    std::string access_key = "1LeeJJLplFXx89PEr6GilzKLzsmFNgaT";
    // Your plugin version
    std::string version = "1.0.0";
    // notifyPluginUpdate json template
    std::string setup_json = "{\"jsonrpc\": \"2.0\", \"method\": \"v2/notifyPluginUpdate\"...}";

    Allxon::Octo octo(name, app_guid, access_key, version, setup_json);
    std::string wss_url = octo.get_websocket_url();

    // use this url to connect to agent core
    // endpoint.connect(wss_url);

    // other plugin api json content
    std::string data_json;

    if (octo.sign(data_json))
    {
        // if sign success, you can send it through websocket
        // e.g.
        // enpoint.send(data_json);
    }

    std::string method;
    if (octo.verify(data_json, method))
    {
        // if verify success, means data_json is safe, you can read it
        // method is the api name
    }
}
```
