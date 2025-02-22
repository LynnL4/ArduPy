
removeDuplicateSubstring(${CMAKE_C_FLAGS} CMAKE_C_FLAGS)
removeDuplicateSubstring(${CMAKE_CXX_FLAGS} CMAKE_CXX_FLAGS)

message("SOURCE_FILES=${SOURCE_FILES}")
add_executable(${PROJECT_NAME} ${SOURCE_FILES}  ${CMAKE_CURRENT_LIST_DIR}/../MicroPython/py/qstr.c
                                                ${CMAKE_CURRENT_LIST_DIR}/../MicroPython/py/parse.c
                                                ${CMAKE_CURRENT_LIST_DIR}/../MicroPython/py/objmodule.c
                                                )

set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE C)


target_link_libraries(${PROJECT_NAME}
        --specs=nano.specs 
        --specs=nosys.specs 
        -mcpu=cortex-m0plus 
        -mthumb 
        -Wl,--cref 
        -Wl,--check-sections 
        -Wl,--gc-sections 
        -Wl,--unresolved-symbols=report-all 
        -Wl,--warn-common 
        -Wl,--warn-section-align
        -Wl,--start-group
        arm_cortexM0l_math m
        -Wl,--end-group
        )

IF(SUFFIX)
    SET_TARGET_PROPERTIES(${PROJECT_NAME} PROPERTIES SUFFIX ${SUFFIX})
ENDIF()

# Build target
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} -O binary  ${CMAKE_BINARY_DIR}/${PROJECT_NAME}${SUFFIX} ${CMAKE_BINARY_DIR}/${PROJECT_NAME}.bin
        DEPENDS ${PROJECT_NAME}
        COMMAND ${CMAKE_SIZE} -A  ${CMAKE_BINARY_DIR}/${PROJECT_NAME}${SUFFIX}
        COMMENT "Generating .bin file ...")

# show information
include(${CMAKE_CURRENT_LIST_DIR}/dump-config.cmake)
