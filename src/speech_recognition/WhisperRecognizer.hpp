#pragma once

#include <string>
#include "whisper.h"  // 确保包含 whisper.h 头文件，以便能识别 whisper_context

class WhisperRecognizer {
public:
    WhisperRecognizer();
    ~WhisperRecognizer();

    bool initialize();
    std::string recognize(const std::string& audio_path);

private:
    struct whisper_context* whisper_context;  // 使用 struct whisper_context* 类型
};
