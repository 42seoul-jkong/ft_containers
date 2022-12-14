/* Any copyright is dedicated to the Public Domain.
 * https://creativecommons.org/publicdomain/zero/1.0/ */

#pragma once

#include "integral_constant.hpp"

namespace ft
{
    // Default
    template <typename T>
    struct is_integral : ft::false_type
    {
    };

    // Remove cv-qualified variants
    template <typename T>
    struct is_integral<const T> : is_integral<T>
    {
    };
    template <typename T>
    struct is_integral<volatile const T> : is_integral<T>
    {
    };
    template <typename T>
    struct is_integral<volatile T> : is_integral<T>
    {
    };

    // Unsigned
    template <>
    struct is_integral<unsigned char> : ft::true_type
    {
    };
    template <>
    struct is_integral<unsigned short int> : ft::true_type
    {
    };
    template <>
    struct is_integral<unsigned int> : ft::true_type
    {
    };
    template <>
    struct is_integral<unsigned long int> : ft::true_type
    {
    };

    // Signed
    template <>
    struct is_integral<signed char> : ft::true_type
    {
    };
    template <>
    struct is_integral<short int> : ft::true_type
    {
    };
    template <>
    struct is_integral<int> : ft::true_type
    {
    };
    template <>
    struct is_integral<long int> : ft::true_type
    {
    };

    // Intrinsic
    template <>
    struct is_integral<bool> : ft::true_type
    {
    };
    template <>
    struct is_integral<char> : ft::true_type
    {
    };
    template <>
    struct is_integral<wchar_t> : ft::true_type
    {
    };
}
