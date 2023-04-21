#include <iostream>
#include <cstdlib>
#include "../../src/NTL.hpp"
#include "../../src/NTL.cpp"

int main()
{
    srand(time(nullptr));

    ntl::Bitmap<ntl::Pixel> image;

    if (!image.load_from_file("105460306_p0.png"))
    {
        std::cout << "Unable to load image" << std::endl;
        return 1;
    }

    ntl::BitmapEditor::flip_x(image);
    ntl::Bitmap<ntl::Pixel> result = ntl::BitmapEditor::stretch(image, 2.0f, 2.0f);

    result.save_as_png("output.png", false);

    ntl::Bitmap<ntl::Pixel> image2(500, 500);

    for (ntl::UInt32 y = 0; y < 500; y++)
    {
        for (ntl::UInt32 x = 0; x < 500; x++)
        {
            image2[y][x] =
                ntl::Pixel(std::array<ntl::UInt8, 4>{
                    ntl::UInt8(rand() % 256),
                    ntl::UInt8(rand() % 256),
                    ntl::UInt8(rand() % 256),
                    255,
                });
        }
    }

    for (int x = -123; x < 567; x++)
        image2.get_row(250).get_pixel(x, true) = ntl::Colors::Black;
    for (int y = -123; y < 567; y++)
        image2.get_column(250).get_pixel(y, true) = ntl::Colors::Black;

    image2.save_as_png("output2.png");

    return 0;
}