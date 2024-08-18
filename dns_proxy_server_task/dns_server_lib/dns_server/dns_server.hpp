//
// Created by maksymvarivodin on 8/15/24.
//

#ifndef DNS_SERVER_HPP
#define DNS_SERVER_HPP

#include "../includes.hpp"
#include "../dns_domain/dns_domain.hpp"

namespace dns_lib
{
    class dns_server
    {
        string server_name_;
        char server_ip_[16] = {};
        unsigned int server_port_ = 0;
        char up_server_ip_[16] = {};
        unsigned int up_server_port_ = 0;
        vector<dns_domain> domains_;

    public:
        dns_server();

        dns_server(
            const string& server_name,
            const string& server_ip,
            unsigned int server_port,
            const string& up_server_ip,
            unsigned int up_server_port,
            const vector<dns_domain>& domains
        );
        dns_server(const dns_server& other) = default;

    public:
        static dns_server load_from_json(istream& ifs);
    };
} // dns_lib

#endif //DNS_SERVER_HPP
