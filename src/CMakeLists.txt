add_executable(check_laads_order
        report.ui
        check_laads_order.ui
        icons.qrc
        translations.qrc
        check_laads_order.cpp
        fast_cksum.cpp
        Order.cpp
        main.cpp)
# 如果是Release模式，就添加WIN32_EXECUTABLE属性，即隐藏终端窗口
set_property(TARGET check_laads_order PROPERTY WIN32_EXECUTABLE $<CONFIG:Release>)

target_link_libraries(check_laads_order PRIVATE Qt5::Widgets)

# 最高警告等级，并将警告视为错误，强制MSVC视源文件为utf8编码
if (MSVC)
    # target_compile_options(check_laads_order PRIVATE /W4 /WX /source-charset:utf-8)
    message(FATAL_ERROR "Serious errors will occur when using MSVC, please
    consider using msys2/MinGW")
else ()
    target_compile_options(check_laads_order PRIVATE -Wall -Wextra -Werror)
endif ()