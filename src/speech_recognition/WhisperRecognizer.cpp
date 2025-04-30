#include "WhisperRecognizer.hpp"
#include "whisper.h"
#include <iostream>

WhisperRecognizer::WhisperRecognizer() : whisper_context(nullptr) {}

WhisperRecognizer::~WhisperRecognizer() {
    if (whisper_context) {
        whisper_free(whisper_context);  // 不需要 reinterpret_cast
    }
}

bool WhisperRecognizer::initialize() {
    whisper_context = whisper_init_from_file("data/models/ggml-base.en.bin");
    if (!whisper_context) {
        std::cerr << "Failed to load Whisper model." << std::endl;
        return false;
    }
    return true;
}

std::string WhisperRecognizer::recognize(const std::string& audio_path) {
    if (!whisper_context) {
        std::cerr << "Whisper model is not initialized." << std::endl;
        return "";
    }

    return "[Recognized text from " + audio_path + "]";
}
