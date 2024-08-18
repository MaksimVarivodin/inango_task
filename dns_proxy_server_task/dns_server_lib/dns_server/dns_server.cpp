//
// Created by maksymvarivodin on 8/16/24.
//

#include "../dns_server_lib.hpp"

namespace dns_lib
{
    dns_server::dns_server()
        : server_name_(),
          server_ip_(),
          server_port_(),
          up_server_ip_(),
          up_server_port_(),
          domains_()
    {
    }

    dns_server::dns_server(
        const string& server_name,
        const string& server_ip,
        unsigned int server_port,
        const string& up_server_ip,
        unsigned int up_server_port,
        const vector<dns_domain>& domains)
        : server_name_(server_name),
          server_ip_(),
          server_port_(server_port),
          up_server_ip_(),
          up_server_port_(up_server_port),
          domains_(domains)
    {
        strcpy(server_ip_, server_ip.c_str());
        strcpy(up_server_ip_, up_server_ip.c_str());
    }

    dns_server dns_server::load_from_json(istream& ifs)
    {
        dns_server_json json_server(dns_server_json::load_from_json(ifs));
        return (dns_server)json_server;
    }
}
