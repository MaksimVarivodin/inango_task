//
// Created by maksymvarivodin on 8/16/24.
//

#include "../dns_server_lib.hpp"

namespace dns_lib
{
    dns_server::dns_server()
        : server_name_(),
          up_server_ip_(),
          up_server_port_(),
          domains_(),
          socket_()
    {
    }

    dns_server::dns_server(
        const string& server_name,
        size_t buffer_size,
        const string& up_server_ip,
        unsigned int up_server_port,
        const vector<dns_domain>& domains,
        dns_socket&& socket)
        : server_name_(server_name),
          buffer_size_(buffer_size),
          up_server_ip_(),
          up_server_port_(up_server_port),
          domains_(domains),
          socket_(std::move(socket))
    {
        strcpy(up_server_ip_, up_server_ip.c_str());
    }

    dns_server::dns_server(const dns_server& other)
        : server_name_(other.server_name_),
          buffer_size_(other.buffer_size_),
          up_server_ip_(),
          up_server_port_(other.up_server_port_),
          domains_(other.domains_),
          socket_(other.socket_)
    {
        strcpy(up_server_ip_, other.up_server_ip_);
    }

    string dns_server::receive() const
    {
        // Creating temporary meta-data buffers
        sockaddr_in client;
        char message_buffer[buffer_size_],
             client_ip[INET_ADDRSTRLEN];
        socklen_t client_len = sizeof(client);

        // Receive message from client
        int bytes_received(recvfrom(
            socket_.descriptor(),
            message_buffer,
            buffer_size_,
            0,
            (sockaddr*)&client,
            &client_len));

        // Checking if receiving was successful
#ifndef NDEBUG
        if (bytes_received <= 0)
            cout << "Error receiving from client." << endl;
#endif

        // Converting client IP to string
        inet_ntop(socket_.domain(), &client.sin_addr, client_ip, INET_ADDRSTRLEN);

#ifndef NDEBUG
        cout << "IP:" << client_ip << " ." << endl;
#endif
        return string(message_buffer, bytes_received);
    }


    dns_server dns_server::load_from_json(istream& ifs)
    {
        dns_server_json json_server(dns_server_json::load_from_json(ifs));
        return (dns_server)json_server;
    }
}
