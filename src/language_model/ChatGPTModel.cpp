#include "ChatGPTModel.hpp"
#include <curl/curl.h>
//#include <nlohmann/json.hpp>  // 需要安装 nlohmann/json 库

//using json = nlohmann::json;

ChatGPTModel::ChatGPTModel(const std::string& api_key)
    : api_key_(api_key), model_("gpt-4"), curl_(nullptr) {}

ChatGPTModel::~ChatGPTModel() {
    if (curl_) {
        curl_easy_cleanup(curl_);
    }
}

bool ChatGPTModel::initialize() {
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl_ = curl_easy_init();
    if (!curl_) {
        std::cerr << "Curl initialization failed!" << std::endl;
        return false;
    }
    return true;
}

size_t ChatGPTModel::WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

std::string ChatGPTModel::generate_response(const std::string& prompt) {
    if (!curl_) {
        std::cerr << "Curl is not initialized!" << std::endl;
        return "";
    }

    ///json body = {
    ///    {"model", model_},
    ///    {"messages", {{"role", "user"}, {"content", prompt}}}
    ///};

    std::string read_buffer;
    struct curl_slist* headers = nullptr;
    headers = curl_slist_append(headers, ("Authorization: Bearer " + api_key_).c_str());
    headers = curl_slist_append(headers, "Content-Type: application/json");

    ///curl_easy_setopt(curl_, CURLOPT_URL, "https://api.openai.com/v1/chat/completions");
    ///curl_easy_setopt(curl_, CURLOPT_HTTPHEADER, headers);
    ///curl_easy_setopt(curl_, CURLOPT_POSTFIELDS, body.dump().c_str());
    ///curl_easy_setopt(curl_, CURLOPT_WRITEFUNCTION, WriteCallback);
    ///curl_easy_setopt(curl_, CURLOPT_WRITEDATA, &read_buffer);

    CURLcode res = curl_easy_perform(curl_);
    if (res != CURLE_OK) {
        std::cerr << "Curl request failed: " << curl_easy_strerror(res) << std::endl;
        return "";
    }

    ///json response = json::parse(read_buffer);
    return "";////response["choices"][0]["message"]["content"].get<std::string>();
}
