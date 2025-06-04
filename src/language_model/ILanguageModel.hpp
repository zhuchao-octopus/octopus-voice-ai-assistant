#pragma once
#include <string>

class ILanguageModel {
public:
    virtual ~ILanguageModel() = default;

    // 输入用户问题，返回模型的回答
    virtual std::string generateResponse(const std::string& prompt) = 0;

    // 可选：设置上下文或参数（如温度、top_p）
    virtual void setContext(const std::string& context) {}
};
