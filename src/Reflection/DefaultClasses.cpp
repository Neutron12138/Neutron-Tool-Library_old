#ifndef __NEUTRONTL_REFLECTION_DEFAULTCLASSES_CPP__
#define __NEUTRONTL_REFLECTION_DEFAULTCLASSES_CPP__

#include "DefaultClasses.hpp"

namespace ntl
{
    namespace DefaultClasses
    {
        void
        register_all(
            Reflector &reflector)
        {
            reflector.register_class(
                NTL_STRING("std::string"),
                get_string_details<
                    char,
                    std::string::traits_type,
                    std::string::allocator_type>());

            reflector.register_class(
                NTL_STRING("std::wstring"),
                get_string_details<
                    wchar_t,
                    std::wstring::traits_type,
                    std::wstring::allocator_type>());

            reflector.register_class(
                NTL_STRING("std::vector<char>"),
                get_vector_details<char, std::allocator<char>>());

            reflector.register_class(
                NTL_STRING("std::vector<short>"),
                get_vector_details<short, std::allocator<short>>());

            reflector.register_class(
                NTL_STRING("std::vector<int>"),
                get_vector_details<int, std::allocator<int>>());

            reflector.register_class(
                NTL_STRING("std::vector<long>"),
                get_vector_details<long, std::allocator<long>>());

            reflector.register_class(
                NTL_STRING("std::vector<long long>"),
                get_vector_details<long long, std::allocator<long long>>());

            reflector.register_class(
                NTL_STRING("std::vector<float>"),
                get_vector_details<float, std::allocator<float>>());

            reflector.register_class(
                NTL_STRING("std::vector<double>"),
                get_vector_details<double, std::allocator<double>>());
        }

        template <typename CharType, typename TraitsType, typename AllocatorType>
        Details
        get_string_details()
        {
            using StringType = std::string<CharType, TraitsType, AllocatorType>;

            typename Details::NonStaticMethodMap nonstatic_methods;

            nonstatic_methods.insert(
                Details::NonStaticMethodMap::value_type(
                    NTL_STRING("append(const basic_string&"),
                    NonStaticMethod(&StringType::append, 1)));
            nonstatic_methods.insert(
                Details::NonStaticMethodMap::value_type(
                    NTL_STRING("<_CharT>push_back(_CharT)"),
                    NonStaticMethod(&StringType::push_back, 1)));

            return Details(
                sizeof(StringType),
                Details::NonStaticFieldMap(),
                Details::StaticFieldMap(),
                nonstatic_methods,
                Details::StaticMethodMap());
        }

        template <typename ElementType, typename AllocatorType>
        Details
        get_vector_details()
        {
            return Details(sizeof(StringType));
        }

        template <typename ElementType, SizeT size>
        Details
        get_array_details()
        {
            return Details(sizeof(StringType));
        }

    } // namespace DefaultClasses

} // namespace ntl

#endif