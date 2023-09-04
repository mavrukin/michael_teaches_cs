cc_library(
    name = "getline",
    srcs = ["getline.c"],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "strindex",
    srcs = ["strindex.c"],
)

cc_binary(
    name = "main",
    srcs = ["main.c"],
    deps = [
        ":getline",
        ":strindex",
    ],
)
