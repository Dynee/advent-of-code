add_executable(day02 main.cpp)

file(COPY ${CMAKE_SOURCE_DIR}/2024/day02/day02-default-input.txt DESTINATION ${CMAKE_BINARY_DIR}/2024/day02/)
file(COPY ${CMAKE_SOURCE_DIR}/2024/day02/day02-input.txt DESTINATION ${CMAKE_BINARY_DIR}/2024/day02/)


target_link_options(day02 PRIVATE -stdlib=libstdc++)  # For Clang
