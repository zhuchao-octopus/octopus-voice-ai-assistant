#pragma once

#include <string>

class LanguageModel {
public:
    LanguageModel();
    ~LanguageModel();

    bool initialize();
    std::string generateResponse(const std::string& input);
};