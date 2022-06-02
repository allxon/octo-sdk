#ifndef JSON_VALIDATOR_H
#define JSON_VALIDATOR_H
#include <string>
#include <map>
#include <memory>
#include <mutex>

namespace Allxon
{
    class PluginAPI;
    class NPUpdateJson;

    class JsonValidator
    {
    public:
        JsonValidator(const std::string &plugin_name, const std::string &app_guid, const std::string &access_key,
                      const std::string &version, const std::string &np_update_json_template);
        virtual ~JsonValidator();
        JsonValidator(const JsonValidator &) = delete;
        JsonValidator &operator=(const JsonValidator &) = delete;

        bool Sign(std::string &input_json);
        bool Verify(const std::string &input_json, std::string &method);

        NPUpdateJson np_update_json() const; 
        std::string error_message() const;
        std::string app_guid() const;
        std::string access_key() const;

    private:
        void Check(const std::string &input_json);
        void ReplaceMacros(std::string &input_json) const;

        std::string error_message_;
        std::string plugin_name_;
        std::string app_guid_;
        std::string access_key_;
        std::string version_;
        std::unique_ptr<NPUpdateJson> np_update_json_;
        mutable std::mutex mutex_;
    };
}

#endif