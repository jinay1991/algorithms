///
/// @file
/// @copyright Copyright (C) 2021. MIT License.
///
#include "problem_statement/image.h"

#include <gtest/gtest.h>

namespace problem_statement
{
namespace
{
constexpr std::size_t kMaxChannels = 3UL;
constexpr std::size_t kMaxWidth = 10UL;
constexpr std::size_t kMaxHeight = 10UL;

TEST(Image, Create_GivenTypicalDimensions_ExpectImageCreated)
{
    // Given
    Image<std::uint8_t, kMaxChannels> image;

    // When
    image.Create(kMaxWidth, kMaxHeight);

    // Then
    EXPECT_EQ(image.GetWidth(), kMaxWidth);
    EXPECT_EQ(image.GetHeight(), kMaxHeight);
    EXPECT_EQ(image.GetChannels(), kMaxChannels);
    EXPECT_EQ(image.GetSize(), kMaxWidth * kMaxHeight * kMaxChannels);

    const auto data = image.GetData();
    for (auto w = 0UL; w < image.GetWidth(); ++w)
    {
        for (auto h = 0UL; h < image.GetHeight(); ++h)
        {
            EXPECT_EQ(data[w * image.GetWidth() + h], w + h);
        }
    }
}

TEST(Image, Create_GivenTypicalDimensions_ExpectImageReCreated)
{
    // Given
    Image<std::uint8_t, kMaxChannels> image;

    // When
    constexpr std::size_t kTestHeight = 15UL;
    constexpr std::size_t kTestWidth = 15UL;
    image.Create(kTestWidth, kTestHeight);
    image.Create(kMaxWidth, kMaxHeight);

    // Then
    EXPECT_EQ(image.GetWidth(), kMaxWidth);
    EXPECT_EQ(image.GetHeight(), kMaxHeight);
    EXPECT_EQ(image.GetChannels(), kMaxChannels);
    EXPECT_EQ(image.GetSize(), kMaxWidth * kMaxHeight * kMaxChannels);

    const auto data = image.GetData();
    for (auto w = 0UL; w < image.GetWidth(); ++w)
    {
        for (auto h = 0UL; h < image.GetHeight(); ++h)
        {
            EXPECT_EQ(data[w * image.GetWidth() + h], w + h);
        }
    }
}

TEST(Image, Threshold_GivenTypicalImage_ExpectThresholdImage)
{
    // Given
    Image<std::uint8_t, kMaxChannels> input_image;
    input_image.Create(kMaxWidth, kMaxHeight);

    Image<std::uint8_t, kMaxChannels> output_image;
    output_image.Create(kMaxWidth, kMaxHeight);

    // When
    constexpr std::size_t kThreshold = 4UL;
    Threshold<std::uint8_t, kMaxChannels>(input_image, output_image, kThreshold);

    // Then
    EXPECT_EQ(output_image.GetWidth(), input_image.GetWidth());
    EXPECT_EQ(output_image.GetHeight(), input_image.GetHeight());
    EXPECT_EQ(output_image.GetChannels(), input_image.GetChannels());
    EXPECT_EQ(output_image.GetSize(), input_image.GetSize());

    const auto data = output_image.GetData();
    for (auto w = 0UL; w < output_image.GetWidth(); ++w)
    {
        for (auto h = 0UL; h < output_image.GetHeight(); ++h)
        {
            const auto value = data[w * output_image.GetWidth() + h];
            if (value > kThreshold)
            {
                EXPECT_EQ(value, std::numeric_limits<std::uint8_t>::max());
            }
            else
            {
                EXPECT_EQ(value, std::numeric_limits<std::uint8_t>::min());
            }
        }
    }
}
}  // namespace
}  // namespace problem_statement
