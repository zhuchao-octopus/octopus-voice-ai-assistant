#include "LanguageModelWrapper.hpp"
#include <iostream>

LanguageModelWrapper::LanguageModelWrapper(Backend backend, const std::string& model_path_or_api_key)
    : backend_(backend) {
    if (backend_ == Backend::LLaMA) {
        llama_model_ = std::make_unique<LlamaModel>(model_path_or_api_key);
    } else {
        chatgpt_model_ = std::make_unique<ChatGPTModel>(model_path_or_api_key);
    }
}

LanguageModelWrapper::~LanguageModelWrapper() {}

bool LanguageModelWrapper::initialize() {
    if (backend_ == Backend::LLaMA) {
        return llama_model_->initialize();
    } else {
        return chatgpt_model_->initialize();
    }
}

std::string LanguageModelWrapper::generate_response(const std::string& prompt) {
    if (backend_ == Backend::LLaMA) {
        return llama_model_->generate_response(prompt);
    } else {
        return chatgpt_model_->generate_response(prompt);
    }
}
