#include "LlamaModel.hpp"
#include <llama.h>  // 假设 llama.cpp 安装后在 include 路径中
#include <iostream>

LlamaModel::LlamaModel() : ctx(nullptr) {}

LlamaModel::~LlamaModel() {
    if (ctx) {
        llama_free(ctx);
    }
}

bool LlamaModel::initialize(const std::string& model_path) {
    // 设置模型参数，使用 llama_model_params 而不是 llama_context_params
    llama_model_params params = llama_model_default_params(); // 使用默认的模型参数
    
    // 加载模型，传递正确的参数类型
    struct llama_model* model = llama_model_load_from_file(model_path.c_str(), params);
    
    if (!model) {
        std::cerr << "[LlamaModel] Failed to load model from: " << model_path << std::endl;
        return false;
    }

    // 使用加载的模型初始化上下文
    llama_context_params ctx_params = llama_context_default_params(); // 这是上下文参数
    ctx = llama_init_from_model(model, ctx_params);
    
    if (!ctx) {
        std::cerr << "[LlamaModel] Failed to initialize context from model: " << model_path << std::endl;
        return false;
    }

    std::cout << "[LlamaModel] Model loaded and context initialized: " << model_path << std::endl;
    return true;
}

std::string LlamaModel::generateResponse(const std::string& prompt) {
    if (!ctx) {
        return "[LlamaModel] Model not initialized";
    }

    // 简化逻辑：单轮推理，未处理多轮上下文（你可以自行扩展）
    llama_token tokens[512];
    int n_tokens = llama_tokenize(ctx, prompt.c_str(), tokens, 512, true);

    llama_eval(ctx, tokens, n_tokens, 0, 4); // 假设 n_threads=4

    std::string output;
    for (int i = 0; i < 128; ++i) { // 最多生成 128 token
        llama_token tok = llama_sample_top_p(ctx, nullptr, 0.95f);
        if (tok == llama_token_eos()) break;

        const char* tok_str = llama_token_to_str(ctx, tok);
        output += tok_str;

        llama_eval(ctx, &tok, 1, n_tokens + i, 4);
    }

    return output;
}
