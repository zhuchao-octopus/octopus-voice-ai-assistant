#pragma once

#include <string>

class AudioRecorder {
public:
    AudioRecorder();
    ~AudioRecorder();

    bool startRecording(const std::string& output_path);
    void stopRecording();

private:
    bool isRecording;
};