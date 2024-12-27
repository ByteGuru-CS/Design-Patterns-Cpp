cmake_minimum_required(VERSION 3.15)
project(DesignPatterns)

set(srcs
    abstract-factory
    adapter
)

foreach(dir IN ITEMS ${srcs})
    file(GLOB files "${dir}/*.cpp")
    message(STATUS "Pattern `${dir}':")

    foreach(file IN ITEMS ${files})

        get_filename_component(file_name
                                ${file} NAME
        )

        set(project_name "${file_name}")
        message(STATUS "  ${dir}/${file_name} will be built")
        
        add_executable(${project_name} "${dir}/${file_name}")
    endforeach()
    
endforeach()