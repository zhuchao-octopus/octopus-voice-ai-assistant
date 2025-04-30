
cmake_policy(SET CMP0079 NEW)
# 添加 whisper.cpp 目录
add_subdirectory(whisper.cpp)

# 添加 speech_recognition 模块
add_subdirectory(speech_recognition)

# 确保 speech_recognition 模块可以找到 whisper 库的头文件
target_include_directories(speech_recognition PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/whisper.cpp/include  # 确保路径正确
    ${CMAKE_CURRENT_SOURCE_DIR}/whisper.cpp/ggml/include  # 确保路径正确
)

# 编译最终主程序
add_executable(octopus-ai-voice-assistant main.cpp)

# 查找 libwhisper.so 库
find_library(WHISPER_LIBRARY NAMES whisper libwhisper.so PATHS ${CMAKE_CURRENT_SOURCE_DIR}/whisper.cpp/build/src)

# 如果找到了，链接它
if(WHISPER_LIBRARY)
    target_link_libraries(speech_recognition ${WHISPER_LIBRARY})
else()
    message(FATAL_ERROR "Whisper library not found!")
endif()

# 查找并链接 ggml 库（如果需要）
find_library(GGML_BASE_LIBRARY NAMES ggml-base libggml-base.so PATHS ${CMAKE_CURRENT_SOURCE_DIR}/whisper.cpp/build/ggml/src)
find_library(GGML_CPU_LIBRARY NAMES ggml-cpu libggml-cpu.so PATHS ${CMAKE_CURRENT_SOURCE_DIR}/whisper.cpp/build/ggml/src)
find_library(GGML_LIBRARY NAMES ggml libggml.so PATHS ${CMAKE_CURRENT_SOURCE_DIR}/whisper.cpp/build/ggml/src)

# 如果找到了，链接它们
if(GGML_BASE_LIBRARY AND GGML_CPU_LIBRARY AND GGML_LIBRARY)
    target_link_libraries(speech_recognition
        ${GGML_BASE_LIBRARY}
        ${GGML_CPU_LIBRARY}
        ${GGML_LIBRARY}
    )
else()
    message(FATAL_ERROR "GGML libraries not found!")
endif()

# 链接模块
target_link_libraries(octopus-ai-voice-assistant
    speech_recognition
)
