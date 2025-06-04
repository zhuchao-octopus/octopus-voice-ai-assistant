#ifndef LANGUAGE_MODEL_WRAPPER_HPP
#define LANGUAGE_MODEL_WRAPPER_HPP

#include "LlamaModel.hpp"  // 假设之前实现的 LLaMA 模型
#include "ChatGPTModel.hpp"

#include <string>
#include <memory>

class LanguageModelWrapper {
public:
    enum class Backend {
        LLaMA,
        ChatGPT
    };

    LanguageModelWrapper(Backend backend, const std::string& model_path_or_api_key);
    ~LanguageModelWrapper();

    bool initialize();
    std::string generate_response(const std::string& prompt);

private:
    Backend backend_;
    std::unique_ptr<LlamaModel> llama_model_;
    std::unique_ptr<ChatGPTModel> chatgpt_model_;
};

#endif // LANGUAGE_MODEL_WRAPPER_HPP
