#ifndef __NEUTRONTL_STRING_STRINGUTILS_CPP__
#define __NEUTRONTL_STRING_STRINGUTILS_CPP__

#include "StringUtils.hpp"

namespace ntl
{
    template <typename m_StringType, typename m_StringStreamType, typename m_InputStreamType, typename m_InputFileStreamType>
    const typename BasicStringUtils<m_StringType, m_StringStreamType, m_InputStreamType, m_InputFileStreamType>::StringType &BasicStringUtils<m_StringType, m_StringStreamType, m_InputStreamType, m_InputFileStreamType>::load_string_from_stream(typename BasicStringUtils<m_StringType, m_StringStreamType, m_InputStreamType, m_InputFileStreamType>::InputStreamType &is)
    {
        try
        {
            typename BasicStringUtils<m_StringType, m_StringStreamType, m_InputStreamType, m_InputFileStreamType>::StringStreamType sstr;
            typename BasicStringUtils<m_StringType, m_StringStreamType, m_InputStreamType, m_InputFileStreamType>::StringType temp;
            while (std::getline(is, temp))
            {
                sstr << temp << std::endl;
            }
            load_string_from_stream_status = Status::Success;
            load_string_from_stream_result = sstr.str();
        }
        catch (const std::exception &e)
        {
            load_string_from_stream_status = Status::Failure;
            load_string_from_stream_result = e.what();
        }

        return load_string_from_stream_result;
    }

    template <typename m_StringType, typename m_StringStreamType, typename m_InputStreamType, typename m_InputFileStreamType>
    const typename BasicStringUtils<m_StringType, m_StringStreamType, m_InputStreamType, m_InputFileStreamType>::StringType &BasicStringUtils<m_StringType, m_StringStreamType, m_InputStreamType, m_InputFileStreamType>::load_string_from_file(const std::string &filename)
    {
        typename BasicStringUtils<m_StringType, m_StringStreamType, m_InputStreamType, m_InputFileStreamType>::InputFileStreamType fin;
        try
        {
            fin.open(filename);
            if (fin.fail())
            {
                fin.close();
                load_string_from_file_status = Status::Failure;
                load_string_from_file_result = to_string("Could not open file:\"", filename, "\"");
            }

            load_string_from_file_status = Status::Success;
            load_string_from_file_result = load_string_from_stream(fin);

            if (load_string_from_stream_status != Status::Success)
            {
                load_string_from_file_status = Status::Failure;
                load_string_from_file_result = load_string_from_stream_result;
            }

            fin.close();
        }
        catch (const std::exception &e)
        {
            fin.close();
            load_string_from_file_status = Status::Failure;
            load_string_from_file_result = e.what();
        }

        return load_string_from_file_result;
    }

    template <typename m_StringType, typename m_StringStreamType, typename m_InputStreamType, typename m_InputFileStreamType>
    typename BasicStringUtils<m_StringType, m_StringStreamType, m_InputStreamType, m_InputFileStreamType>::StringType BasicStringUtils<m_StringType, m_StringStreamType, m_InputStreamType, m_InputFileStreamType>::to_string()
    {
        return typename BasicStringUtils<m_StringType, m_StringStreamType, m_InputStreamType, m_InputFileStreamType>::StringType();
    }

    template <typename m_StringType, typename m_StringStreamType, typename m_InputStreamType, typename m_InputFileStreamType>
    template <typename ArgT>
    typename BasicStringUtils<m_StringType, m_StringStreamType, m_InputStreamType, m_InputFileStreamType>::StringType BasicStringUtils<m_StringType, m_StringStreamType, m_InputStreamType, m_InputFileStreamType>::to_string(const ArgT &arg)
    {
        typename BasicStringUtils<m_StringType, m_StringStreamType, m_InputStreamType, m_InputFileStreamType>::StringStreamType sstr;
        sstr << arg;
        return sstr.str();
    }

    template <typename m_StringType, typename m_StringStreamType, typename m_InputStreamType, typename m_InputFileStreamType>
    template <typename ArgT, typename... ArgsT>
    typename BasicStringUtils<m_StringType, m_StringStreamType, m_InputStreamType, m_InputFileStreamType>::StringType BasicStringUtils<m_StringType, m_StringStreamType, m_InputStreamType, m_InputFileStreamType>::to_string(const ArgT &arg, const ArgsT &...args)
    {
        return to_string(arg) + to_string(args...);
    }

} // namespace ntl

#endif