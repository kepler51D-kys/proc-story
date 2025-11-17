cmake_minimum_required(VERSION 3.10)

project(game CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(PkgConfig REQUIRED)
pkg_check_modules(SDL2 REQUIRED sdl2 SDL2_image)

set(SOURCE_FOLDERS "." "rendering" "src")

set(CXX_FILES "")
foreach(folder ${SOURCE_FOLDERS})
    set(full_path ${CMAKE_SOURCE_DIR}/${folder})
    if(EXISTS ${full_path} AND IS_DIRECTORY ${full_path})
        message(AHHHHHHHHHHHHHHHHHHHHHHHHHHHH)
        file(GLOB folder_sources "${full_path}/*.cpp")
        list(APPEND CXX_FILES ${folder_sources})
    else()
        message(WARNING "Folder '${full_path}' does not exist")
    endif()
endforeach()

list(LENGTH CXX_FILES NUM_SOURCES)
if(NUM_SOURCES EQUAL 0)
    message(FATAL_ERROR "Error: No .cpp files found in the specified folders")
endif()

message("Compiling the following files:")
foreach(file ${CXX_FILES})
    message("  ${file}")
endforeach()

# Create the executable
add_executable(main ${CXX_FILES})

# Link libraries
target_link_libraries(main ${SDL2_LIBRARIES})

# Add include directories
target_include_directories(main PRIVATE ${SDL2_INCLUDE_DIRS})

# Add compiler flags
target_compile_options(main PRIVATE ${SDL2_CFLAGS_OTHER})