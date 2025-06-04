#include "WhisperRecognizer.hpp"
#include "whisper.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <filesystem>
#include <sndfile.h>  


WhisperRecognizer::WhisperRecognizer() : whisper_ctx(nullptr) {}

WhisperRecognizer::~WhisperRecognizer()
{
    if (whisper_ctx)
    {
        whisper_free(whisper_ctx);
        whisper_ctx = nullptr;
    }
}

bool WhisperRecognizer::initialize(const std::string &model_path)
{
    if (!std::filesystem::exists(model_path))
    {
        std::cerr << "[Whisper] Model file not found: " << model_path << std::endl;
        return false;
    }

    // 使用默认参数初始化
    whisper_context_params cparams = whisper_context_default_params();
    whisper_ctx = whisper_init_from_file_with_params(model_path.c_str(), cparams);

    if (!whisper_ctx)
    {
        std::cerr << "[Whisper] Failed to load model from: " << model_path << std::endl;
        return false;
    }

    std::cout << "[Whisper] Successfully loaded model: " << model_path << std::endl;
    return true;
}
std::string WhisperRecognizer::recognize(const std::string &audio_path)
{
    if (!whisper_ctx)
    {
        std::cerr << "[Whisper] Model is not initialized!" << std::endl;
        return "";
    }

    // 读取音频文件到 PCM 数据
    std::vector<float> pcmf32;  // 用来存储音频数据
    if (!read_audio_file(audio_path, pcmf32))
    {
        std::cerr << "[Whisper] Failed to read audio file: " << audio_path << std::endl;
        return "";
    }

    // 获取默认参数
    whisper_full_params params = whisper_full_default_params(WHISPER_SAMPLING_GREEDY);  // 默认参数

    // 可选择设置语言
    params.language = "en";  // 设置语言为英语

    // 执行音频识别
    if (whisper_full(whisper_ctx, params, pcmf32.data(), pcmf32.size()) != 0)
    {
        std::cerr << "[Whisper] Failed to process audio" << std::endl;
        return "";
    }

    // 获取识别到的段数
    int n_segments = whisper_full_n_segments(whisper_ctx);
    std::string result;

    // 提取识别结果的文本
    for (int i = 0; i < n_segments; ++i)
    {
        result += std::string(whisper_full_get_segment_text(whisper_ctx, i)) + " ";
    }

    return result;
}

// 示例：如何从文件读取音频数据到 pcmf32 数组
bool WhisperRecognizer::read_audio_file(const std::string &audio_path, std::vector<float> &pcm_data)
{
    if (!std::filesystem::exists(audio_path))
    {
        std::cerr << "[Whisper] Audio file not found: " << audio_path << std::endl;
        return false;
    }

    // 在此示例中，我们假设使用 libsndfile 读取音频数据
    SF_INFO sf_info;
    SNDFILE* file = sf_open(audio_path.c_str(), SFM_READ, &sf_info);
    if (!file)
    {
        std::cerr << "[Whisper] Failed to open audio file: " << audio_path << std::endl;
        return false;
    }

    // 读取音频数据到 pcm_data 数组
    pcm_data.resize(sf_info.frames * sf_info.channels);
    sf_readf_float(file, pcm_data.data(), sf_info.frames);
    sf_close(file);

    return true;
}