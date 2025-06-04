#ifndef CHATGPT_MODEL_HPP
#define CHATGPT_MODEL_HPP

#include <string>
#include <iostream>
#include <vector>
#include <curl/curl.h>

class ChatGPTModel {
public:
    explicit ChatGPTModel(const std::string& api_key);
    ~ChatGPTModel();

    bool initialize();
    std::string generate_response(const std::string& prompt);

private:
    std::string api_key_;
    std::string model_;
    CURL* curl_;

    static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp);
};

#endif // CHATGPT_MODEL_HPP
