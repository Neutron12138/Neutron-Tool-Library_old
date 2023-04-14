#ifndef __NEUTRONTL_REFLECTION20_ARGUMENTSCOUNTER_HPP__
#define __NEUTRONTL_REFLECTION20_ARGUMENTSCOUNTER_HPP__

namespace ntl
{
    namespace cpp20
    {
#if not NEUTRONTL_CPP20

        template <typename TargetType>
        TargetType any_type()
        {
            return TargetType();
        }

        namespace details
        {

        } // namespace details

#endif

    } // namespace cpp20

} // namespace ntl

#endif
