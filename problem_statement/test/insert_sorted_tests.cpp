///
/// @file
/// @copyright Copyright (C) 2021. MIT License.
///
#include "problem_statement/insert_sorted.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <ostream>

namespace problem_statement
{
namespace
{

struct Payload
{
    std::int32_t priority;
    std::int32_t data;
};

inline constexpr bool operator==(const Payload& lhs, const Payload& rhs) noexcept
{
    return ((lhs.priority == rhs.priority) && (lhs.data == rhs.data));
}

inline constexpr bool operator<(const Payload& lhs, const Payload& rhs) noexcept
{
    return (lhs.priority < rhs.priority);
}

inline constexpr bool operator>(const Payload& lhs, const Payload& rhs) noexcept
{
    return (lhs.priority > rhs.priority);
}

inline std::ostream& operator<<(std::ostream& out, const Payload& data) noexcept
{
    out << "{" << data.priority << ", " << data.data << "}";
    return out;
}

TEST(InsertSorted1, GivenTypicalInputs_ExpectUpdatedBuffer)
{
    // Given
    std::vector<Payload> buffer{};
    Payload data{0, 1};
    ASSERT_EQ(buffer.size(), 0UL);

    // When
    InsertSorted1<Payload>(buffer, data);

    // Then
    EXPECT_EQ(buffer.size(), 1UL);
    EXPECT_EQ(buffer.at(0UL), data);
}

TEST(InsertSorted1, GivenTypicalListOfInputs_ExpectUpdatedBuffer)
{
    // Given
    std::vector<Payload> buffer{};
    const std::vector<Payload> data{Payload{10, 1},
                                    Payload{6, 2},
                                    Payload{5, 3},
                                    Payload{2, 4},
                                    Payload{11, 5},
                                    Payload{3, 6},
                                    Payload{7, 7},
                                    Payload{9, 8},
                                    Payload{8, 9},
                                    Payload{1, 10},
                                    Payload{4, 11}};
    ASSERT_EQ(buffer.size(), 0UL);

    // When
    for (const auto& d : data)
    {
        InsertSorted1<Payload>(buffer, d);
    }

    // Then
    EXPECT_EQ(buffer.size(), data.size());
    EXPECT_THAT(buffer,
                ::testing::ElementsAre(Payload{1, 10},
                                       Payload{2, 4},
                                       Payload{3, 6},
                                       Payload{4, 11},
                                       Payload{5, 3},
                                       Payload{6, 2},
                                       Payload{7, 7},
                                       Payload{8, 9},
                                       Payload{9, 8},
                                       Payload{10, 1},
                                       Payload{11, 5}));
}

TEST(InsertSorted2, GivenTypicalInputs_ExpectUpdatedBuffer)
{
    // Given
    std::vector<Payload> buffer{};
    Payload data{0, 1};
    ASSERT_EQ(buffer.size(), 0UL);

    // When
    InsertSorted2<Payload>(buffer, data);

    // Then
    EXPECT_EQ(buffer.size(), 1UL);
    EXPECT_EQ(buffer.at(0UL), data);
}

TEST(InsertSorted2, GivenTypicalListOfInputs_ExpectUpdatedBuffer)
{
    // Given
    std::vector<Payload> buffer{};
    const std::vector<Payload> data{Payload{10, 1},
                                    Payload{6, 2},
                                    Payload{5, 3},
                                    Payload{2, 4},
                                    Payload{11, 5},
                                    Payload{3, 6},
                                    Payload{7, 7},
                                    Payload{9, 8},
                                    Payload{8, 9},
                                    Payload{1, 10},
                                    Payload{4, 11}};
    ASSERT_EQ(buffer.size(), 0UL);

    // When
    for (const auto& d : data)
    {
        InsertSorted2<Payload>(buffer, d);
    }

    // Then
    EXPECT_EQ(buffer.size(), data.size());
    EXPECT_THAT(buffer,
                ::testing::ElementsAre(Payload{1, 10},
                                       Payload{2, 4},
                                       Payload{3, 6},
                                       Payload{4, 11},
                                       Payload{5, 3},
                                       Payload{6, 2},
                                       Payload{7, 7},
                                       Payload{8, 9},
                                       Payload{9, 8},
                                       Payload{10, 1},
                                       Payload{11, 5}));
}

TEST(InsertSorted3, GivenTypicalInputs_ExpectUpdatedBuffer)
{
    // Given
    std::vector<Payload> buffer{};
    Payload data{0, 1};
    ASSERT_EQ(buffer.size(), 0UL);

    // When
    InsertSorted3<Payload>(buffer, data);

    // Then
    EXPECT_EQ(buffer.size(), 1UL);
    EXPECT_EQ(buffer.at(0UL), data);
}

TEST(InsertSorted3, GivenTypicalListOfInputs_ExpectUpdatedBuffer)
{
    // Given
    std::vector<Payload> buffer{};
    const std::vector<Payload> data{Payload{10, 1},
                                    Payload{6, 2},
                                    Payload{5, 3},
                                    Payload{2, 4},
                                    Payload{11, 5},
                                    Payload{3, 6},
                                    Payload{7, 7},
                                    Payload{9, 8},
                                    Payload{8, 9},
                                    Payload{1, 10},
                                    Payload{4, 11}};
    ASSERT_EQ(buffer.size(), 0UL);

    // When
    for (const auto& d : data)
    {
        InsertSorted3<Payload>(buffer, d);
        std::cout << "Buffer " << d << ": ";
        for (const auto& value : buffer)
        {
            std::cout << value << ", ";
        }
        std::cout << std::endl;
    }

    // Then
    EXPECT_EQ(buffer.size(), data.size());
    EXPECT_THAT(buffer,
                ::testing::ElementsAre(Payload{1, 10},
                                       Payload{2, 4},
                                       Payload{3, 6},
                                       Payload{4, 11},
                                       Payload{5, 3},
                                       Payload{6, 2},
                                       Payload{7, 7},
                                       Payload{8, 9},
                                       Payload{9, 8},
                                       Payload{10, 1},
                                       Payload{11, 5}));
}
}  // namespace
}  // namespace problem_statement
