//
// Created by maksymvarivodin on 8/18/24.
//

#ifndef DNS_SOCKET_JSON_HPP
#define DNS_SOCKET_JSON_HPP

#include "../includes.hpp"

namespace dns_lib
{
    class dns_socket_json
    {
        json parsed_data_;

    public:
        dns_socket_json(const json& data);
        explicit operator dns_socket();
    };
} // dns_lib

#endif //DNS_SOCKET_JSON_HPP
