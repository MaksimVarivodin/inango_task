//
// Created by maksymvarivodin on 8/15/24.
//
#include "dns_server_lib.hpp"

int main(int argc, char* argv[])
{
    using namespace std;
    if (argc >= 2)
    {
        sockaddr_in server;
        server.sin_family = AF_INET;
        server.sin_port = htons(54000);
        inet_pton(AF_INET, "127.0.0.1", &server.sin_addr);
        int descriptor(socket(AF_INET, SOCK_DGRAM, 0));
        if (descriptor == -1)
            cout << "Error creating socket" << endl;
        else cout << "Socket created successfully" << endl;
        string message(argv[1]);

        int send_ok(sendto(descriptor, message.c_str(), message.length() + 1, 0, (sockaddr*)&server, sizeof(server)));

        if (send_ok == -1)
            cout << "Error sending message" << endl;
        else cout << "Sent successfully" << endl;
        close(descriptor);
    }

    return 0;
}
