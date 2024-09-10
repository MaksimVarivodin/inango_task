//
// Created by maksymvarivodin on 9/10/24.
//

#ifndef DNS_HEADER_HPP
#define DNS_HEADER_HPP

#include "../includes.hpp"

namespace dns_lib
{
    /*
     * https://support.huawei.com/enterprise/en/doc/EDOC1100174721/f917b5d7/dns
     */
    namespace header_flags
    {
        /**
         * @brief Enumeration representing the Query/Response (QR) flag in the DNS header.
         *
         * @details The QR flag indicates whether this message is a query (0) or a response (1).
         *
         * @note The QR flag occupies bit 0 in the DNS header flags field.
         */
        enum qr: uint8_t
        {
            QUERY = 0, //!< Query message.
            RESPONSE = 1, //!< Response message.
            QR_START = 0, //!< Start bit position for QR flag.
            QR_LENGTH = 1, //!< Length of the QR flag in bits.
        };

        /**
         * @brief Enumeration representing the Operation Code (OPCODE) in the DNS header.
         *
         * @details The OPCODE specifies the kind of query in the message.
         *
         * @note The OPCODE occupies bits 1-4 in the DNS header flags field.
         */
        enum opcode: uint8_t
        {
            STANDARD = 0, //!< Standard query.
            INVERSE = 1, //!< Inverse query (obsolete).
            STATUS = 2, //!< Server status request.
            NOTIFY = 4, //!< Zone transfer request.
            UPDATE = 5, //!< Dynamic update request.
            OPCODE_START = 1, //!< Start bit position for OPCODE.
            OPCODE_LENGTH = 4, //!< Length of the OPCODE flag in bits.
        };

        /**
         * @brief Enumeration representing the Authoritative Answer (AA) flag in the DNS header.
         *
         * @details The AA flag indicates whether the responding name server is an authority for the domain name in the question section.
         *
         * @note The AA flag occupies bit 5 in the DNS header flags field.
         */
        enum aa: uint8_t
        {
            NOT_AUTHORITY = 0, //!< The responding name server is not an authority for the domain name.
            AUTHORITY = 1, //!< The responding name server is an authority for the domain name.
            AA_START = 5, //!< Start bit position for AA flag.
            AA_LENGTH = 1, //!< Length of the AA flag in bits.
        };

        /**
         * @brief Enumeration representing the Truncated Response (TC) flag in the DNS header.
         *
         * @details The TC flag indicates whether the response was truncated due to the size of the response.
         *
         * @note The TC flag occupies bit 6 in the DNS header flags field.
         */
        enum tr: uint8_t
        {
            NO_TRUNCATION = 0, //!< Response was not truncated.
            TRUNCATION = 1, //!< Response was truncated.
            TC_START = 6, //!< Start bit position for TC flag.
            TC_LENGTH = 1, //!< Length of the TC flag in bits.
        };

        /**
         * @brief Enumeration representing the Recursion Desired (RD) flag in the DNS header.
         *
         * @details The RD flag indicates whether the resolver should pursue a recursive query.
         *
         * @note The RD flag occupies bit 7 in the DNS header flags field.
         */
        enum rd: uint8_t
        {
            NO_RECURSION = 0, //!< Resolver should not pursue a recursive query.
            RECURSION = 1, //!< Resolver should pursue a recursive query.
            RD_START = 7, //!< Start bit position for RD flag.
            RD_LENGTH = 1, //!< Length of the RD flag in bits.
        };

        /**
         * @brief Enumeration representing the Recursion Available (RA) flag in the DNS header.
         *
         * @details The RA flag indicates whether the name server supports recursive queries.
         *
         * @note The RA flag occupies bit 8 in the DNS header flags field.
         */
        enum ra: uint8_t
        {
            RECURSION_AVAILABLE = 0, //!< Name server supports recursive queries.
            RECURSION_NOT_AVAILABLE = 1, //!< Name server does not support recursive queries.
            RA_START = 8, //!< Start bit position for RA flag.
            RA_LENGTH = 1, //!< Length of the RA flag in bits.
        };

        /**
         * @brief Enumeration representing the Reserved (Z) flag in the DNS header.
         *
         * @details The Z flag is reserved for future use and should be set to zero.
         *
         * @note The Z flag occupies bits 9-11 in the DNS header flags field.
         */
        enum z: uint8_t
        {
            ZERO = 0, //!< Reserved flag should be set to zero.
            Z_START = 9, //!< Start bit position for Z flag.
            Z_LENGTH = 3, //!< Length of the Z flag in bits.
        };

        /**
         * @brief Enumeration representing the Response Code (RCODE) in the DNS header.
         *
         * @details The RCODE indicates the status of the response.
         *
         * @note The RCODE occupies bits 12-15 in the DNS header flags field.
         */
        enum rcode: uint8_t
        {
            NO_ERROR = 0, //!< No error occurred.
            FORMAT_ERROR = 1, //!< Format error occurred.
            SERVER_FAILURE = 2, //!< Server failure occurred.
            NAME_ERROR = 3, //!< Name error occurred.
            NOT_IMPLEMENTED = 4, //!< Requested feature is not implemented.
            REFUSED = 5, //!< Request was refused.
            RCODE_START = 12, //!< Start bit position for RCODE.
            RCODE_LENGTH = 4, //!< Length of the RCODE flag in bits.
        };

        uint8_t get_flag(const uint16_t source, const uint8_t flag_start, const uint8_t flag_length);
        uint16_t set_flag(const uint16_t source, const uint8_t value, const uint8_t flag_start,
                          const uint8_t flag_length);
    }

    class dns_header
    {
        /*
          A 16 bit identifier assigned by the program that generates any kind of query.
          This identifier is copied the corresponding reply and can be used by the requester
          to match up replies to outstanding queries.
         */
        const uint16_t id_ = 0;
        uint16_t flags_ = 0;
        uint16_t question_count_ = 0;
        uint16_t answer_count_ = 0;
        uint16_t server_names_count_ = 0;
        uint16_t additional_records_count_ = 0;

    public:
        [[nodiscard]] uint16_t id() const;
        [[nodiscard]] uint16_t question_count() const;
        [[nodiscard]] uint16_t answer_count() const;
        [[nodiscard]] uint16_t server_names_count() const;
        [[nodiscard]] uint16_t additional_records_count() const;

        [[nodiscard]] uint8_t qr_flag() const;
        [[nodiscard]] uint8_t opcode_flag() const;
        [[nodiscard]] uint8_t aa_flag() const;
        [[nodiscard]] uint8_t tc_flag() const;
        [[nodiscard]] uint8_t rd_flag() const;
        [[nodiscard]] uint8_t ra_flag() const;
        [[nodiscard]] uint8_t z_flag() const;
        [[nodiscard]] uint8_t rcode_flag() const;

        void increment_question_count();
        void increment_answer_count();
        void increment_server_names_count();
        void increment_additional_records_count();

    };
} // dns_lib

#endif //DNS_HEADER_HPP
