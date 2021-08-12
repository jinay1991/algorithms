load("@rules_cc//cc:defs.bzl", "cc_test")

cc_test(
    name = "unit_tests",
    srcs = [
        # "astar_tests.cpp",
        # "breadth_first_search_tests.cpp",
        # "dijkstra_tests.cpp",
        "graph_tests.cpp",
    ],
    deps = [
        "//algorithms/graph",
        # "//algorithms/graph/test/support",
        "@googletest//:gtest_main",
    ],
)
