load("@rules_cc//cc:defs.bzl", "cc_test")

cc_test(
    name = "unit_tests",
    srcs = [
        "anagram_tests.cpp",
        "calculator_tests.cpp",
        "find_max_rides_tests.cpp",
        "find_right_sibling_tests.cpp",
    ],
    deps = [
        "//problem_statement",
        "@googletest//:gtest_main",
    ],
)
