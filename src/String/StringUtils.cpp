#ifndef __NEUTRONTL_STRING_STRINGUTILS_CPP__
#define __NEUTRONTL_STRING_STRINGUTILS_CPP__

#include "StringUtils.hpp"

namespace ntl
{
    const String &
    StringUtils::load_string_from_stream(
        InputStream &is)
    {
        try
        {
            StringStream sstr;
            String temp;
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
            load_string_from_stream_result = to_stl_string(e.what());
        }

        return load_string_from_stream_result;
    }

    const String &
    StringUtils::load_string_from_file(
        const std::string &filename)
    {
        InputFileStream fin;
        try
        {
            fin.open(filename);
            if (fin.fail())
            {
                fin.close();
                load_string_from_file_status = Status::Failure;
                load_string_from_file_result =
                    to_string(
                        NTL_STRING("Could not open file:\""),
                        filename,
                        NTL_STRING("\""));
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
            load_string_from_file_result = to_stl_string(e.what());
        }

        return load_string_from_file_result;
    }

#ifdef NEUTRON_CONFIG_USE_WCHAR
    std::wstring
    StringUtils::to_stl_wstring(
        const std::string &str)
    {
        std::wstring result;
        for (auto iter = str.cbegin(); iter != str.cend(); iter++)
            result += static_cast<wchar_t>(*iter);
        return result;
    }
#else
    std::string
    StringUtils::to_stl_string(
        const std::string &str)
    {
        return str;
    }
#endif

    String
    StringUtils::to_string()
    {
        return String();
    }

    template <typename ArgT>
    String
    StringUtils::to_string(
        const ArgT &arg)
    {
        StringStream sstr;
        sstr << arg;
        return sstr.str();
    }

    template <typename ArgT, typename... ArgsT>
    String
    StringUtils::to_string(
        const ArgT &arg,
        const ArgsT &...args)
    {
        return to_string(arg) + to_string(args...);
    }

    template <typename IterType>
    String
    StringUtils::joint_string(
        const IterType &begin,
        const IterType &end,
        const String &delimiter)
    {
        ntl::StringStream sstr;
        for (auto iter = begin; iter != end; iter++)
        {
            sstr << *iter << delimiter;
        }
        return sstr.str();
    }

    bool
    StringUtils::match(
        const String &data,
        const Regex &regex,
        std::regex_constants::match_flag_type flag)
    {
        return std::regex_match(data, regex, flag);
    }

    bool
    StringUtils::search(
        const String &data,
        Match &match,
        const Regex &regex,
        std::regex_constants::match_flag_type flag)
    {
        return std::regex_search(data, match, regex, flag);
    }

    String
    StringUtils::replace(
        const String &data,
        const Regex &regex,
        const String &fmt,
        std::regex_constants::match_flag_type flag)
    {
        return std::regex_replace(data, regex, fmt, flag);
    }

    String
    StringUtils::replace_all(
        const String &data,
        const Regex &regex,
        const String &fmt,
        std::regex_constants::match_flag_type flag)
    {
        String str = data;
        for (; match(str, regex, flag); str = replace(str, regex, fmt, flag))
            ;
        return str;
    }

    std::vector<String>
    StringUtils::split(
        const String &data,
        const String &reg,
        std::regex_constants::match_flag_type flag)
    {
        std::vector<String> result;
        Regex regex(
            to_string(
                NTL_STRING("(.*)"),
                reg,
                NTL_STRING("(.*)")));
        String str = data;
        while (match(str, regex, flag))
        {
            Match m;
            search(str, m, regex);
            str = m.str(1);
            result.push_back(m.str(2));
        }
        result.push_back(str);
        return std::vector<String>(result.crbegin(), result.crend());
    }

    std::vector<String>
    StringUtils::split_by_line(
        const String &data)
    {
        std::vector<String> result;
        StringStream sstr(data);
        String temp;
        while (std::getline(sstr, temp))
        {
            result.push_back(temp);
        }
        return result;
    }

#ifdef NEUTRON_CONFIG_USE_WCHAR
    int StringUtils::to_int(const String &str)
    {
        return std::wcstoi(str);
    }
    long StringUtils::to_long(const String &str) { return std::wcstol(str); }
    long long StringUtils::to_llong(const String &str) { return std::wcstoll(str); }
    unsigned int StringUtils::to_uint(const String &str) { return static_cast<unsigned int>(std::wcstoi(str)); }
    unsigned long StringUtils::to_ulong(const String &str) { return std::wcstoul(str); }
    unsigned long long StringUtils::to_ullong(const String &str) { return std::wcstoull(str); }
    float StringUtils::to_float(const String &str) { return std::wcstof(str); }
    double StringUtils::to_double(const String &str) { return std::wcstod(str); }
#else
    int StringUtils::to_int(const String &str)
    {
        return std::stoi(str);
    }
    long StringUtils::to_long(const String &str) { return std::stol(str); }
    long long StringUtils::to_llong(const String &str) { return std::stoll(str); }
    unsigned int StringUtils::to_uint(const String &str) { return static_cast<unsigned int>(std::stoi(str)); }
    unsigned long StringUtils::to_ulong(const String &str) { return std::stoul(str); }
    unsigned long long StringUtils::to_ullong(const String &str) { return std::stoull(str); }
    float StringUtils::to_float(const String &str) { return std::stof(str); }
    double StringUtils::to_double(const String &str) { return std::stod(str); }
#endif

    std::wostream &
    operator<<(
        std::wostream &os,
        const std::string &str)
    {
        os << StringUtils::to_stl_string(str);
        return os;
    }

} // namespace ntl

#endif