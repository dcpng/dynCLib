include_directories("D:/dev-libs/utils/STC/src")

add_library(
    dynCLib MODULE
    common.c
)

add_executable(
    test
    test.c
)