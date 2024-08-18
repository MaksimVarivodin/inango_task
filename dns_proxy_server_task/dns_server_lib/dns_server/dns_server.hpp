//
// Created by maksymvarivodin on 8/15/24.
//

#ifndef DNS_SERVER_HPP
#define DNS_SERVER_HPP


#include "../includes.hpp"

#include "../dns_domain/dns_domain.hpp"
#include "../dns_socket/dns_socket.hpp"

namespace dns_lib
{
    class dns_server
    {
        string server_name_;
        size_t buffer_size_ = ULLONG_MAX;
        char up_server_ip_[INET_ADDRSTRLEN] = {};
        unsigned int up_server_port_ = 0;
        vector<dns_domain> domains_;
        dns_socket socket_;

    public:
        dns_server();

        dns_server(
            const string& server_name,
            size_t buffer_size,
            const string& up_server_ip,
            unsigned int up_server_port,
            const vector<dns_domain>& domains,
            dns_socket&& socket
        );

        dns_server(const dns_server& other);

        string receive() const;

    public:
        static dns_server load_from_json(istream& ifs);
    };
} // dns_lib

#endif //DNS_SERVER_HPP
