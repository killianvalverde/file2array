set(FILE2ARRAY_SOURCE_FILES
        exception.hpp
        program.cpp
        program.hpp
        program_args.hpp
)

add_library(file2array STATIC ${FILE2ARRAY_SOURCE_FILES})

set(suffix "$<IF:$<CONFIG:Debug>,d,>")
target_link_libraries(file2array speed${suffix})
