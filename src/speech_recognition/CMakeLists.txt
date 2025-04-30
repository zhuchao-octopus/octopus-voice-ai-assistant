# 编译 speech_recognition 模块
add_library(speech_recognition
    WhisperRecognizer.cpp
)

target_include_directories(speech_recognition PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}  # 当前模块路径
)

# 使用相对路径指定库文件所在的目录
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/../build/src)  # 假设构建目录在上级目录的 build 文件夹中

# 依赖 whisper 库和 ggml 库
target_link_libraries(speech_recognition
    ${CMAKE_CURRENT_SOURCE_DIR}/../build/src/libwhisper.so
    ${CMAKE_CURRENT_SOURCE_DIR}/../build/src/libggml.so  # 如果 whisper 库依赖 libggml
)
