cmake_minimum_required(VERSION 3.15)
cmake_policy(SET CMP0135 NEW)
project(Vecteur_TP1_2)
# activation de la vérification des assertions
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D NDEBUG")

SET(CMAKE_C_FLAGS CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-elide-constructors")

include(FetchContent)
FetchContent_Declare(
        googletest
        # Specify the commit you depend on and update it regularly.
        # URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
        URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(Vecteur main.cpp vecteur.h memory.cxx)
add_executable(Vecteur_test vecteur.h  tests/test_common.hh tests/test_vecteur.cc memory.cxx)
target_link_libraries(Vecteur_test gtest_main)
target_compile_options(Vecteur PRIVATE -UNDEBUG)
target_compile_options(Vecteur_test PRIVATE -UNDEBUG)