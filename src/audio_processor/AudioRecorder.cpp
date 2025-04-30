#include "AudioRecorder.hpp"
#include <iostream>

AudioRecorder::AudioRecorder() : isRecording(false) {}

AudioRecorder::~AudioRecorder() {
    if (isRecording) {
        stopRecording();
    }
}

bool AudioRecorder::startRecording(const std::string& output_path) {
    std::cout << "Start recording to: " << output_path << std::endl;
    isRecording = true;
    return true;
}

void AudioRecorder::stopRecording() {
    if (isRecording) {
        std::cout << "Stop recording." << std::endl;
        isRecording = false;
    }
}