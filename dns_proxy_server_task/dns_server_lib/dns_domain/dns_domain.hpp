//
// Created by maksymvarivodin on 8/15/24.
//

#ifndef DNS_DOMAIN_HPP
#define DNS_DOMAIN_HPP

#include "../includes.hpp"

extern "C" {
#include <string.h>
}

namespace dns_lib
{
    class dns_domain
    {
        string name_;
        string response_;
        char ip_[INET_ADDRSTRLEN] = {};
        unsigned int port_ = 0;

    public:
        dns_domain();
        dns_domain(const string & name, const string& response, const string& ip, unsigned int port);
        virtual ~dns_domain() = default;
        [[nodiscard]] string name() const;
        [[nodiscard]] string response() const;
        [[nodiscard]] string ip() const;
        [[nodiscard]] unsigned int port() const;

    };
} // dns_lib

#endif //DNS_DOMAIN_HPP
