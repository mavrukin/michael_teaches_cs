cc_library(
    name = "convert",
    srcs = ["convert.c"]
)

cc_binary(
    name = "main",
    srcs = ["main.c"],
    deps = [
        ":convert",
        "//Chapter_4_Exercise_1:getline",
    ],
)
