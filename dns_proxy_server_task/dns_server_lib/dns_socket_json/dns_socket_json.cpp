//
// Created by maksymvarivodin on 8/18/24.
//

#include "../dns_server_lib.hpp"

namespace dns_lib
{
    dns_socket_json::dns_socket_json(const json& data)
        : parsed_data_(data)
    {
    }

    dns_socket_json::operator dns_socket()
    {
#ifndef NDEBUG
        cout << "=======\t\tParsed server socket meta-info\t=======\n";
#endif
        return dns_socket::create_socket(
            parsed_data_["port"].get<int>(),
            parsed_data_["ip"].get<string>(),
            parsed_data_["domain"].get<int>(),
            parsed_data_["type"].get<int>(),
            parsed_data_["protocol"].get<int>()
        );
    }
} // dns_lib
