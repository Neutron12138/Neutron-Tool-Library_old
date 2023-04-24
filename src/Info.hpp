#ifndef __NEUTRONTL_INFO_HPP__
#define __NEUTRONTL_INFO_HPP__

#include "Config.hpp"

#ifndef NEUTRONTL_CONFIG_NO_INFO

// 版本号
#define NEUTRON_INFO_VERSION_MAJOR NTL_CSTRING("1")
#define NEUTRON_INFO_VERSION_MINOR NTL_CSTRING("2")
#define NEUTRON_INFO_VERSION_REVISION NTL_CSTRING("2")

// 版本后缀
#define NEUTRON_INFO_VERSION_SUFFIX NTL_CSTRING("Release")

// 版本全称
#define NEUTRON_INFO_VERSION_FULL NTL_CSTRING("1.2.2 Release")

// 更新说明
#define NEUTRON_INFO_UPDATE_DESCRIPTION NTL_CSTRING("废除了序列化器和反序列化器，而是改用重载函数")

#endif

#endif