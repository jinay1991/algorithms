load("@algorithms//third_party/benchmark:benchmark.bzl", "benchmark")
load("@algorithms//third_party/glog:glog.bzl", "glog")
load("@algorithms//third_party/googletest:googletest.bzl", "googletest")
load("@algorithms//third_party/llvm_toolchain:llvm_toolchain.bzl", "llvm_toolchain")
load("@algorithms//third_party/nholthaus:nholthaus.bzl", "nholthaus")
load("@algorithms//third_party/sysroot:sysroot.bzl", "sysroot")

def algorithms_dependencies():
    """ Load 3rd party dependencies """
    benchmark()
    glog()
    googletest()
    llvm_toolchain()
    nholthaus()
    sysroot()
