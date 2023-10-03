cc_library(
    name = "opstack",
    srcs = ["opstack.c"],
)

cc_library(
    name = "op_producer",
    srcs = ["op_producer.c"],
    deps = [":opstack"],
)

cc_binary(
    name = "main",
    srcs = ["main.c"],
    deps = [
        ":op_producer", 
        ":opstack"
    ],
)