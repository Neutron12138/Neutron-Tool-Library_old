#ifndef __NEUTRONTL_HPP__
#define __NEUTRONTL_HPP__

// ---------- 配置信息 ----------
#include "Config.hpp"

// ---------- 有关NTL的信息 ----------
#include "Info.hpp"

// ---------- 包含头文件 ----------
#include "Includes.hpp"

// ---------- 调试工具 ----------
#include "Debug.hpp"

// ---------- 宏定义 ----------
#include "Macros.hpp"

// ---------- 头文件 ----------
// 实现请包含NTL.cpp

#include "Base/BaseDataType.hpp"
#include "Base/StdIOType.hpp"
#include "Base/Type.hpp"
#include "Base/STLType.hpp"
#include "Base/BasicObject.hpp"
#include "Base/Object.hpp"
#include "Base/NonCopyable.hpp"
#include "Base/NamedObject.hpp"

#include "String/StringUtils.hpp"

#include "Exception/Exception.hpp"
#include "Exception/OutOfRangeException.hpp"
#include "Exception/NullPointerException.hpp"
#include "Exception/InvalidArgumentException.hpp"

#include "Maths/MathsContants.hpp"
#include "Maths/Sphere.hpp"

#include "Time/Time.hpp"
#include "Time/Timer.hpp"
#include "Time/CountdownTimer.hpp"

#include "Memory/BasicDeleter.hpp"
#include "Memory/Pointer.hpp"
#include "Memory/SharedPointer.hpp"
#include "Memory/UniquePointer.hpp"
#include "Memory/WeakPointer.hpp"

#include "Resource/ResourceObject.hpp"
#include "Resource/ResourceDeleter.hpp"

#include "Node/BasicNode.hpp"
#include "Node/Node.hpp"
#include "Node/DefaultNode.hpp"
#include "Node/DataNode.hpp"

#include "Log/LogLevel.hpp"
#include "Log/LogItem.hpp"
#include "Log/Log.hpp"

#include "Meta/FundamentalTypeInfo.hpp"
#include "Meta/CompoundTypeInfo.hpp"
#include "Meta/TypeAttributeInfo.hpp"
#include "Meta/AttributeQueryInfo.hpp"
#include "Meta/SupportedOperationsInfo.hpp"
#include "Meta/TypeInfo.hpp"
#include "Meta/TypeUtils.hpp"

#include "Misc/Print.hpp"
#include "Misc/Application.hpp"

// ---------- 静态实例 ----------

#include "Instances.hpp"

#endif