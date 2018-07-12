cmake_minimum_required(VERSION 3.5)

project(my_library)

############################################################
# Create a library
############################################################

#Generate the static library from the library sources
add_library(my_library STATIC 
    src/main.cpp
)

target_include_directories(my_library
    PUBLIC 
        ${PROJECT_SOURCE_DIR}/include
)


############################################################
# Create an executable
############################################################

# Add an executable with the above sources
add_executable(my_binary
    src/main.cpp
)

# link the new hello_library target with the hello_binary target
target_link_libraries( my_binary
    PRIVATE 
        my_library
)
