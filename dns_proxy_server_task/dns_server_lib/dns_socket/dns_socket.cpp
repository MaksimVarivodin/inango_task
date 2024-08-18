//
// Created by maksymvarivodin on 8/18/24.
//

#include "../dns_server_lib.hpp"

namespace dns_lib
{
    dns_socket::dns_socket(int socket, int port, const string& ip_address, int domain, int type, int protocol)
        : descriptor_(socket),
          port_(port),
          ip_(),
          domain_(domain),
          type_(type),
          protocol_(protocol)
    {
        strcpy(ip_, ip_address.c_str());
    }

    dns_socket::dns_socket(dns_socket&& other) noexcept
        : descriptor_(other.descriptor_),
          port_(other.port_),
          ip_(),
          domain_(other.domain_),
          type_(other.type_),
          protocol_(other.protocol_)
    {
        strcpy(ip_, other.ip_);
        other.ip_[0] = '\0';
        other.descriptor_ = -1;
        other.port_ = -1;
        other.domain_ = -1;
        other.type_ = -1;
        other.protocol_ = -1;
#ifndef NDEBUG
        cout << "=======\t\tMoved socket\t=======\n";
#endif


    }

    dns_socket::dns_socket()
        : descriptor_(-1)
    {
    }

    dns_socket::~dns_socket()
    {
        if (descriptor_ >= 0)
        {
#ifndef NDEBUG
            cout << "=======\t\tDestroyed socket\t=======\n";
#endif
            close(descriptor_);
            descriptor_ = -1;
        }
    }

    int dns_socket::descriptor() const
    {
        return descriptor_;
    }

    int dns_socket::port() const
    {
        return port_;
    }

    string dns_socket::ip() const
    {
        return {ip_};
    }

    int dns_socket::domain() const
    {
        return domain_;
    }

    int dns_socket::type() const
    {
        return type_;
    }

    int dns_socket::protocol() const
    {
        return protocol_;
    }

    dns_socket dns_socket::create_socket(int port, const string& ip_address, int domain, int type, int protocol)
    {
        int socket_descriptor(socket(domain, type, protocol));

        if (socket_descriptor < 0)
            throw std::runtime_error("Failed to create socket");
#ifndef NDEBUG
        cout << "=======\t\tCreated socket descriptor: " << socket_descriptor << "\t=======\n";
        cout << "IP address: " << ip_address << ", port: " << port << "\n";
        cout << "Domain: " << domain << ", type: " << type << ", protocol: " << protocol << "\n";
#endif
        const char* ip_addr = ip_address.length()> 0? ip_address.c_str() : "0.0.0.0";
        sockaddr_in server_address{
            server_address.sin_family = domain,
            server_address.sin_port = htons(port)
        };
        if(inet_pton(AF_INET, ip_addr, &server_address.sin_addr) <= 0)
        {
            cout << "Invalid IP address" <<ip_address << "\n";
            return dns_socket();
        }

        if (bind(socket_descriptor, (sockaddr*)&server_address, sizeof(server_address)) < 0)
            throw std::runtime_error("Failed to bind socket");
#ifndef NDEBUG
        cout << "=======\t\tBound socket to IP and Port\t=======\n";
#endif
        return {
            socket_descriptor,
            port,
            ip_address,
            domain,
            type,
            protocol
        };
    }
} // dns_lib
