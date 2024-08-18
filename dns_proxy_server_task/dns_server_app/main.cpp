//
// Created by maksymvarivodin on 8/15/24.
//



#include "dns_server_lib.hpp"


int main()
{
    using namespace dns_lib;
    using namespace std;

    ifstream config_file("config.json", ios::in);

    if (config_file.is_open())
    {
        cout << "file opened\n";
        dns_server server(dns_server::load_from_json(config_file));

        while (true)
        {
            cout << server.receive() << endl;
        }
        config_file.close();

    }else cout << "file not opened\n";


    return 0;
}
