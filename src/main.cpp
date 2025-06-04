#include "speech_recognition/WhisperRecognizer.hpp"
#include "language_model/LanguageModelWrapper.hpp"
#include <iostream>

int main() {
    WhisperRecognizer recognizer;
   
    LanguageModelWrapper model(LanguageModelWrapper::Backend::ChatGPT, "YOUR_API_KEY");



    if (!recognizer.initialize("data/models/ggml-base.en.bin")) {
        std::cerr << "Failed to initialize Whisper Recognizer." << std::endl;
        return -1;
    }

    std::string result = recognizer.recognize("data/audio/output_festival.wav");
    std::cout << "Recognition Result: " << result << std::endl;

    return 0;
}
