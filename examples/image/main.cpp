#include <iostream>
#include <cstdlib>
#include "../../src/NTL.hpp"
#include "../../src/NTL.cpp"

int main()
{
    srand(time(nullptr));

    ntl::ImageRGBA image;

    if (!image.load_from_file("105460306_p0.png"))
    {
        std::cout << "Unable to load image" << std::endl;
        return 1;
    }

    image.save_as_png("output.png", true);

    ntl::ImageRGBA image2(500, 500);

    for (ntl::UInt32 y = 0; y < 500; y++)
    {
        for (ntl::UInt32 x = 0; x < 500; x++)
        {
            image2[y * image2.get_width() + x] =
                ntl::PixelRGBA(std::array<ntl::UInt8, 4>{
                    ntl::UInt8(rand() % 256),
                    ntl::UInt8(rand() % 256),
                    ntl::UInt8(rand() % 256),
                    ntl::UInt8(rand() % 256),
                });
        }
    }

    image2.save_as_png("output2.png");

    return 0;
}