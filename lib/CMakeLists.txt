set(
    HEADER_FILES
    public/bitmanip/bitmanip.h
    public/dyn_prog/fibo.h
    public/memory/object_pool.h
    public/thread/threadpool.h
    )

set(
    IMPL_FILES
    impl/bitmanip/bitmanip.cc
    impl/dyn_prog/fibo.cc
    impl/memory/object_pool.cc
    impl/thread/threadpool.cc
    )
set(SOURCE_FILES ${HEADER_FILES} ${IMPL_FILES})

add_library(${CMAKE_PROJECT_NAME} STATIC ${SOURCE_FILES})
target_include_directories(
    ${CMAKE_PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/public
    )