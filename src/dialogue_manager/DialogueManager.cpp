#include "DialogueManager.hpp"

DialogueManager::DialogueManager() {}

DialogueManager::~DialogueManager() {}

std::string DialogueManager::processInput(const std::string& user_input) {
    return "Echo: " + user_input;
}