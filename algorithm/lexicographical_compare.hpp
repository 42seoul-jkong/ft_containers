/* Any copyright is dedicated to the Public Domain.
 * https://creativecommons.org/publicdomain/zero/1.0/ */

#pragma once

namespace ft
{
    template <typename TIterFirst, typename TIterSecond>
    inline bool
    lexicographical_compare(
        TIterFirst first1, TIterFirst last1,
        TIterSecond first2, TIterSecond last2)
    {
        for (; (first1 != last1) && (first2 != last2); ++first1, (void)++first2)
        {
            if (*first1 < *first2)
                return true;
            if (*first2 < *first1)
                return false;
        }
        return (first1 == last1) && (first2 != last2);
    }

    template <typename TIterFirst, typename TIterSecond, typename TComp>
    inline bool
    lexicographical_compare(
        TIterFirst first1, TIterFirst last1,
        TIterSecond first2, TIterSecond last2,
        TComp comp)
    {
        for (; (first1 != last1) && (first2 != last2); ++first1, (void)++first2)
        {
            if (comp(*first1, *first2))
                return true;
            if (comp(*first2, *first1))
                return false;
        }
        return (first1 == last1) && (first2 != last2);
    }
}
