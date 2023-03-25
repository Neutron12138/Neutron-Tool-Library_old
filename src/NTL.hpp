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
#include "Base/Copyable.hpp"

#include "String/StringUtils.hpp"

#include "Exception/Exception.hpp"
#include "Exception/OutOfRangeException.hpp"
#include "Exception/NullPointerException.hpp"
#include "Exception/InvalidArgumentException.hpp"
#include "Exception/CaughtException.hpp"
#include "Exception/TypeErrorException.hpp"

#include "Maths/MathsContants.hpp"
#include "Maths/Sphere.hpp"
#include "Maths/Angle.hpp"
#include "Maths/Vector.hpp"
#include "Maths/Matrix.hpp"

#include "Time/Time.hpp"
#include "Time/Timer.hpp"
#include "Time/CountdownTimer.hpp"

#include "Memory/BasicDeleter.hpp"
#include "Memory/Pointer.hpp"
#include "Memory/SharedPointer.hpp"
#include "Memory/UniquePointer.hpp"
#include "Memory/WeakPointer.hpp"
#include "Memory/MemoryTracker.hpp"
#include "Memory/DefaultMemoryTracker.hpp"

#include "Resource/ResourceObject.hpp"
#include "Resource/ResourceDeleter.hpp"

#include "Node/BasicNode.hpp"
#include "Node/Node.hpp"
#include "Node/DefaultNode.hpp"
#include "Node/DataNode.hpp"

#include "Log/LogLevel.hpp"
#include "Log/LogItem.hpp"
#include "Log/BasicLog.hpp"
#include "Log/Log.hpp"

#include "TypeInfo/FundamentalTypeInfo.hpp"
#include "TypeInfo/CompoundTypeInfo.hpp"
#include "TypeInfo/TypeAttributeInfo.hpp"
#include "TypeInfo/AttributeQueryInfo.hpp"
#include "TypeInfo/SupportedOperationsInfo.hpp"
#include "TypeInfo/TypeInfo.hpp"
#include "TypeInfo/TypeUtils.hpp"
#include "TypeInfo/Type.hpp"

#include "Misc/PrintUtils.hpp"
#include "Misc/ContainerOperation.hpp"
#include "Misc/ClassMerger.hpp"

#include "Application/Application.hpp"
#include "Application/ConsoleApplication.hpp"

#include "Image/Color.hpp"
#include "Image/Pixel.hpp"
#include "Image/Bitmap.hpp"
#include "Image/BitmapEditor.hpp"

#include "Serialization/Serialization.hpp"
#include "Serialization/Serializable.hpp"
#include "Serialization/Serializer.hpp"
#include "Serialization/Deserializer.hpp"

#include "Reflection/FieldSign.hpp"
#include "Reflection/MethodSign.hpp"
#include "Reflection/Member.hpp"
#include "Reflection/Method.hpp"
#include "Reflection/NonStaticMethod.hpp"
#include "Reflection/StaticMethod.hpp"
#include "Reflection/Field.hpp"
#include "Reflection/NonStaticField.hpp"
#include "Reflection/StaticField.hpp"
#include "Reflection/Details.hpp"
#include "Reflection/Reflectible.hpp"
#include "Reflection/Reflector.hpp"

#include "Signal/Slot.hpp"
#include "Signal/Signal.hpp"
#include "Signal/Signalable.hpp"

// ---------- 静态实例 ----------

#include "Instances.hpp"

#endif