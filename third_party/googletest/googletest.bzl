load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def googletest():
    if "googletest" not in native.existing_rules():
        http_archive(
            name = "googletest",
            url = "https://github.com/google/googletest/archive/refs/tags/v1.13.0.tar.gz",
            sha256 = "ad7fdba11ea011c1d925b3289cf4af2c66a352e18d4c7264392fead75e919363",
            strip_prefix = "googletest-1.13.0",
        )
