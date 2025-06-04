#ifndef WHISPER_RECOGNIZER_HPP
#define WHISPER_RECOGNIZER_HPP

#include <string>
#include <vector>
#include <whisper.h>  // ✅ 添加这行

class WhisperRecognizer {
public:
    WhisperRecognizer();
    ~WhisperRecognizer();

    bool initialize(const std::string &model_path);
    std::string recognize(const std::string& audio_path);
    bool read_audio_file(const std::string &audio_path, std::vector<float> &pcm_data);
private:
    whisper_context* whisper_ctx;  // 使用定义好的类型
};

#endif
