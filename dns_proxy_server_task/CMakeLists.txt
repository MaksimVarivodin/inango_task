cmake_minimum_required(VERSION 3.28)

project(dns_proxy_server_task VERSION 1.0 LANGUAGES C CXX)


add_subdirectory(dns_server_app)
add_subdirectory(dns_client_app)
add_subdirectory(dns_server_lib)
#add_subdirectory(dns_server_tests)