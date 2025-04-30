#include "LanguageModel.hpp"
#include <iostream>

LanguageModel::LanguageModel() {}

LanguageModel::~LanguageModel() {}

bool LanguageModel::initialize() {
    std::cout << "Initialize Language Model (Llama.cpp)." << std::endl;
    return true;
}

std::string LanguageModel::generateResponse(const std::string& input) {
    return "Generated response to: " + input;
}