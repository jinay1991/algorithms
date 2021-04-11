load("@rules_cc//cc:defs.bzl", "cc_test")

cc_test(
    name = "unit_tests",
    srcs = ["tree_tests.cpp"],
    deps = [
        "//common/algorithm:tree",
        "@googletest//:gtest_main",
    ],
)
