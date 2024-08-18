//
// Created by maksymvarivodin on 8/15/24.
//

#include "../dns_server_lib.hpp"

namespace dns_lib
{
    dns_domain::dns_domain()
        : name_(),
          response_(),
          ip_(),
          port_(0)
    {
    }

    dns_domain::dns_domain(const string& name, const string& response, const string& ip, unsigned int port)
        : name_(name),
          response_(response),
          ip_(),
          port_(port)
    {
        strcpy(ip_, ip.c_str());
    }

    string dns_domain::name() const
    {
        return this->name_;
    }

    string dns_domain::response() const
    {
        return this->response_;
    }

    string dns_domain::ip() const
    {
        return {this->ip_};
    }

    unsigned int dns_domain::port() const
    {
        return this->port_;
    }
} // dns_lib
