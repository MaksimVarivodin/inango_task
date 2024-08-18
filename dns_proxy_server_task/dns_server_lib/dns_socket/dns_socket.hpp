//
// Created by maksymvarivodin on 8/18/24.
//

#ifndef DNS_SOCKET_HPP
#define DNS_SOCKET_HPP

#include "../includes.hpp"

namespace dns_lib
{
    class dns_socket
    {
        int descriptor_ = 0;
        int port_ = 0;
        char ip_[INET_ADDRSTRLEN] = {};
        int domain_ = 0;
        int type_ = 0;
        int protocol_ = 0;

    public:
        dns_socket(
            int socket,
            int port,
            const string& ip_address,
            int domain,
            int type,
            int protocol
        );
        dns_socket(dns_socket&& other) noexcept;
        dns_socket(const dns_socket& other) = default;
        dns_socket();
        ~dns_socket();

    public:
        [[nodiscard]] int descriptor() const;
        [[nodiscard]] int port() const;
        [[nodiscard]] string ip() const;
        [[nodiscard]] int domain() const;
        [[nodiscard]] int type() const;
        [[nodiscard]] int protocol() const;


        static dns_socket create_socket(
            int port,
            const string& ip_address,
            int domain,
            int type,
            int protocol);
    };
} // dns_lib

#endif //DNS_SOCKET_HPP
