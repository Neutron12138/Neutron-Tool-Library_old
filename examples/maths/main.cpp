#include <iostream>
#include "../../src/NTL.hpp"
#include "../../src/NTL.cpp"

template <typename ComponentType, ntl::SizeT dimensions>
void print(const ntl::Vector<ComponentType, dimensions> &vec);

template <typename ComponentType, ntl::SizeT rows, ntl::SizeT columns>
void print(const ntl::Matrix<ComponentType, rows, columns> &mat);

int main()
{
    std::cout << "ntl::MathsConstants::PI:" << ntl::MathsConstants::PI << std::endl;
    std::cout << "ntl::MathsConstants::exact::ePI:" << ntl::MathsConstants::exact::ePI << std::endl;

    ntl::Angle<float> a1(ntl::MathsConstants::PI_HALF, ntl::Angle<float>::AngleUnit::Radian);
    ntl::Angle<float> a2(180.0f, ntl::Angle<float>::AngleUnit::Degree);

    std::cout << "a1.as_radian():" << a1.as_radian() << std::endl
              << "a1.as_degree():" << a1.as_degree() << std::endl
              << "a2.as_radian():" << a2.as_radian() << std::endl
              << "a2.as_degree():" << a2.as_degree() << std::endl;

    std::cout << "a1 + a2:" << (a1 + a2) << std::endl
              << "a1 - a2:" << (a1 - a2) << std::endl
              << "a2 * 2.0f:" << (a2 * 2.0f) << std::endl
              << "a2 / 2.0f:" << (a2 / 2.0f) << std::endl;

    std::cout << "----------" << std::endl;

    ntl::Vec2 vec1 = ntl::make_vector(1.0f, 1.0f);
    ntl::Vec2 vec2 = ntl::make_vector(0.1f, 0.2f);
    ntl::Vec2 vec3 = ntl::make_vector(0.0f, 1.0f);

    std::cout << "vec1.dot(vec2):" << vec1.dot(vec2) << std::endl;

    std::cout << "vec1.length():" << vec1.length() << std::endl;

    std::cout << "vec1.normalized():";
    print(vec1.normalized());

    std::cout << "vec1 + 2.0f * vec2:";
    print(vec1 + 2.0f * vec2);

    std::cout << "-vec1.reflect(vec3):";
    print(-vec1.reflect(vec3));

    std::cout << "----------" << std::endl;

    ntl::Matrix2x3<float> mat1;
    for (size_t i = 0; i < 2; i++)
        for (size_t j = 0; j < 3; j++)
            mat1[i][j] = i * 3 + j;
    print(2.0f * -mat1);

    return 0;
}

template <typename ComponentType, ntl::SizeT dimensions>
void print(const ntl::Vector<ComponentType, dimensions> &vec)
{
    vec.for_each([](ntl::SizeT index, const float &element) -> void
                 { std::cout << element << " "; });
    std::cout << std::endl;
}

template <typename ComponentType, ntl::SizeT rows, ntl::SizeT columns>
void print(const ntl::Matrix<ComponentType, rows, columns> &mat)
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
            std::cout << mat[i][j] << " ";
        std::cout << std::endl;
    }

    std::cout << std::endl;
}
