cmake_minimum_required(VERSION 3.10)

# Add the project name - this must come after cmake_minimum_required
project(game C)

# Set C standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Find required packages
find_package(PkgConfig REQUIRED)
pkg_check_modules(SDL2 REQUIRED sdl2 SDL2_image)

set(SOURCE_FOLDERS "." "rendering" "src")

set(C_FILES "")
foreach(folder ${SOURCE_FOLDERS})
    set(full_path ${CMAKE_SOURCE_DIR}/${folder})
    if(EXISTS ${full_path} AND IS_DIRECTORY ${full_path})
        file(GLOB folder_sources "${full_path}/*.cpp")
        list(APPEND C_FILES ${folder_sources})
    else()
        message(WARNING "Folder '${full_path}' does not exist")
    endif()
endforeach()

list(LENGTH C_FILES NUM_SOURCES)
if(NUM_SOURCES EQUAL 0)
    message(FATAL_ERROR "Error: No .cpp files found in the specified folders")
endif()

# Print the files being compiled
message("Compiling the following files:")
foreach(file ${C_FILES})
    message("  ${file}")
endforeach()

# Create the executable
add_executable(main ${C_FILES})

# Link libraries
target_link_libraries(main ${SDL2_LIBRARIES})

# Add include directories
target_include_directories(main PRIVATE ${SDL2_INCLUDE_DIRS})

# Add compiler flags
target_compile_options(main PRIVATE ${SDL2_CFLAGS_OTHER})