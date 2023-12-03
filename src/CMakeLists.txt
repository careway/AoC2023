
FILE( GLOB DIRS LIST_DIRECTORIES TRUE ./day*)
message(${DIRS})

foreach(dir ${DIRS})
    add_subdirectory(${dir})
endforeach()