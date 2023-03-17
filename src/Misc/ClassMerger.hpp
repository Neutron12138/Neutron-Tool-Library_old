#ifndef __NEUTRONTL_MISC_CLASSMERGER_HPP__
#define __NEUTRONTL_MISC_CLASSMERGER_HPP__

#include "../Base/BasicObject.hpp"

namespace ntl
{
    /// @brief 类合并器
    /// @tparam m_ClassType 类类型
    template <typename m_ClassType>
    class ClassMerger : public BasicObject,
                        public m_ClassType
    {
    public:
        /// @brief 类类型
        using ClassType = m_ClassType;

        using SelfType = ClassMerger<ClassType>;
        using ParentType = ClassType;

    public:
        ClassMerger() = default;
        template <typename... ArgsType>
        ClassMerger(ArgsType &&...args);
        ClassMerger(const ClassType &from);
        ClassMerger(const SelfType &from) = default;
        ~ClassMerger() = default;

    public:
        SelfType &operator=(const SelfType &from) = default;
        operator ClassType();
        operator ClassType() const;

    public:
        /// @brief 作为m_ClassType
        /// @return m_ClassType类型的本对象
        ClassType &as();

        /// @brief 作为m_ClassType
        /// @return m_ClassType类型的本对象
        const ClassType &as() const;
    };

} // namespace ntl

#endif