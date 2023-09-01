cc_library(
    name = "getline",
    srcs = ["getline.c"],
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