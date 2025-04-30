#include "speech_recognition/WhisperRecognizer.hpp"
#include <iostream>

int main() {
    WhisperRecognizer recognizer;

    if (!recognizer.initialize()) {
        std::cerr << "Failed to initialize Whisper Recognizer." << std::endl;
        return -1;
    }

    std::string result = recognizer.recognize("data/audio/sample.wav");
    std::cout << "Recognition Result: " << result << std::endl;

    return 0;
}