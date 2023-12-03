project(Day2)
file(GLOB exec *.cpp)

MATH(EXPR VAR "0")
foreach(file ${exec})
    MATH(EXPR VAR "${VAR}+1")
    add_executable(${PROJECT_NAME}_${VAR} ${file})
endforeach()
