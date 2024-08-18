cmake_minimum_required(VERSION 3.28)

project(dns_server_app VERSION 1.0 LANGUAGES CXX)


# Создание исполняемого файла из main.cpp
add_executable(${PROJECT_NAME} main.cpp)

# Добавление include-директорий для корректного поиска заголовочных файлов
target_include_directories(${PROJECT_NAME} PUBLIC
        ../dns_server_lib/dns_domain
        ../dns_server_lib/dns_server
        ../dns_server_lib/dns_server_json
        ../dns_server_lib/dns_domain_json
        ../dns_server_lib
)
# Подключение библиотеки dns_server_lib
target_link_libraries(${PROJECT_NAME}  PRIVATE dns_server_lib)