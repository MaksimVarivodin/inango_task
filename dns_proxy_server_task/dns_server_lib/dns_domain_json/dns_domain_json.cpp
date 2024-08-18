//
// Created by maksymvarivodin on 8/15/24.
//

#include "../dns_server_lib.hpp"

namespace dns_lib
{
    dns_domain_json::dns_domain_json(const json& json_data)
        : parsed_data_(json_data)
    {
    }

    dns_domain_json::operator dns_domain() const
    {
#ifndef NDEBUG
        cout << "=======\t\tParsed domain -> "<< parsed_data_["name"].get<std::string>()<< "\t=======\n";
#endif
        return {
            parsed_data_["name"].get<std::string>(),
            parsed_data_["response"].get<std::string>(),
            parsed_data_["ip"].get<std::string>(),
            parsed_data_["port"].get<unsigned int>()
        };
    }
} // dns_lib
