///
/// @file
/// @copyright Copyright (C) 2021. MIT License.
///
/*
 * Considering a black and white image, implement the following:
 * 1. Implement the create function.
 * 2. In the main function, create an instance of an image, then...
 *  2.1 Initialize the image with the sum of indexes pixel indexes =>   pixel = i+j;
 * 3. Implement the threshold function and use it in the main function.
 * 4. How would look like this threshold function in Matlab?
 * 5. Start the implementation of multi channel image support (colored image). Add the number of channels as parameter
 * template.
 *  5.1. Update the create function accordingly.
 *  5.2. In this case, is it possible to limit the number of channels that can be used? (in compiling time)
 * 6...
 * 'im' contains a matrix representing an image. What do these matlab code stripes do?
 *  im(1:10,:) = 0;
 *  im(end-10:end,:) = 0;
 *  t1 = im(:,1:10)
 */

#ifndef PROBLEM_STATEMENT_IMAGE_H
#define PROBLEM_STATEMENT_IMAGE_H

#include <cstdint>
#include <limits>
#include <type_traits>

namespace problem_statement
{

template <typename T, std::size_t kMaxChannels, typename = std::enable_if_t<kMaxChannels <= 3UL> >
class Image
{
  public:
    using pixel_t = T;

    Image() : size_{0UL}, width_{0UL}, height_{0UL}, channels_{kMaxChannels}, data_{nullptr} {}
    ~Image() { Destroy(); }

    void Create(const std::size_t width, const std::size_t height)
    {
        if (data_ != nullptr)
        {
            Destroy();
        }
        width_ = width;
        height_ = height;
        size_ = width_ * height_ * channels_;
        data_ = new pixel_t[size_];
        if (data_ == nullptr)
        {
            size_ = 0UL;
            width_ = 0UL;
            height_ = 0UL;
            return;
        }
        Init();
    }

    constexpr std::size_t GetWidth() const { return width_; };
    constexpr std::size_t GetHeight() const { return height_; };
    constexpr std::size_t GetSize() const { return size_; }
    constexpr std::size_t GetChannels() const { return channels_; }

    constexpr pixel_t* GetData() const { return data_; }
    pixel_t* GetData() { return data_; }

  private:
    void Destroy()
    {
        if (data_)
        {
            delete[] data_;
        }
    }

    void Init()
    {
        for (auto w = 0UL; w < GetWidth(); ++w)
        {
            for (auto h = 0UL; h < GetHeight(); ++h)
            {
                data_[w * GetWidth() + h] = w + h;
            }
        }
    }

    std::size_t size_;
    std::size_t width_;
    std::size_t height_;
    const std::size_t channels_;

    pixel_t* data_;
};

// If pixel smaller than threshold, output receives zero, otherwise one
template <typename T, std::size_t kMaxChannels, typename = std::enable_if_t<kMaxChannels <= 3UL> >
void Threshold(const Image<T, kMaxChannels>& input_image, Image<T, kMaxChannels>& output_image, const T threshold)
{
    if ((input_image.GetWidth() == output_image.GetWidth()) && (input_image.GetHeight() == output_image.GetHeight()) &&
        (input_image.GetChannels() == output_image.GetChannels()) &&
        (input_image.GetSize() == output_image.GetSize()) && (input_image.GetData() != nullptr) &&
        (output_image.GetData() != nullptr))
    {
        const auto input_image_data = input_image.GetData();
        auto output_image_data = output_image.GetData();
        for (auto i = 0UL; i < input_image.GetSize(); ++i)
        {
            if (input_image_data[i] > threshold)
            {
                output_image_data[i] = std::numeric_limits<T>::max();
            }
            else
            {
                output_image_data[i] = std::numeric_limits<T>::min();
            }
        }
    }
}
}  // namespace problem_statement

#endif  /// PROBLEM_STATEMENT_IMAGE_H
