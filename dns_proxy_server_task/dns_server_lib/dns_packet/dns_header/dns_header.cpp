//
// Created by maksymvarivodin on 9/10/24.
//

#include "dns_header.hpp"

namespace dns_lib
{
    uint8_t header_flags::get_flag(const uint16_t source, const uint8_t flag_start, const uint8_t flag_length)
    {
        uint16_t move(source << 16 - (flag_start + flag_length));
        move >>= 16 - flag_length;
        return static_cast<uint8_t>(move);
    }

    uint16_t header_flags::set_flag(const uint16_t source, const uint8_t value, const uint8_t flag_start, const uint8_t flag_length)
    {
        uint8_t
            move_left_part(flag_start + flag_length),
            move_right_part(16 - flag_start);
        uint16_t
            left_part(source >> move_left_part),
            right_part(source << move_right_part),
            flag_part(value);
        left_part <<= move_left_part;
        right_part >>= move_right_part;
        flag_part <<= flag_start;
        return left_part | flag_part | right_part;
    }
} // dns_lib
