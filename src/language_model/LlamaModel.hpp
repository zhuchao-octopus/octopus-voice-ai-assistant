#pragma once

#include "ILanguageModel.hpp"
#include <string>

struct llama_context;  // 前向声明 llama.cpp 的上下文结构体

class LlamaModel : public ILanguageModel {
public:
    LlamaModel();
    ~LlamaModel();

    // 初始化模型，例如加载模型文件
    bool initialize(const std::string& model_path);

    // 生成回复
    std::string generateResponse(const std::string& prompt) override;

private:
    llama_context* ctx;     // llama 模型上下文
    std::string session_id; // 可选：用于管理对话状态
};
