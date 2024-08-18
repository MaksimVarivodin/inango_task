//
// Created by maksymvarivodin on 8/15/24.
//

#ifndef DNS_DOMAIN_JSON_HPP
#define DNS_DOMAIN_JSON_HPP

#include "../dns_domain/dns_domain.hpp"

namespace dns_lib
{
    class dns_domain_json
    {
        json parsed_data_;

    public:
        explicit dns_domain_json(const json& json_data);
        explicit operator dns_domain() const;
    };
} // dns_lib

#endif //DNS_DOMAIN_JSON_HPP
