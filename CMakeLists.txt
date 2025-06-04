# Specify the minimum required version of CMake to build the project
cmake_minimum_required(VERSION 3.15)

# Set the C++ standard to C++17 for the entire project
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Declare the name of the project
project(octopus-ai-voice-assistant)

# Set CMake policy to properly handle linking of targets defined in subdirectories
cmake_policy(SET CMP0079 NEW)

# ========================== External Dependencies ==========================

# Add the Whisper speech recognition engine as a subdirectory.
# This should contain its own CMakeLists.txt file to define a library target named "whisper".
# The path should point to the root of the whisper.cpp source code.
add_subdirectory(src/external/whisper.cpp)

# Add the LLaMA language model engine as a subdirectory.
# This should also contain a CMakeLists.txt that defines a target called "llama".
# This will enable integration of llama.cpp (supporting GGUF models) into our project.
add_subdirectory(src/external/llama.cpp)

# ========================== Internal Modules ===============================

# Add the speech recognition module directory.
# This should define a target named "speech_recognition" used for recognizing spoken audio using Whisper.
add_subdirectory(src/speech_recognition)

# Add the language model module directory.
# This will include a target "language_model" responsible for handling local or remote language models (e.g., LLaMA, ChatGPT).
add_subdirectory(src/language_model)

# Add the dialogue manager module directory.
# This should define a target called "dialogue_manager" that handles conversational state and context.
add_subdirectory(src/dialogue_manager)

# ========================== Main Application ===============================

# Define the main application target as an executable.
# This will be built from the main entry file located at src/main.cpp.
add_executable(octopus-ai-voice-assistant
    src/main.cpp
)

# ========================== Link Dependencies ==============================

# Link the whisper and sndfile libraries to the speech_recognition module.
# "whisper" is required for running Whisper inference.
# "sndfile" is used for loading audio files (e.g., WAV format).
target_link_libraries(speech_recognition
    whisper     # Target from whisper.cpp
    sndfile     # External audio decoding library (libsndfile)
)

# Link the LLaMA language model engine to the language_model module.
# This allows the language_model component to use llama.cpp GGUF model inference.
target_link_libraries(language_model
    llama       # Target from llama.cpp
)

# Link all internal modules (speech_recognition, language_model, dialogue_manager)
# into the main executable to assemble the complete voice assistant pipeline.
target_link_libraries(octopus-ai-voice-assistant
    speech_recognition   # Handles speech-to-text using Whisper
    language_model       # Handles natural language inference using LLaMA or ChatGPT
    dialogue_manager     # Manages context and intent for conversations
)
