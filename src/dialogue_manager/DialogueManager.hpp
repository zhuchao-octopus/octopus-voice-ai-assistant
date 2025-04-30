#pragma once

#include <string>

class DialogueManager {
public:
    DialogueManager();
    ~DialogueManager();

    std::string processInput(const std::string& user_input);
};